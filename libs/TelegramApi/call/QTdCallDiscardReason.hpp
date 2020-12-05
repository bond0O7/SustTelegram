#ifndef QTDCALLDISCARDREASON_HPP
#define QTDCALLDISCARDREASON_HPP
#include "../common/QAbstractTdObject.hpp"
#include <td/telegram/td_api.h>

class QTdCallDiscardReason : public QTdObject {
  Q_OBJECT
public:
  explicit QTdCallDiscardReason(QObject *parent = nullptr);
};
class QTdCallDiscardReasonEmpty : public QTdCallDiscardReason {
  Q_OBJECT
public:
  explicit QTdCallDiscardReasonEmpty(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual QJsonObject marshallJson() override;
};

class QTdCallDiscardReasonMissed : public QTdCallDiscardReason {
  Q_OBJECT
public:
  explicit QTdCallDiscardReasonMissed(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual QJsonObject marshallJson() override;
};

class QTdCallDiscardReasonDeclined : public QTdCallDiscardReason {
  Q_OBJECT
public:
  explicit QTdCallDiscardReasonDeclined(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual QJsonObject marshallJson() override;
};

class QTdCallDiscardReasonDisconnected : public QTdCallDiscardReason {
  Q_OBJECT
public:
  explicit QTdCallDiscardReasonDisconnected(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual QJsonObject marshallJson() override;
};

class QTdCallDiscardReasonHangUp : public QTdCallDiscardReason {
  Q_OBJECT
public:
  explicit QTdCallDiscardReasonHangUp(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual QJsonObject marshallJson() override;
};

#endif // QTDCALLDISCARDREASON_HPP
