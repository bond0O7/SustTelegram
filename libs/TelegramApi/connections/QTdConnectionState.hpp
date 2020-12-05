#ifndef QTDCONNECTIONSTATE_HPP
#define QTDCONNECTIONSTATE_HPP
#include "../common/QAbstractTdObject.hpp"

class QTdConnectionState : public QTdObject {
  Q_OBJECT
public:
  explicit QTdConnectionState(QObject *parent = nullptr);
};

class QTdConnectionStateWaitingForNetwork : public QTdConnectionState {
  Q_OBJECT
public:
  explicit QTdConnectionStateWaitingForNetwork(QObject *parent = nullptr);
};

class QTdConnectionStateConnectingToProxy : public QTdConnectionState {
  Q_OBJECT
public:
  explicit QTdConnectionStateConnectingToProxy(QObject *parent = nullptr);
};
class QTdConnectionStateConnecting : public QTdConnectionState {
  Q_OBJECT
public:
  explicit QTdConnectionStateConnecting(QObject *parent = nullptr);
};

class QTdConnectionStateUpdating : public QTdConnectionState {
  Q_OBJECT
public:
  explicit QTdConnectionStateUpdating(QObject *parent = nullptr);
};

class QTdConnectionStateReady : public QTdConnectionState {
  Q_OBJECT
public:
  explicit QTdConnectionStateReady(QObject *parent = nullptr);
};

#endif // QTDCONNECTIONSTATE_HPP
