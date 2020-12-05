#include "QTdPhotoSize.hpp"

QTdPhotoSize::QTdPhotoSize(QObject *parent) : QTdObject(parent) {
  setType(Type::PhotoSize);
}

QString QTdPhotoSize::type() const { return mType; }

QTdFile *QTdPhotoSize::photo() const { return mPhoto.get(); }

qint32 QTdPhotoSize::width() const noexcept { return mWidth.value(); }

qint32 QTdPhotoSize::height() const noexcept { return mHeigth.value(); }

void QTdPhotoSize::unmarshallJson(const QJsonObject &json) {
  mPhoto->unmarshallJson(json["photo"].toObject());
  if (mPhoto->localFile()->path().isEmpty()) {
    mPhoto->downloadFile();
  }
  mWidth = json["width"];
  mHeigth = json["height"];
  mType = json["type"].toString();
  emit photoSizeChanged();
}
