#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>

#include "port_client.hpp"

using namespace std;

using PortList = QList<QSerialPortInfo>;
using Port = QSerialPortInfo;

ostream& operator<<(ostream& out, QString&& str) {
  return out << str.toStdString();
}

void PortClient::onReadyRead(void) {
  char buff;
  _port.getChar(&buff);
  _port.putChar(buff+1);
  cout.put(buff);
  cout.flush();
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

