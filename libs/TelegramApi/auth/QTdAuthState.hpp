#ifndef QTDAUTHSTATAE_HPP
#define QTDAUTHSTATAE_HPP
#include "QTdAuthCode.hpp"
class QTdAuthState : public QTdObject {
  Q_OBJECT
public:
  explicit QTdAuthState(QObject *parent = nullptr);
};

class QTdAuthStateWaitParams : public QTdAuthState {
  Q_OBJECT
public:
  explicit QTdAuthStateWaitParams(QObject *parent = nullptr);
};

class QTdAuthStateWaitEncryptionKey : public QTdAuthState {
  Q_OBJECT
public:
  explicit QTdAuthStateWaitEncryptionKey(QObject *parent = nullptr);

  bool isEncrypted() const noexcept;

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void isEncryptedChanged(bool encrypted);

protected:
  void setIsEncrypted(const bool isEncrypted);

private:
  bool mIsEncrtypted;
};

class QTdAuthStateWaitRegisteration : public QTdAuthState {
  Q_OBJECT
public:
  // TODO: Terms Of services
  explicit QTdAuthStateWaitRegisteration(QObject *parent = nullptr);
};

class QTdAuthStateWaitPhoneNumber : public QTdAuthState {
  Q_OBJECT
public:
  explicit QTdAuthStateWaitPhoneNumber(QObject *parent = nullptr);
};

class QTdAuthStateWaitCode : public QTdAuthState {
  Q_PROPERTY(QTdAuthCodeInfo *info READ info NOTIFY infoChanged)
  Q_OBJECT
public:
  explicit QTdAuthStateWaitCode(QObject *parent = nullptr);

  QTdAuthCodeInfo *info() const;
  bool isRegistered() const noexcept;

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void infoChanged();
  void isRegisteredChanged();

private:
  QTdAuthCodeInfo *mInfo;
  bool mIsRegistered;
};

class QTdAuthStateWaitPassword : public QTdAuthState {
  Q_OBJECT
  Q_PROPERTY(QString passwordHint READ passwordHint NOTIFY dataChanged)
  Q_PROPERTY(bool hasRecoveryEmailAddress READ hasRecoveryEmailAddress NOTIFY
                 dataChanged)
  Q_PROPERTY(
      QString recoveryEmailAddress READ recoveryEmailAddress NOTIFY dataChanged)
public:
  explicit QTdAuthStateWaitPassword(QObject *parent = nullptr);

  QString passwordHint() const;
  bool hasRecoveryEmailAddress() const noexcept;
  QString recoveryEmailAddressPattern() const;

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void dataChanged();

private:
  QString mPasswordHint;
  bool mHasRecoveryEmailAddress;
  QString mRecoveryEmailAddressPattern;
};

class QTdAuthStateReady : public QTdAuthState {
  Q_OBJECT
public:
  explicit QTdAuthStateReady(QObject *parent = nullptr);
};

class QTdAuthStateLogginOut : public QTdAuthState {
  Q_OBJECT
public:
  explicit QTdAuthStateLogginOut(QObject *parent = nullptr);
};
class QTdAuthStateClosing : public QTdAuthState {
  Q_OBJECT
public:
  explicit QTdAuthStateClosing(QObject *parent = nullptr);
};
class QTdAuthStateClosed : public QTdAuthState {
  Q_OBJECT
public:
  explicit QTdAuthStateClosed(QObject *parent = nullptr);
};

#endif // QTDAUTHSTATAE_HPP
