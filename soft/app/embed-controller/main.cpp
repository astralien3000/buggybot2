#include <QtSerialPort/QtSerialPort>
#include <QtCore/QCoreApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <cereal/types/vector.hpp>

#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

#include <messages/servo_action.hpp>

#include "port_client.hpp"

using namespace std;

using PortList = QList<QSerialPortInfo>;
using Port = QSerialPortInfo;

ostream& operator<<(ostream& out, QString&& str) {
  return out << str.toStdString();
}

ostream& operator<<(ostream& out, QString& str) {
  return out << str.toStdString();
}

void config_sock(zmq::socket_t& sock) {
  int hwm = 1;
  int linger = 0;
  sock.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_LINGER, &linger, sizeof(linger));
}

template<typename Payload, typename Func>
void (*handler_binder(Func func))(const void*) {
  static Func ret = func;
  return [](const void* msg) {
      ret(((Protocol::Pack<Protocol::Message, Payload>*)msg)->message.payload);
    };
}

PortClient::PortClient(QSerialPort& port)
  : _port(port) {

  QObject::connect(&port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
  QObject::connect(&port, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(onError()));
  QObject::connect(&_watchdog, SIGNAL(timeout()), this, SLOT(onTimeout()));

  _watchdog.setInterval(1000);
  _watchdog.start();

  _monitor.setInterval(1);
  _monitor.start();

  QObject::connect(&_monitor, SIGNAL(timeout()), this, SLOT(onMonitor()));

  parser.addHandler(Protocol::DefaultHandler<Protocol::Message, Actuator::ServoPosition>(
                      handler_binder<Actuator::ServoPosition>([this](Actuator::ServoPosition& a) { this->onServoAngle(a); })
                    ));

  in.bind("ipc://embed.in");
  out.bind("ipc://embed.out");
  out.setsockopt(ZMQ_SUBSCRIBE, 0, 0);

  config_sock(out);
  config_sock(in);

}

PortClient::~PortClient() {
}

void PortClient::onTimeout(void) {
  _watchdog.stop();
  _sync = false;

  cout << "Timeout" << endl;
  bool old = _port.isDataTerminalReady();
  _port.setDataTerminalReady(!old);

  _watchdog.start(1000);
}

void PortClient::onError(void) {
  //throw "QSerialPort error";
  QCoreApplication::exit(5);
}

void PortClient::onMonitor(void) {
  zmq::message_t msg;
  out.recv(&msg, ZMQ_NOBLOCK);
  if(_sync) {
      if(msg.size()) {
          std::stringstream ss;
          ss.write((char*)msg.data(), msg.size());

          vector<HardwareServoAction> hsas;

          {
            cereal::BinaryInputArchive ar(ss);
            ar(hsas);
          }

          for(auto it = hsas.begin() ; it != hsas.end() ; it++) {
              HardwareServoAction& hsa = *it;

              if(0 <= hsa.position && hsa.position <= 1024) {
                  {
                    Protocol::Pack<Protocol::Message, Actuator::ServoPosition> pak;
                    pak.message.payload.id = hsa.id;
                    pak.message.payload.enabled = hsa.enable;
                    pak.message.payload.position = hsa.position;
                    u8* data = Protocol::pack(pak);
                    _port.write((char*)data, sizeof(pak));
                  }
                }
              else {
                  cout << "Invalid servo_" << (u16)hsa.id << " command ->" << hsa.position << endl;
                }
            }
        }
    }
}


void PortClient::onServoAngle(Actuator::ServoPosition& payload) {
  std::stringstream ss;
  _watchdog.start(500);
  _sync = true;

  HardwareServoAction hsa;
  hsa.id = payload.id;
  hsa.position = payload.position;
  hsa.enable = payload.enabled;

  {
    cereal::BinaryOutputArchive ar(ss);
    ar(hsa);
  }

  zmq::message_t msg(ss.str().size());
  ss.str().copy((char*)msg.data(), msg.size());

  in.send(msg, ZMQ_NOBLOCK);
}

void PortClient::onReadyRead(void) {
  char buff;
  //  _watchdog.start(500);
  //  _sync = true;

  while(_port.bytesAvailable()) {
      _port.getChar(&buff);
      parser.parse((u8*)&buff, 1);
    }
}

int main(int argc, char* argv[]) {
  int ret = 0;

  while(1) {
      bool show = true;

      try {
        PortList ports = QSerialPortInfo::availablePorts();
        Port selected;

        if(ports.size() == 0) {
            if(ret == 1) show = false;
            else ret = 1;
            throw "No port detected";
          }

        for(PortList::Iterator it = ports.begin() ; it != ports.end() ; it++) {
            if((*it).manufacturer().contains("Arduino")) {
                selected = *it;
              }
          }

        if(!selected.isValid()) {
            if(ret == 2) show = false;
            else ret = 2;
            throw "No valid port found";
          }

        if(selected.isBusy()) {
            if(ret == 3) show = false;
            else ret = 3;
            throw "Port is busy";
          }

        QCoreApplication app(argc, argv);
        QSerialPort port(selected);

        port.setBaudRate(QSerialPort::Baud57600);
        port.setFlowControl(QSerialPort::NoFlowControl);
        port.setParity(QSerialPort::NoParity);
        port.setStopBits(QSerialPort::OneStop);
        port.setDataBits(QSerialPort::Data8);

        if(!port.open(QIODevice::ReadWrite)) {
            if(ret == 4) show = false;
            else ret = 4;
            throw "Can't open port";
          }

        /*
        cout << "----------------------------------------------------------------" << endl;
        cout << "Port Name : " << selected.portName() << endl;
        cout << "Description : " << selected.description() << endl;
        cout << "Serial Number : " << selected.serialNumber() << endl;
        cout << "Manufacturer : " << selected.manufacturer() << endl;
        cout << "System Location : " << selected.systemLocation() << endl;
        if(selected.hasProductIdentifier())
          cout << "Product Id : " << selected.productIdentifier() << endl;
        if(selected.hasVendorIdentifier())
          cout << "Vendor Id : " << selected.vendorIdentifier() << endl;
        cout << "----------------------------------------------------------------" << endl;
        */

        PortClient client(port);

        ret = app.exec();
        throw "Connection lost";
      }
      catch(const char* e) {
        if(show) {
            cout << "ERROR : " << e << endl;
          }
      }

    }

  return ret;
}

