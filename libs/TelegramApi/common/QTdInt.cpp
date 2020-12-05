#include "QTdInt.hpp"

QJsonValue QTdInt32::toJsonValue() const {
  return QJsonValue(static_cast<int>(mValue));
}

QString QTdInt32::toQmlValue() const { return QString::number(mValue); }

QJsonValue QTdInt53::toJsonValue() const {
  return QJsonValue(static_cast<double>(mValue));
}

QString QTdInt53::toQmlValue() const { return QString::number(mValue); }

QJsonValue QTdInt64::toJsonValue() const {
  return QJsonValue(QString::number(mValue));
}

QString QTdInt64::toQmlValue() const { return QString::number(mValue); }
