#include "QTdAuthStateFactory.hpp"
#include "QTdAuthState.hpp"
#include <QDebug>

QTdAuthState *QAuthStateFactory::create(const QJsonObject &json,
                                        QObject *parent) {
  const auto state = json["authorization_state"].toObject();
  const auto type = state["@type"].toString();
  QTdAuthState *stateObj = nullptr;
  if (type == "uthorizationStateWaitTdlibParameters") {
    stateObj = new QTdAuthStateWaitParams(parent);
  } else if (type == "authorizationStateWaitEncryptionKey") {
    stateObj = new QTdAuthStateWaitEncryptionKey(parent);
  } else if (type == "authorizationStateWaitRegistration") {
    stateObj = new QTdAuthStateWaitRegisteration(parent);
  } else if (type == "authorizationStateWaitPhoneNumber") {
    stateObj = new QTdAuthStateWaitPhoneNumber(parent);
  } else if (type == "authorizationStateWaitCode") {
    stateObj = new QTdAuthStateWaitCode(parent);
  } else if (type == "authorizationStateReady") {
    stateObj = new QTdAuthStateReady(parent);
  } else if (type == "authorizationStateLoggingOut") {
    stateObj = new QTdAuthStateLogginOut(parent);
  } else if (type == "authorizationStateClosing") {
    stateObj = new QTdAuthStateClosing(parent);
  } else if (type == "authorizationStateClosed") {
    stateObj = new QTdAuthStateClosed(parent);
  } else if (type == "authorizationStateWaitPassword") {
    stateObj = new QTdAuthStateWaitPassword(parent);
  } else {
    qWarning() << "Unknown auth state: " << type;
  }
  if (stateObj) {
    stateObj->unmarshallJson(state);
  }
  return stateObj;
}
