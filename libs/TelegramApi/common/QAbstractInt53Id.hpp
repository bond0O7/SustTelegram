#ifndef QABSTRACT53ID_HPP
#define QABSTRACT53ID_HPP

#include "QAbstractTdObject.hpp"
#include "QTdInt.hpp"

class QAbstract53Id : public QTdObject {
  Q_DISABLE_COPY(QAbstract53Id)
  Q_PROPERTY(QString id READ qmlId NOTIFY idChanged)
  Q_OBJECT
public:
  explicit QAbstract53Id(QObject *parent = nullptr);

  qint64 id() const noexcept;
  QString qmlId() const;
  QJsonValue jsonId() const;

  static QAbstract53Id *create(const QJsonObject &json, QObject *parent);

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void idChanged(int id);

private:
  QTdInt53 mId;
};

#endif // QABSTRACT53ID_HPP
