#include "QTdAuthManager.hpp"

QTdAuthManager::QTdAuthManager(QObject *parent) : QObject(parent) {}

QTdAuthManager::State QTdAuthManager::state() const noexcept { return mState; }

QTdAuthState *QTdAuthManager::type() const {}

QTdAuthParam *QTdAuthManager::params() const {}

void QTdAuthManager::setParams(QTdAuthParam *params) {}

void QTdAuthManager::sendParams() {}

void QTdAuthManager::setEncryptionKey(const QString &key) {}

void QTdAuthManager::sendPhoneNumber(const QString &phoneNumber) {}

void QTdAuthManager::sendCode(const QString &code) {}

void QTdAuthManager::registerUser(const QString &firstname,
                                  const QString &lastname) {}

void QTdAuthManager::sendPassword(const QString &password) {}

void QTdAuthManager::logout() {}

void QTdAuthManager::deleteAccount(const QString &reason) {}
