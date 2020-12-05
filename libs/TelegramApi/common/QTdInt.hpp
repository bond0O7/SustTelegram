#ifndef QTDINT_HPP
#define QTDINT_HPP

#include <QDebug>
#include <QJsonValue>

class QTdInt32 {
public:
  QTdInt32() : mValue(0) {}
  QTdInt32(qint32 value) : mValue(value) {}
  QJsonValue toJsonValue() const;
  QString toQmlValue() const;
  qint32 value() const noexcept;
  bool isValid() const noexcept { return mValue > 0; }
  void operator=(const qint32 value) { mValue = value; }
  void operator=(const QJsonValue &value) {
    mValue = static_cast<qint32>(value.toInt());
  }
  void operator=(const QString &value) {
    mValue = static_cast<qint32>(value.toInt());
  }

private:
  qint32 mValue;
};

class QTdInt53 {
public:
  QTdInt53() : mValue(0) {}
  QTdInt53(qint64 value) : mValue(value) {}
  QJsonValue toJsonValue() const;
  QString toQmlValue() const;
  bool isValid() const noexcept { return mValue > 0; }
  qint64 value() const noexcept { return mValue; }
  void operator=(const QJsonValue &value) { mValue = value.toDouble(); }
  void operator=(const qint64 value) { mValue = value; }
  void operator=(const QString &value) { mValue = value.toLongLong(); }

private:
  qint64 mValue;
};
class QTdInt64 {
public:
  QTdInt64() : mValue(0) {}
  QTdInt64(qint64 value) : mValue(value) {}
  QJsonValue toJsonValue() const;
  QString toQmlValue() const;
  bool isValid() const noexcept { return mValue > 0; }
  qint64 value() const noexcept { return mValue; }
  void operator=(const QJsonValue &value) {
    auto ok = false;
    auto res = value.toVariant();
    mValue = res.toLongLong(&ok);
    if (!ok) {
      qWarning() << "Failed to parse qint64 from json value: [Json]" << value;
    }
  }
  void operator=(const QString &value) { mValue = value.toLongLong(); }

private:
  qint64 mValue;
};

#endif // QTDINT_HPP
