#ifndef QTDRESPONSE_HPP
#define QTDRESPONSE_HPP
#include "QAbstractTdObject.hpp"
#include <QJsonObject>

class QTdResponse : public QTdObject {
  Q_OBJECT
public:
  explicit QTdResponse(QObject *parent = nullptr);

  bool isError() const noexcept;
  QString erroString() const;
  int errorCode() const;
  bool isOk() const noexcept;
  QJsonObject json() const;
  void setJson(const QJsonObject &json);

private:
  QJsonObject mJson;
};

#endif // QTDRESPONSE_HPP
