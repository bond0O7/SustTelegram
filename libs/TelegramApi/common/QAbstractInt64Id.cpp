#include "QAbstractInt64Id.hpp"

QAbstractInt64Id::QAbstractInt64Id(QObject *parent) : QTdObject(parent) {}

QString QAbstractInt64Id::qmlId() const { return mId.toQmlValue(); }

QJsonValue QAbstractInt64Id::jsonId() const { return mId.toJsonValue(); }

qint64 QAbstractInt64Id::id() const noexcept { return mId.value(); }

QAbstractInt64Id *QAbstractInt64Id::create(const QJsonObject &json,
                                           QObject *parent) {
  auto object = new QAbstractInt64Id(parent);
  object->unmarshallJson(json);
  return object;
}

void QAbstractInt64Id::unmarshallJson(const QJsonObject &json) {
  if (json.contains("id")) {
    mId = json["id"];
  }
  QTdObject::unmarshallJson(json);
}
