#ifndef QTDFILE_HPP
#define QTDFILE_HPP

#include "../common/QAbstractInt32Id.hpp"
#include "../common/QAbstractTdObject.hpp"
#include "QTdLocalFile.hpp"
#include "QTdRemoteFile.hpp"
#include <QScopedPointer>

class QTdFile : public QTdObject {
  Q_OBJECT
  Q_PROPERTY(QString size READ qmlSize NOTIFY fileChanged)
  Q_PROPERTY(QString expectedSize READ qmlExpectedSize NOTIFY fileChanged)
  Q_PROPERTY(QLocalFile *localFile READ localFile NOTIFY fileChanged)
  Q_PROPERTY(QRemoteFile *remoteFile READ remoteFile NOTIFY fileChanged)
public:
  explicit QTdFile(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual void unmarshallJson(const QJsonObject &json) override;

public:
  QTdInt32 id() const noexcept;

  qint32 size() const noexcept;
  QString qmlSize() const;

  qint32 expectedSize() const noexcept;
  QString qmlExpectedSize() const;

  QTdLocalFile *localFile() const;
  QTdRemoteFile *remoteFile() const;

  Q_INVOKABLE void downloadFile();

signals:
  void fileChanged();

private slots:
  void handleUpdateFile(const QJsonObject &json);

private:
  QAbstractInt32Id mId;
  QTdInt32 mSize;
  QTdInt32 mExpectedSize;
  QScopedPointer<QTdLocalFile> mLocalFile;
  QScopedPointer<QTdRemoteFile> mRemoteFile;
};

#endif // QTDFILE_HPP
