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

  zmq::context_t ctx {1};

  struct SockPair {
    zmq::socket_t pub;
    zmq::socket_t sub;

    SockPair(zmq::context_t& ctx)
      : pub(ctx, ZMQ_PUB),
        sub(ctx, ZMQ_SUB) {
    }
  };

  std::map<u8, SockPair*> _sock;

public:
  PortClient(QSerialPort& port);
  ~PortClient();

public:
  void onServoAngle(Actuator::ServoAngle& payload);

public slots:
  void onReadyRead(void);
  void onTimeout(void);
  void onMonitor(void);
};

#endif//PORT_CLIENT_HPP
