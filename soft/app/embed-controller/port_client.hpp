#ifndef PORT_CLIENT_HPP
#define PORT_CLIENT_HPP

#include <map>

#include <QtSerialPort/QSerialPort>
#include <QObject>
#include <QTimer>

#include <zmq.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

class PortClient : public QObject {
  Q_OBJECT

private:
  QSerialPort& _port;
  Protocol::Parser<1, 128> parser;
  QTimer _watchdog;
  QTimer _monitor;
  bool _sync = false;

  zmq::context_t ctx {1};

  zmq::socket_t in {ctx, ZMQ_PUB};
  zmq::socket_t out{ctx, ZMQ_SUB};

public:
  PortClient(QSerialPort& port);
  ~PortClient();

public:
  void onServoAngle(Actuator::ServoPosition& payload);

public slots:
  void onReadyRead(void);
  void onTimeout(void);
  void onMonitor(void);
  void onError(void);
};

#endif//PORT_CLIENT_HPP
