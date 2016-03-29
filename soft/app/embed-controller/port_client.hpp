#ifndef PORT_CLIENT_HPP
#define PORT_CLIENT_HPP

#include <QtSerialPort/QSerialPort>
#include <QObject>

class PortClient : public QObject {
  Q_OBJECT

  QSerialPort& _port;

public:
  PortClient(QSerialPort& port)
    : _port(port) {

    QObject::connect(&port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

  }

public slots:
    void onReadyRead(void);
};

#endif//PORT_CLIENT_HPP
