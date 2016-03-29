#ifndef PORT_CLIENT_HPP
#define PORT_CLIENT_HPP

#include <QtSerialPort/QSerialPort>
#include <QObject>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>


class PortClient : public QObject {
  Q_OBJECT

  QSerialPort& _port;
  Protocol::Parser<1, 128> parser;

public:
  PortClient(QSerialPort& port);

public:
  void onServoAngle(Actuator::ServoAngle& payload);

public slots:
    void onReadyRead(void);
};

#endif//PORT_CLIENT_HPP
