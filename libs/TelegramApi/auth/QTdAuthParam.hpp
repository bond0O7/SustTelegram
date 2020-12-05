#ifndef QTDAUTHPARAM_HPP
#define QTDAUTHPARAM_HPP

#include "../common/QAbstractTdObject.hpp"

class QTdAuthParam : public QTdObject {
  Q_OBJECT
  Q_PROPERTY(
      bool useTestDC READ useTestDC WRITE setUseTestDC NOTIFY useTestDCChanged)
  Q_PROPERTY(bool useFileDatabase READ useFileDatabase WRITE setUseFileDatabase
                 NOTIFY useFileDatabaseChanged)
  Q_PROPERTY(bool useChatInfoDatabase READ useChatInfoDatabase WRITE
                 setUseChatInfoDatabase NOTIFY useChatInfoDatabaseChanged)
  Q_PROPERTY(bool useMessageDatabase READ useMessageDatabase WRITE
                 setUseMessageDatabase NOTIFY useMessageDatabaseChanged)
  Q_PROPERTY(bool useSecretChats READ useSecretChats WRITE setUseSecretChats
                 NOTIFY useSecretChatsChanged)
  Q_PROPERTY(bool useStorageOptimizer READ useStorageOptimizer WRITE
                 setUseStorageOptimizer NOTIFY useStorageOptimizerChanged)
  Q_PROPERTY(qint32 apiID READ apiID WRITE setApiID NOTIFY apiIDChanged)
  Q_PROPERTY(
      QString apiHash READ apiHash WRITE setApiHash NOTIFY apiHashChanged)
  Q_PROPERTY(QString systemLanguageCode READ systemLanguageCode WRITE
                 setSystemLanguageCode NOTIFY systemLanguageCodeChanged)
  Q_PROPERTY(QString deviceModel READ deviceModel WRITE setDeviceModel NOTIFY
                 deviceModelChanged)
  Q_PROPERTY(QString systemVersion READ systemVersion WRITE setSystemVersion
                 NOTIFY systemVersionChanged)
  Q_PROPERTY(QString applicationVersion READ applicationVersion WRITE
                 setApplicationVersion NOTIFY applicationVersionChanged)
  Q_PROPERTY(QString databaseDirectory READ databaseDirectory WRITE
                 setDatabaseDirectory NOTIFY databaseDirectoryChanged)
  Q_PROPERTY(QString filesDirectory READ filesDirectory WRITE setFilesDirectory
                 NOTIFY filesDirectoryChanged)

public:
  explicit QTdAuthParam(QObject *parent = nullptr);

  // QTdObject interface
public:
  virtual QJsonObject marshallJson() override;

public slots:
  QString fileDirectory() const;
  void setFileDirectory(const QString &fileDirectory);
  void setUseTestDc(bool useTestDc);
  void setUseFileDatabase(bool useFileDatabase);
  void setUseChatInfoDatabase(bool useChatInfoDatabase);
  void setUseMessageDatabase(bool useMessageDatabase);
  void setUseSecretChat(bool useSecretChat);
  void setUseStorageOptimizer(bool useStorageOptimizer);
  void setApiId(const qint32 apiId);
  void setApiHash(const QString &apiHash);
  void setSystemLanguageCode(const QString &systemLanguageCode);
  void setDeviceModel(const QString &deviceModel);
  void setSystemVersion(const QString &systemVersion);
  void setApplicationVersion(const QString &applicationVersion);
  void setDatabaseDirectory(const QString &databaseDirectory);

public:
  bool useTestDc() const;

  bool useFileDatabase() const;

  bool useChatInfoDatabase() const;

  bool useMessageDatabase() const;

  bool useSecretChat() const;

  bool useStorageOptimizer() const;

  qint32 apiId() const;

  QString apiHash() const;

  QString systemLanguageCode() const;

  QString deviceModel() const;

  QString systemVersion() const;

  QString applicationVersion() const;

  QString databaseDirectory() const;

signals:
  void useTestDCChanged(bool useTestDC);
  void useFileDatabaseChanged(bool useFileDatabase);
  void useChatInfoDatabaseChanged(bool useChatInfoDatabase);
  void useMessageDatabaseChanged(bool useMessageDatabase);
  void useSecretChatsChanged(bool useSecretChats);
  void useStorageOptimizerChanged(bool useStorageOptimizer);
  void apiIDChanged(qint32 apiID);
  void apiHashChanged(QString apiHash);
  void systemLanguageCodeChanged(QString systemLanguageCode);
  void deviceModelChanged(QString deviceModel);
  void systemVersionChanged(QString systemVersion);
  void applicationVersionChanged(QString applicationVersion);
  void databaseDirectoryChanged(QString databaseDirectory);
  void filesDirectoryChanged(QString filesDirectory);

private:
  bool mUseTestDc;
  bool mUseFileDatabase;
  bool mUseChatInfoDatabase;
  bool mUseMessageDatabase;
  bool mUseSecretChat;
  bool mUseStorageOptimizer;
  qint32 mApiId;
  QString mApiHash;
  QString mSystemLanguageCode;
  QString mDeviceModel;
  QString mSystemVersion;
  QString mApplicationVersion;
  QString mDatabaseDirectory;
  QString mFileDirectory;
};

#endif // QTDAUTHPARAM_HPP
