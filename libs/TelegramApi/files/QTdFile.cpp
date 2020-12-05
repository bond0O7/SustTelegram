#include "QTdFile.hpp"

QTdFile::QTdFile(QObject *parent) : QTdObject(parent) { setType(Type::File); }

void QTdFile::unmarshallJson(const QJsonObject &json) {
  mId.unmarshallJson(json);
  mSize = json["size"];
  mExpectedSize = json["expected_size"];
  mLocalFile->unmarshallJson(json["local"].toObject());
  mRemoteFile->unmarshallJson(json["remote"].toObject());
  emit fileChanged();
}

QTdInt32 QTdFile::id() const noexcept { return mId.id(); }

qint32 QTdFile::size() const noexcept { return mSize.value(); }

QString QTdFile::qmlSize() const { return mSize.toQmlValue(); }

qint32 QTdFile::expectedSize() const noexcept { return mExpectedSize.value(); }

QString QTdFile::qmlExpectedSize() const { return mExpectedSize.toQmlValue(); }

QTdLocalFile *QTdFile::localFile() const { return mLocalFile.get(); }

QTdRemoteFile *QTdFile::remoteFile() const { return mRemoteFile.get(); }

void QTdFile::downloadFile() {} // TODO: Implement it

void QTdFile::handleUpdateFile(const QJsonObject &json) {
  if (json["id"] != id().value()) {
    return;
  }
  this->unmarshallJson(json);
}
