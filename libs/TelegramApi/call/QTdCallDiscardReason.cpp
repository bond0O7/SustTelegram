#include "QTdCallDiscardReason.hpp"

QTdCallDiscardReason::QTdCallDiscardReason(QObject *parent)
    : QTdObject(parent) {
  setType(Type::CallDiscardReason);
}

QTdCallDiscardReasonEmpty::QTdCallDiscardReasonEmpty(QObject *parent)
    : QTdCallDiscardReason(parent) {
  setType(Type::CallDiscardReasonEmpty);
}

QTdCallDiscardReasonMissed::QTdCallDiscardReasonMissed(QObject *parent)
    : QTdCallDiscardReason(parent) {
  setType(Type::CallDiscardReasonMissed);
}

QJsonObject QTdCallDiscardReasonMissed::marshallJson() {
  return QJsonObject{{"@type", "callDiscardReasonMissed"}};
}

QTdCallDiscardReasonDeclined::QTdCallDiscardReasonDeclined(QObject *parent)
    : QTdCallDiscardReason(parent) {
  setType(Type::CallDiscardReasonDeclined);
}

QJsonObject QTdCallDiscardReasonDeclined::marshallJson() {

  return QJsonObject{{"@type", "callDiscardReasonDeclined"}};
}

QTdCallDiscardReasonDisconnected::QTdCallDiscardReasonDisconnected(
    QObject *parent)
    : QTdCallDiscardReason(parent) {
  setType(Type::CallDiscardReasonDisconnected);
}

QJsonObject QTdCallDiscardReasonDisconnected::marshallJson() {
  return QJsonObject{{"@type", "callDiscardReasonDisconnected"}};
}

QTdCallDiscardReasonHangUp::QTdCallDiscardReasonHangUp(QObject *parent)
    : QTdCallDiscardReason(parent) {
  setType(Type::CallDiscardReasonHangUp);
}

QJsonObject QTdCallDiscardReasonHangUp::marshallJson() {
  return QJsonObject{{"@type", "callDiscardReasonHangUp"}};
}

QJsonObject QTdCallDiscardReasonEmpty::marshallJson() {
  return QJsonObject{{"@type", "callDiscardReasonEmpty"}};
}
