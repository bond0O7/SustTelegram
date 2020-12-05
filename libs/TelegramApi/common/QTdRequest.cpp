#include "QTdRequest.hpp"

QTdRequest::QTdRequest(QObject *parent) : QTdObject(parent) {}

void QTdRequest::send() {}

QFuture<QJsonObject> QTdRequest::exec() {}

QTdOkRequest::QTdOkRequest(QObject *parent) : QTdRequest(parent) {}

QFuture<QTdResponse> QTdOkRequest::sendAsync() {}
