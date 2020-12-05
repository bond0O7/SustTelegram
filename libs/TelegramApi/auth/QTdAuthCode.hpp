#ifndef QTDAUTHCODE_HPP
#define QTDAUTHCODE_HPP

#include "../common/QAbstractTdObject.hpp"
#include "../common/QTdInt.hpp"

class QTdAuthCode : public QTdObject {
  Q_OBJECT
public:
  explicit QTdAuthCode(QObject *parent = nullptr);
};

class QTdAuthCodeTelegramMessage : public QTdAuthCode {
  Q_OBJECT
  Q_PROPERTY(QString length READ qmlLength NOTIFY lengthChanged)

public:
  explicit QTdAuthCodeTelegramMessage(QObject *parent = nullptr);
  QString qmlLength() const;
  qint32 length() const noexcept;

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void lengthChanged();

private:
  QTdInt32 mLength;
};

class QTdAuthCodeSms : public QTdAuthCode {
  Q_OBJECT
  Q_PROPERTY(QString length READ qmlLength NOTIFY lengthChanged)

public:
  explicit QTdAuthCodeSms(QObject *parent = nullptr);
  QString qmlLength() const;
  qint32 length() const noexcept;

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void lengthChanged();

private:
  QTdInt32 mLength;
};

class QTdAuthCodeCall : public QTdAuthCode {
  Q_OBJECT
  Q_PROPERTY(QString length READ qmlLength NOTIFY lengthChanged)

public:
  explicit QTdAuthCodeCall(QObject *parent = nullptr);
  QString qmlLength() const;
  qint32 length() const noexcept;

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void lengthChanged();

private:
  QTdInt32 mLength;
};

class QTdAuthCodeFlashCall : public QTdAuthCode {
  Q_OBJECT
  Q_PROPERTY(QString pattern READ pattern NOTIFY patternChanged)

public:
  explicit QTdAuthCodeFlashCall(QObject *parent = nullptr);
  QString pattern() const;

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void patternChanged();

private:
  QString mPattern;
};

class QTdAuthCodeInfo : public QTdObject {
  Q_OBJECT
  Q_PROPERTY(QString timeout READ qmlTimeout NOTIFY infoChanged)
  Q_PROPERTY(QTdAuthCode *type READ type NOTIFY infoChanged)
  Q_PROPERTY(QTdAuthCode *type READ nextType NOTIFY infoChanged)

public:
  explicit QTdAuthCodeInfo(QObject *parent = nullptr);
  QString qmlTimeout() const;
  QTdAuthCode *type() const;
  QTdAuthCode *nextType() const;

  static QTdAuthCode *create(const QJsonObject &json, QObject *parent);

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void infoChanged();

private:
  QTdInt32 mTimeout;
  QTdAuthCode *mType;
  QTdAuthCode *mNextType;
};

#endif // QTDAUTHCODE_HPP
