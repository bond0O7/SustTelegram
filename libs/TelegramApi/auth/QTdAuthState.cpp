#include "QTdAuthState.hpp"
QTdAuthState::QTdAuthState(QObject *parent) : QTdObject(parent) {}

QTdAuthStateWaitParams::QTdAuthStateWaitParams(QObject *parent)
    : QTdAuthState(parent) {
  setType(Type::AuthorizationStateWaitTdlibParameters);
}

QTdAuthStateWaitEncryptionKey::QTdAuthStateWaitEncryptionKey(QObject *parent)
    : QTdAuthState(parent) {
  setType(Type::AuthorizationStateWaitEncryptionKey);
}

bool QTdAuthStateWaitEncryptionKey::isEncrypted() const noexcept {
  return mIsEncrtypted;
}
void QTdAuthStateWaitEncryptionKey::setIsEncrypted(const bool isEncrypted) {
  if (mIsEncrtypted != isEncrypted) {
    mIsEncrtypted = isEncrypted;
    emit isEncryptedChanged(mIsEncrtypted);
  }
}

void QTdAuthStateWaitEncryptionKey::unmarshallJson(const QJsonObject &json) {
  if (json.contains("is_encrypted")) {
    mIsEncrtypted = json["is_encrypted"].toBool();
  }
  QTdAuthState::unmarshallJson(json);
}

QTdAuthStateWaitRegisteration::QTdAuthStateWaitRegisteration(QObject *parent)
    : QTdAuthState(parent) {
  setType(Type::AuthorizationStateWaitRegisteration);
}

QTdAuthStateWaitPhoneNumber::QTdAuthStateWaitPhoneNumber(QObject *parent)
    : QTdAuthState(parent) {
  setType(Type::AuthorizationStateWaitPhoneNumber);
}

QTdAuthStateWaitCode::QTdAuthStateWaitCode(QObject *parent)
    : QTdAuthState(parent) {
  setType(Type::AuthorizationStateWaitCode);
}

QTdAuthCodeInfo *QTdAuthStateWaitCode::info() const { return mInfo; }

bool QTdAuthStateWaitCode::isRegistered() const noexcept {
  return mIsRegistered;
}

void QTdAuthStateWaitCode::unmarshallJson(const QJsonObject &json) {
  if (mInfo) {
    delete mInfo;
  }
  mInfo = new QTdAuthCodeInfo(this);
  emit infoChanged();
  if (json.contains("is_registered")) {
    mIsRegistered = json["is_registered"].toBool();
    emit isRegisteredChanged();
  }
  QTdAuthState::unmarshallJson(json);
}
QTdAuthStateWaitPassword::QTdAuthStateWaitPassword(QObject *parent)
    : QTdAuthState(parent) {
  setType(Type::AuthorizationStateWaitPassword);
}

QString QTdAuthStateWaitPassword::passwordHint() const { return mPasswordHint; }

bool QTdAuthStateWaitPassword::hasRecoveryEmailAddress() const noexcept {
  return mHasRecoveryEmailAddress;
}

QString QTdAuthStateWaitPassword::recoveryEmailAddressPattern() const {
  return mRecoveryEmailAddressPattern;
}

void QTdAuthStateWaitPassword::unmarshallJson(const QJsonObject &json) {
  auto changed = false;
  if (json.contains("password_hint")) {
    mPasswordHint = json["password_hint"].toString();
    changed = true;
  }
  if (json.contains("has_recovery_email_address")) {
    mHasRecoveryEmailAddress = json["has_recovery_email_address"].toBool();
    changed = true;
  }
  if (json.contains("recovery_email_address_pattern")) {
    mRecoveryEmailAddressPattern =
        json["recovery_email_address_patter"].toString();
    changed = true;
  }
  if (changed) {
    emit dataChanged();
  }
  QTdAuthState::unmarshallJson(json);
}

QTdAuthStateReady::QTdAuthStateReady(QObject *parent) : QTdAuthState(parent) {
  setType(Type::AuthorizationStateReady);
}

QTdAuthStateLogginOut::QTdAuthStateLogginOut(QObject *parent) : QTdAuthState(parent) {

  setType(Type::AuthorizationStateLogginOut);
}

QTdAuthStateClosing::QTdAuthStateClosing(QObject *parent) : QTdAuthState(parent) {
  setType(Type::AuthorizationStateClosing);
}

QTdAuthStateClosed::QTdAuthStateClosed(QObject *parent) : QTdAuthState(parent) {
  setType(Type::SecretChatStateClosed);
}
