#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <cereal/archives/json.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

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
  //QObject::connect(&port, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(onError()));
  QObject::connect(&_watchdog, SIGNAL(timeout()), this, SLOT(onTimeout()));

  _watchdog.setInterval(10);
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

void PortClient::onMonitor(void) {
  if(_sync) {
      zmq::message_t msg;
      out.recv(&msg, ZMQ_NOBLOCK);
      if(msg.size()) {
          std::stringstream ss;
          ss.write((char*)msg.data(), msg.size());
          cereal::JSONInputArchive ar(ss);

          string topic;
          ar(topic);

          if(topic == string("pos")) {
              u8 id;
              bool enabled;
              u16 pos;
              ar(id, pos, enabled);
              cout << (uint16_t)id << "::" << pos << "::" << enabled << endl;

              if(0 <= pos && pos <= 1024) {
                  {
                    Protocol::Pack<Protocol::Message, Actuator::ServoPosition> pak;
                    pak.message.payload.id = id;
                    pak.message.payload.enabled = enabled;
                    pak.message.payload.position = pos;
                    u8* data = Protocol::pack(pak);
                    _port.write((char*)data, sizeof(pak));
                  }
                }
              else {
                  cout << "Invalid servo_" << (u16)id << " command ->" << pos << endl;
                }
            }
        }
    }
}


void PortClient::onServoAngle(Actuator::ServoPosition& payload) {
  std::stringstream ss;

  {
    cereal::JSONOutputArchive ar(ss);
    ar(string("pos"), (uint8_t)payload.id, (uint16_t)payload.position, (bool)payload.enabled);
  }

  zmq::message_t msg(ss.str().size());
  ss.str().copy((char*)msg.data(), msg.size());

  in.send(msg);
}

void PortClient::onReadyRead(void) {
  char buff;
  _watchdog.start(10);
  _sync = true;

  while(_port.bytesAvailable()) {
      _port.getChar(&buff);
      parser.parse((u8*)&buff, 1);
    }
}

int main(int argc, char* argv[]) {
  PortList ports = QSerialPortInfo::availablePorts();
  Port selected;

  if(ports.size() == 0) {
      cout << "No port detected" << endl;
      exit(1);
    }

  for(PortList::Iterator it = ports.begin() ; it != ports.end() ; it++) {
      if((*it).manufacturer().contains("Arduino")) {
          selected = *it;
        }
    }

  if(!selected.isValid()) {
      cout << "No valid port found" << endl;
      exit(2);
    }

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

  if(selected.isBusy()) {
      cout << "Port is busy" << endl;
      exit(3);
    }

  QApplication app(argc, argv);
  QSerialPort port(selected);

  port.setBaudRate(QSerialPort::Baud38400);
  port.setFlowControl(QSerialPort::NoFlowControl);
  port.setParity(QSerialPort::NoParity);
  port.setStopBits(QSerialPort::OneStop);
  port.setDataBits(QSerialPort::Data8);

  if(!port.open(QIODevice::ReadWrite)) {
      cout << "Can't open port" << endl;
      exit(4);
    }

  PortClient client(port);

  return app.exec();
}

