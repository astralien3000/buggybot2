#include <QtSerialPort/QtSerialPort>
#include <QtCore/QCoreApplication>
#include <QString>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>

#include <cereal/types/vector.hpp>

#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

#include <messages/optoforce_data.hpp>

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

PortClient::PortClient(QSerialPort& port)
  : _port(port),
    _parser([this](const u8* msg, u16 s) { this->onMessage((const uint8_t*)msg, s); }) {
  QObject::connect(&port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
  QObject::connect(&port, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(onError()));

  in.bind("ipc://optoforce.in");
  config_sock(in);
}

PortClient::~PortClient() {
}

s16 get_s16(const uint8_t* msg, uint16_t pos) {
  return msg[pos] * 256 + msg[pos+1];
}

template<typename T>
void send(zmq::socket_t& sock_pub, T& sa) {
  stringstream oss;

  {
    cereal::BinaryOutputArchive ar(oss);
    ar(sa);
  }

  zmq::message_t msg(oss.str().size());
  oss.str().copy((char*)msg.data(), msg.size());

  sock_pub.send(msg, ZMQ_NOBLOCK);
}

void PortClient::onMessage(const uint8_t* msg, uint16_t size) {
  /*
  for(u16 i = 0 ; i < size ; i++) {
      cout << setfill('0') << setw(2) << hex << (u16)msg[i] << " ";
    }
  cout << endl;
  */

  vector<OptoforceData> ods;
  OptoforceData od;

  od.label = "sensor_1";
  od.x = get_s16(msg, 8);
  od.y = get_s16(msg, 10);
  od.z = get_s16(msg, 12);
  ods.push_back(od);

  od.label = "sensor_2";
  od.x = get_s16(msg, 14);
  od.y = get_s16(msg, 16);
  od.z = get_s16(msg, 18);
  ods.push_back(od);

  od.label = "sensor_3";
  od.x = get_s16(msg, 20);
  od.y = get_s16(msg, 22);
  od.z = get_s16(msg, 24);
  ods.push_back(od);

  od.label = "sensor_4";
  od.x = get_s16(msg, 26);
  od.y = get_s16(msg, 28);
  od.z = get_s16(msg, 30);
  ods.push_back(od);

  send(in, ods);
}

void PortClient::onError(void) {
  QCoreApplication::exit(5);
}

void PortClient::onReadyRead(void) {
  while(_port.bytesAvailable()) {
      char buff;
      _port.getChar(&buff);
      _parser.parse(buff);
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
            if((*it).manufacturer().contains("OptoForce")) {
                selected = *it;
              }
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

