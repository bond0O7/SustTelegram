#include "QTdAuthCode.hpp"
#include <QStringLiteral>
QTdAuthCode::QTdAuthCode(QObject *parent) : QTdObject(parent) {}

QTdAuthCodeTelegramMessage::QTdAuthCodeTelegramMessage(QObject *parent)
    : QTdAuthCode(parent) {
  setType(Type::AuthenticationCodeTypeTelegramMessage);
}

QString QTdAuthCodeTelegramMessage::qmlLength() const {
  return mLength.toQmlValue();
}

qint32 QTdAuthCodeTelegramMessage::length() const noexcept {
  return mLength.value();
}

void QTdAuthCodeTelegramMessage::unmarshallJson(const QJsonObject &json) {
  if (json.contains("length")) {
    mLength = json["length"];
    emit lengthChanged();
  }
  QTdAuthCode::unmarshallJson(json);
}
QTdAuthCodeSms::QTdAuthCodeSms(QObject *parent) : QTdAuthCode(parent) {
  setType(Type::AuthenticationCodeTypeSms);
}

QString QTdAuthCodeSms::qmlLength() const { return mLength.toQmlValue(); }

qint32 QTdAuthCodeSms::length() const noexcept { return mLength.value(); }

void QTdAuthCodeSms::unmarshallJson(const QJsonObject &json) {
  if (json.contains("length")) {
    mLength = json["length"];
    emit lengthChanged();
  }
  QTdAuthCode::unmarshallJson(json);
}
QTdAuthCodeCall::QTdAuthCodeCall(QObject *parent) : QTdAuthCode(parent) {
  setType(Type::AuthenticationCodeTypeCall);
}

QString QTdAuthCodeCall::qmlLength() const { return mLength.toQmlValue(); }

qint32 QTdAuthCodeCall::length() const noexcept { return mLength.value(); }

void QTdAuthCodeCall::unmarshallJson(const QJsonObject &json) {
  if (json.contains("length")) {
    mLength = json["length"];
    emit lengthChanged();
  }
  QTdAuthCode::unmarshallJson(json);
}
QTdAuthCodeFlashCall::QTdAuthCodeFlashCall(QObject *parent)
    : QTdAuthCode(parent) {
  setType(Type::AuthenticationCodeTypeFlashCall);
}

QString QTdAuthCodeFlashCall::pattern() const { return mPattern; }

void QTdAuthCodeFlashCall::unmarshallJson(const QJsonObject &json) {
  if (json.contains("pattern")) {
    mPattern = json["pattern"].toString();
    emit patternChanged();
  }
  QTdAuthCode::unmarshallJson(json);
}
QTdAuthCodeInfo::QTdAuthCodeInfo(QObject *parent)
    : QTdObject(parent), mTimeout(0), mType(nullptr), mNextType(nullptr) {}

QString QTdAuthCodeInfo::qmlTimeout() const { return mTimeout.toQmlValue(); }

QTdAuthCode *QTdAuthCodeInfo::type() const { return mType; }

QTdAuthCode *QTdAuthCodeInfo::nextType() const { return mNextType; }

QTdAuthCode *QTdAuthCodeInfo::create(const QJsonObject &json, QObject *parent) {
  const auto type = json["@type"].toString();
  if (type == QStringLiteral("authenticationCodeTypeSms")) {
    auto sms = new QTdAuthCodeSms(parent);
    sms->unmarshallJson(json);
    return sms;
  } else if (type == QStringLiteral("authenticationCodeTypeCall")) {
    auto call = new QTdAuthCodeCall(parent);
    call->unmarshallJson(json);
    return call;
  } else if (type == QStringLiteral("authenticationCodeTypeFlashCall")) {
    auto flashCall = new QTdAuthCodeFlashCall(parent);
    flashCall->unmarshallJson(json);
    return flashCall;
  } else if (type == QStringLiteral("authenticationCodeTypeTelegramMessage")) {
    auto telegramMessage = new QTdAuthCodeTelegramMessage(parent);
    telegramMessage->unmarshallJson(json);
    return telegramMessage;
  }
  return nullptr;
}

void QTdAuthCodeInfo::unmarshallJson(const QJsonObject &json) {
  mTimeout = json["timeout"];
  if (mType) {
    delete mType;
    mType = nullptr;
  }
  mType = QTdAuthCodeInfo::create(json["type"].toObject(), this);
  if (mNextType) {
    delete mNextType;
    mNextType = nullptr;
  }
  mNextType = QTdAuthCodeInfo::create(json["next_type"].toObject(), this);
  emit infoChanged();
}
