#ifndef QTDAUTHMANAGER_HPP
#define QTDAUTHMANAGER_HPP

#include "QTdAuthParam.hpp"
#include "QTdAuthState.hpp"
#include <QObject>

class QTdAuthManager : public QObject {
  Q_OBJECT
  Q_PROPERTY(State state READ state NOTIFY stateChanged)
  Q_PROPERTY(QTdAuthState *type READ type NOTIFY stateChanged)
  Q_PROPERTY(
      QTdAuthParams *params READ params WRITE setParams NOTIFY paramsChanged)

public:
  explicit QTdAuthManager(QObject *parent = nullptr);

  enum class State {
    Invalid,
    WaitTdParams,
    WaitEncryptionKey,
    WaitPhoneNumber,
    WaitCode,
    WaitPassword,
    Ready,
    LoggingOut,
    Closing,
    Closed
  };
  Q_ENUM(State)

  State state() const noexcept;
  QTdAuthState *type() const;
  QTdAuthParam *params() const;

public slots:
  void setParams(QTdAuthParam *params);
  void sendParams();
  void setEncryptionKey(const QString &key);
  void sendPhoneNumber(const QString &phoneNumber);
  void sendCode(const QString &code);
  void registerUser(const QString &firstname, const QString &lastname = "");
  void sendPassword(const QString &password);
  void logout();
  void deleteAccount(const QString &reason);

signals:
  void stateChanged(State state);
  void waitingForTdParams();
  void waitingForEncryptionKey();
  void waitingForRegisteration();
  void waitingForPhoneNumber();
  void waitingForCode();
  void waitingForPassword(QString passwordHint, bool hasRecoveryEmailAddress,
                          QString recoveryEmailAddress);
  void phoneNumberError(QString message);
  void codeError(QString message);
  void passwordError(QString message);
  void ready();
  void logginOut();
  void closing();
  void closed();
  void paramChanged(QTdAuthParam *params);

private slots:
  void handleAuthStateChanged(QTdAuthState *state);

private:
  State mState;
  QTdAuthParam *mParams;
};

#endif // QTDAUTHMANAGER_HPP
