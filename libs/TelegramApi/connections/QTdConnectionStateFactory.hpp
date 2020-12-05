#ifndef QTDCONNECTIONSTATEFACTORY_HPP
#define QTDCONNECTIONSTATEFACTORY_HPP
#include "QTdConnectionState.hpp"

#include <QJsonObject>
#include <QObject>

class QTdConnectionStateFactory {
  static QTdConnectionState *create(const QJsonObject &json, QObject *parent);
};

#endif // QTDCONNECTIONSTATEFACTORY_HPP
