#include "QAbstractInt32Id.hpp"

QAbstractInt32Id::QAbstractInt32Id(QObject *parent) : QTdObject(parent) {}

qint32 QAbstractInt32Id::id() const noexcept { return mId.value(); }

QString QAbstractInt32Id::qmlId() const { return mId.toQmlValue(); }

QJsonValue QAbstractInt32Id::jsonId() const { return mId.toJsonValue(); }

QAbstractInt32Id *QAbstractInt32Id::create(const QJsonObject &json,
                                           QObject *parent) {
  auto object = new QAbstractInt32Id(parent);
  object->unmarshallJson(json);
  return object;
}

void QAbstractInt32Id::unmarshallJson(const QJsonObject &json) {
  if (json.contains("id")) {
    mId = json["id"];
  }
  QTdObject::unmarshallJson(json);
}
