#ifndef QTDLOCALFILE_HPP
#define QTDLOCALFILE_HPP

#include "../common/QAbstractTdObject.hpp"
#include "../common/QTdInt.hpp"

class QTdLocalFile : public QTdObject {
  Q_PROPERTY(QString path READ path NOTIFY pathChanged)
  Q_PROPERTY(
      bool canBeDownloaded READ canBeDownloaded NOTIFY canBeDownloadedChanged)
  Q_PROPERTY(bool canBeDeleted READ canBeDeleted NOTIFY canBeDeletedChanged)
  Q_PROPERTY(bool isDownloadingActive READ isDownloadingActive NOTIFY
                 isDownloadingActiveChanged)
  Q_PROPERTY(bool isDownloadingCompleted READ isDownloadingCompleted NOTIFY
                 isDownloadingCompletedChanged)
  Q_PROPERTY(QString downloadOffset READ qmlDownloadOffset NOTIFY
                 downloadOffsetChanged)
  Q_PROPERTY(QString downloadedPrefixSize READ qmlDownloadedPrefixSize NOTIFY
                 downloadedPrefixSizeChanged)
  Q_PROPERTY(
      QString downloadSize READ qmlDownloadSize NOTIFY downloadedSizeChanged)
  Q_OBJECT
public:
  explicit QTdLocalFile(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

public:
  QString path() const;

  bool canBeDownloaded() const;

  bool canBeDeleted() const;

  bool isDownloadingActive() const;

  bool isDownloadingCompleted() const;

  QTdInt32 downloadOffset() const;
  QString qmlDownloadOffset() const;

  QTdInt32 downloadedPrefixSize() const;
  QString qmlDownloadedPrefixSize() const;

  QTdInt32 downloadedSize() const;
  QString qmlDownloadSize() const;

signals:
  void pathChanged(QString path);
  void canBeDownloadedChanged(bool canBeDownloaded);
  void canBeDeletedChanged(bool canBeDeleted);
  void isDownloadingActiveChanged(bool isDownlaodingActive);
  void isDownloadingCompletedChanged(bool isDownloadingCompleted);
  void downloadOffsetChanged();
  void downloadedPrefixSizeChanged();
  void downloadedSizeChanged();

private:
  QString mPath;
  bool mCanBeDownloaded;
  bool mCanBeDeleted;
  bool mIsDownloadingActive;
  bool mIsDownloadingCompleted;
  QTdInt32 mDownloadOffset;
  QTdInt32 mDownloadedPrefixSize;
  QTdInt32 mDownloadedSize;
};

#endif // QTDLOCALFILE_HPP
