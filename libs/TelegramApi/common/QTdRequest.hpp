#ifndef QTDREQUEST_HPP
#define QTDREQUEST_HPP
#include "QAbstractTdObject.hpp"
#include "QTdResponse.hpp"
#include <QJsonObject>
#include <QtConcurrent>

class QTdRequest : public QTdObject {
  Q_DISABLE_COPY(QTdRequest)
  Q_OBJECT
public:
  explicit QTdRequest(QObject *parent = nullptr);
  virtual QFuture<QTdResponse> sendAsync() = 0;
  virtual void send();
  virtual QFuture<QJsonObject> exec();
};

class QTdOkRequest : public QTdRequest {
  Q_DISABLE_COPY(QTdOkRequest)
  Q_OBJECT
public:
  explicit QTdOkRequest(QObject *parent = nullptr);
  QFuture<QTdResponse> sendAsync();
};

#endif // QTDREQUEST_HPP
