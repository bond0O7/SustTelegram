#ifndef QTDPHOTOSIZE_HPP
#define QTDPHOTOSIZE_HPP
#include "../common/QAbstractTdObject.hpp"
#include "../common/QTdInt.hpp"
#include "QTdFile.hpp"
#include <QScopedPointer>

class QTdPhotoSize : public QTdObject {
  Q_OBJECT
  Q_PROPERTY(QString type READ type NOTIFY photoSizeChanged)
  Q_PROPERTY(QTdFile *photo READ photo NOTIFY photoSizeChanged)
  Q_PROPERTY(qint32 width READ width NOTIFY photoSizeChanged)
  Q_PROPERTY(qint32 height READ height NOTIFY photoSizeChanged)
public:
  explicit QTdPhotoSize(QObject *parent = nullptr);

  QString type() const;
  QTdFile *photo() const;
  qint32 width() const noexcept;
  qint32 height() const noexcept;

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

signals:
  void photoSizeChanged();

private:
  QString mType;
  QScopedPointer<QTdFile> mPhoto;
  QTdInt32 mWidth;
  QTdInt32 mHeigth;
};

#endif // QTDPHOTOSIZE_HPP
