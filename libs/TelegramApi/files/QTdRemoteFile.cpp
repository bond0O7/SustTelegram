#include "QTdRemoteFile.hpp"

QTdRemoteFile::QTdRemoteFile(QObject *parent) : QTdObject(parent) {
  setType(Type::RemoteFile);
}

void QTdRemoteFile::unmarshallJson(const QJsonObject &json) {
  mId = json["id"].toString();
  emit idChanged(mId);
  mUniqueId = json["unique_id"].toString();
  mIsUploadingActive = json["is_uploading_active"].toBool();
  emit isUploadingActiveChanged(mIsUploadingActive);
  mIsUploadingCompleted = json["is_uploading_completed"].toBool();
  emit isUploadingCompletedChanged(mIsUploadingCompleted);
  mUploadedSize = json["uploaded_size"];
  emit uploadedSizeChanged(mUploadedSize.toQmlValue());
  QTdObject::unmarshallJson(json);
}

QString QTdRemoteFile::id() const { return mId; }

QString QTdRemoteFile::uniqueId() const { return mUniqueId; }

bool QTdRemoteFile::isUploadingActive() const { return mIsUploadingActive; }

bool QTdRemoteFile::isUploadingCompleted() const {
  return mIsUploadingCompleted;
}

QTdInt32 QTdRemoteFile::uploadedSize() const { return mUploadedSize; }

QString QTdRemoteFile::qmlUploadedSize() const {
  return mUploadedSize.toQmlValue();
}
