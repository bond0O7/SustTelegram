#include "QAbstractInt53Id.hpp"

QAbstract53Id::QAbstract53Id(QObject *parent) : QTdObject(parent) {}

qint64 QAbstract53Id::id() const noexcept { return mId.value(); }

QString QAbstract53Id::qmlId() const { return mId.toQmlValue(); }

QJsonValue QAbstract53Id::jsonId() const { return mId.toJsonValue(); }

QAbstract53Id *QAbstract53Id::create(const QJsonObject &json, QObject *parent) {
  auto object = new QAbstract53Id(parent);
  object->unmarshallJson(json);
  return object;
}

void QAbstract53Id::unmarshallJson(const QJsonObject &json) {
  if (json.contains("id")) {
    mId = json["id"];
  }
  QTdObject::unmarshallJson(json);
}
