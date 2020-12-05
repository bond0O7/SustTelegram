#ifndef QABSTRACTINT32ID_HPP
#define QABSTRACTINT32ID_HPP

#include "QAbstractTdObject.hpp"
#include "QTdInt.hpp"
#include <QObject>

class QAbstractInt32Id : public QTdObject {
  Q_OBJECT
  Q_DISABLE_COPY(QAbstractInt32Id)
  Q_PROPERTY(QString id READ qmlId NOTIFY idChanged)
public:
  explicit QAbstractInt32Id(QObject *parent = nullptr);
  qint32 id() const noexcept;
  QString qmlId() const;
  QJsonValue jsonId() const;
  static QAbstractInt32Id *create(const QJsonObject &json, QObject *parent);

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void idChanged(int id);

private:
  QTdInt32 mId;
};

#endif // QABSTRACTINT32ID_HPP
