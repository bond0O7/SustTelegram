#include "QTdResponse.hpp"

QTdResponse::QTdResponse(QObject *parent) : QTdObject(parent) {}

bool QTdResponse::isError() const noexcept {
  if (mJson.contains("@type")) {
    return mJson["@type"].toString().toLower() == "error";
  }
  return false;
}

QString QTdResponse::erroString() const {
  return isError() ? mJson.value("message").toString() : QString();
}

int QTdResponse::errorCode() const {
  return isError() ? mJson.value("code").toInt() : 0;
}

bool QTdResponse::isOk() const noexcept {
  if (mJson.contains("@type")) {
    return mJson.value("@type").toString().toLower() == "ok";
  }
  return false;
}

QJsonObject QTdResponse::json() const { return mJson; }

void QTdResponse::setJson(const QJsonObject &json) { mJson = json; }
