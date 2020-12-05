#include "QTdConnectionState.hpp"

QTdConnectionState::QTdConnectionState(QObject *parent) : QTdObject(parent) {}

QTdConnectionStateWaitingForNetwork::QTdConnectionStateWaitingForNetwork(
    QObject *parent)
    : QTdConnectionState(parent) {
  setType(Type::ConnectionStateWaitForNetwork);
}

QTdConnectionStateConnectingToProxy::QTdConnectionStateConnectingToProxy(
    QObject *parent)
    : QTdConnectionState(parent) {
  setType(Type::ConnectionStateToProxy);
}

QTdConnectionStateConnecting::QTdConnectionStateConnecting(QObject *parent)
    : QTdConnectionState(parent) {
  setType(Type::ConnectionStateConnecting);
}

QTdConnectionStateUpdating::QTdConnectionStateUpdating(QObject *parent)
    : QTdConnectionState(parent) {
  setType(Type::ConnectionStateUpdating);
}

QTdConnectionStateReady::QTdConnectionStateReady(QObject *parent)
    : QTdConnectionState(parent) {
  setType(Type::ConnectionStateReady);
}
