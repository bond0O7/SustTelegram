#ifndef QTDREMOTEFILE_HPP
#define QTDREMOTEFILE_HPP

#include "../common/QAbstractTdObject.hpp"
#include "../common/QTdInt.hpp"

class QTdRemoteFile : public QTdObject {
  Q_OBJECT
  Q_PROPERTY(QString id READ id NOTIFY idChanged)
  Q_PROPERTY(bool isUploadingActive READ isUploadingActive NOTIFY
                 isUploadingActiveChanged)
  Q_PROPERTY(bool isUploadingCompleted READ isUploadingCompleted NOTIFY
                 isUploadingCompletedChanged)
  Q_PROPERTY(
      QString uploadedSize READ qmlUploadedSize NOTIFY uploadedSizeChanged)
public:
  explicit QTdRemoteFile(QObject *parent = nullptr);

  void unmarshallJson(const QJsonObject &json) override;

  QString id() const;

  QString uniqueId() const;

  bool isUploadingActive() const;

  bool isUploadingCompleted() const;

  QTdInt32 uploadedSize() const;
  QString qmlUploadedSize() const;

signals:
  void idChanged(QString id);
  void isUploadingActiveChanged(bool isUploadingActive);
  void isUploadingCompletedChanged(bool isUploadingCompleted);
  void uploadedSizeChanged(QString uploadSize);

private:
  QString mId;
  QString mUniqueId;
  bool mIsUploadingActive;
  bool mIsUploadingCompleted;
  QTdInt32 mUploadedSize;
};

#endif // QTDREMOTEFILE_HPP
