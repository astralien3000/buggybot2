#ifndef PORT_CLIENT_HPP
#define PORT_CLIENT_HPP

#include <map>

#include <QtSerialPort/QSerialPort>
#include <QObject>
#include <QTimer>

#include <zmq.hpp>

#include "parser.hpp"

class PortClient : public QObject {
  Q_OBJECT

private:
  QSerialPort& _port;
  Parser _parser;

  zmq::context_t ctx {1};

  zmq::socket_t in {ctx, ZMQ_PUB};

public:
  PortClient(QSerialPort& port);
  ~PortClient();

public:
  void onMessage(const uint8_t* msg, uint16_t size);

public slots:
  void onReadyRead(void);
  void onError(void);
};

#endif//PORT_CLIENT_HPP
