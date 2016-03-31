#ifndef PORT_CLIENT_HPP
#define PORT_CLIENT_HPP

#include <QtSerialPort/QSerialPort>
#include <QObject>
#include <QTimer>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>


class PortClient : public QObject {
  Q_OBJECT

  QSerialPort& _port;
  Protocol::Parser<1, 128> parser;
  QTimer _watchdog;

public:
  PortClient(QSerialPort& port);

public:
  void onServoAngle(Actuator::ServoAngle& payload);

public slots:
  void onReadyRead(void);
  void onTimeout();
};

#endif//PORT_CLIENT_HPP
