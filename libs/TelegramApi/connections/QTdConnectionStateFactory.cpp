#include "QTdConnectionStateFactory.hpp"

QTdConnectionState *QTdConnectionStateFactory::create(const QJsonObject &json,
                                                      QObject *parent) {
  const auto state = json["state"];
  const auto type = json["@type"].toString();
  if (type == "connectionStateReady") {
    return new QTdConnectionStateReady(parent);
  } else if (type == "connectionStateUpdating") {
    return new QTdConnectionStateUpdating(parent);
  } else if (type == "connectionStateConnecting") {
    return new QTdConnectionStateConnecting(parent);
  } else if (type == "connectionStateConnectingToProxy") {
    return new QTdConnectionStateConnectingToProxy(parent);
  } else if (type == "connectionStateWaitingForNetwork") {
    return new QTdConnectionStateWaitingForNetwork(parent);
  }
  return nullptr;
}
