#ifndef QTDDOCUMENT_HPP
#define QTDDOCUMENT_HPP

#include "../common/QAbstractTdObject.hpp"
#include "QTdFile.hpp"
#include "QTdPhotoSize.hpp"

class QTdDocument : public QTdObject {
  Q_OBJECT
  Q_DISABLE_COPY(QTdDocument)
  Q_PROPERTY(QString fileName READ fileName NOTIFY documentChanged)
  Q_PROPERTY(QString mimeType READ mimeType NOTIFY documentChanged)
  Q_PROPERTY(QTdPhotoSize *thumbnail READ thumbnail NOTIFY documentChanged)
  Q_PROPERTY(QTdFile document READ document NOTIFY documentChanged)
public:
  explicit QTdDocument(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

public:
  QString fileName() const;

  QString mimeType() const;

  QTdPhotoSize *thumbnail() const;

  QTdFile *document() const;

signals:
  void documentChanged();

private:
  QString mFileName;
  QString mMimeType;
  QScopedPointer<QTdPhotoSize> mMinithumbnail;
  QScopedPointer<QTdPhotoSize> mThumbnail;
  QScopedPointer<QTdFile> mDocument;
};

#endif // QTDDOCUMENT_HPP
