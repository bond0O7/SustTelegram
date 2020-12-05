#include "QAbstractTdObject.hpp"

QTdObject::QTdObject(QObject *parent) : QObject(parent), mType(Type::Unknown) {}

QTdObject::Type QTdObject::type() const noexcept { return mType; }

QString QTdObject::typeString() const { return mTypeString; }

void QTdObject::unmarshallJson(const QJsonObject &json) {
  mTypeString = json["@type"].toString();
}

QJsonObject QTdObject::marshallJson() { return QJsonObject(); }

void QTdObject::setType(const QTdObject::Type type) {
  mType = type;
  emit typeChanged(type);
}
