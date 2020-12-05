#include "QTdThread.hpp"
#include <QByteArray>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <td/telegram/td_json_client.h>

QTdWorker::QTdWorker(QObject *parent)
    : QObject(parent), mTdlib(QTdHandle::instance()) {}

QTdWorker::~QTdWorker() { mTdlib.clear(); }

void QTdWorker::run() {
  forever {
    const auto rcv = QByteArray(td_json_client_receive(mTdlib->handle(), 1));
    if (!rcv.isEmpty()) {
      const auto json = QJsonDocument::fromJson(rcv).object();
      if (!json.isEmpty()) {
        emit recv(json);

        // check if it's in the closing state
        if (json["@type"] == "updateAuthorizationState") {
          const auto state = json["authorization_state"].toObject();
          if (state["type"] == "authorizationStateClosed") {
            qDebug() << "Closing connection";
            break;
          }
        }
      }
    }
  }
}
