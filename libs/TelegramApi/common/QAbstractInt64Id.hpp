#ifndef QABSTRACTINT64ID_HPP
#define QABSTRACTINT64ID_HPP

#include "QAbstractTdObject.hpp"
#include "QTdInt.hpp"

class QAbstractInt64Id : public QTdObject {
  Q_DISABLE_COPY(QAbstractInt64Id)
  Q_PROPERTY(QString id READ qmlId NOTIFY idChanged)
  Q_OBJECT
public:
  explicit QAbstractInt64Id(QObject *parent = nullptr);
  QString qmlId() const;
  QJsonValue jsonId() const;
  qint64 id() const noexcept;

  static QAbstractInt64Id *create(const QJsonObject &json, QObject *parent);

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void idChanged(int);

private:
  QTdInt64 mId;
};

#endif // QABSTRACTINT64ID_HPP
