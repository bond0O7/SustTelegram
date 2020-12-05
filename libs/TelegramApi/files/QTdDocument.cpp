#include "QTdDocument.hpp"

QTdDocument::QTdDocument(QObject *parent) : QTdObject(parent) {
  setType(Type::Document);
}

void QTdDocument::unmarshallJson(const QJsonObject &json) {
  mFileName = json["filename"].toString();
  mMimeType = json["mime_type"].toString();
  if (json.contains("thumnail")) {
    mThumbnail->unmarshallJson(json["thumbnail"].toObject());
  }
  mDocument->unmarshallJson(json["document"].toObject());
  emit documentChanged();
}

QString QTdDocument::fileName() const { return mFileName; }

QString QTdDocument::mimeType() const { return mMimeType; }

QTdPhotoSize *QTdDocument::thumbnail() const { return mThumbnail.get(); }

QTdFile *QTdDocument::document() const { return mDocument.get(); }
