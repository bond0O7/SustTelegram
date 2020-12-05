#include "QTdLocalFile.hpp"

QTdLocalFile::QTdLocalFile(QObject *parent) : QTdObject(parent) {
  setType(Type::LocalFile);
}

void QTdLocalFile::unmarshallJson(const QJsonObject &json) {
  mPath = json["path"].toString();
  emit pathChanged(mPath);
  mCanBeDownloaded = json["can_be_downloaded"].toBool();
  emit canBeDownloadedChanged(mCanBeDownloaded);
  mCanBeDeleted = json["can_be_deleted"].toBool();
  emit canBeDeletedChanged(mCanBeDeleted);
  mIsDownloadingActive = json["is_downloading_active"].toBool();
  emit isDownloadingActiveChanged(mIsDownloadingActive);
  mIsDownloadingCompleted = json["is_downloading_completed"].toBool();
  emit isDownloadingCompletedChanged(mIsDownloadingCompleted);
  mDownloadedPrefixSize = json["downloaded_prefix_size"];
  emit downloadedPrefixSizeChanged();
  mDownloadedSize = json["downloaded_size"];
  emit downloadedSizeChanged();
  QTdObject::unmarshallJson(json);
}

QString QTdLocalFile::path() const { return mPath; }

bool QTdLocalFile::canBeDownloaded() const { return mCanBeDownloaded; }

bool QTdLocalFile::canBeDeleted() const { return mCanBeDeleted; }

bool QTdLocalFile::isDownloadingActive() const { return mIsDownloadingActive; }

bool QTdLocalFile::isDownloadingCompleted() const {
  return mIsDownloadingCompleted;
}

QTdInt32 QTdLocalFile::downloadOffset() const { return mDownloadOffset; }

QString QTdLocalFile::qmlDownloadOffset() const {
  return mDownloadOffset.toQmlValue();
}

QTdInt32 QTdLocalFile::downloadedPrefixSize() const {
  return mDownloadedPrefixSize;
}

QString QTdLocalFile::qmlDownloadedPrefixSize() const {
  return mDownloadedPrefixSize.toQmlValue();
}

QTdInt32 QTdLocalFile::downloadedSize() const { return mDownloadedSize; }

QString QTdLocalFile::qmlDownloadSize() const {
  return mDownloadedSize.toQmlValue();
}
