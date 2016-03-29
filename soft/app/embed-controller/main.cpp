#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

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

Protocol::Parser<1, 128> parser;

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

  parser.addHandler(Protocol::DefaultHandler<Protocol::Message, Actuator::ServoAngle>(
                      handler_binder<Actuator::ServoAngle>([this](Actuator::ServoAngle& a) { this->onServoAngle(a); })
          ));

}

void PortClient::onServoAngle(Actuator::ServoAngle& payload) {
  cout << "Angle(" << (int)payload.id << ") : " << payload.angle << endl;

  if(payload.angle > 2 || payload.angle < 0) {
      cout << "RAZ" << endl;
      Protocol::Pack<Protocol::Message, Actuator::ServoAngle> pak;
      pak.message.payload.angle = 0;
      u8* data = Protocol::pack(pak);
      _port.write((char*)data, sizeof(pak));
    }
}

void PortClient::onReadyRead(void) {
  char buff;

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

  parser.addHandler(Protocol::DefaultHandler<Protocol::Message, Actuator::ServoAngle>([](const void* msg){
      auto pak = (Protocol::Pack<Protocol::Message, Actuator::ServoAngle>*)msg;

      cout << "Angle(" << pak->message.payload.id << ") : " << pak->message.payload.angle << endl;

    }));

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

