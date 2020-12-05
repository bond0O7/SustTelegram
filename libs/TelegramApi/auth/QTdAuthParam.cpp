#include "QTdAuthParam.hpp"
#include "../GlobalTelegramConstants.hpp"
#include <QLocale>
QTdAuthParam::QTdAuthParam(QObject *parent) : QTdObject(parent) {
  mSystemLanguageCode = QLocale().name();
  mDeviceModel = "Desktop";
  mSystemVersion = QSysInfo::productVersion();
  mApplicationVersion = qApp->applicationVersion();
  mDatabaseDirectory =
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
          .append("/database");
  mFileDirectory =
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
          .append("/files");
}

QString QTdAuthParam::fileDirectory() const { return mFileDirectory; }

void QTdAuthParam::setFileDirectory(const QString &fileDirectory) {
  if (mFileDirectory == fileDirectory) {
    return;
  }
  mFileDirectory = fileDirectory;
  emit filesDirectoryChanged(mFileDirectory);
}

bool QTdAuthParam::useTestDc() const { return mUseTestDc; }

void QTdAuthParam::setUseTestDc(bool useTestDc) {
  if (useTestDc == mUseTestDc) {
    return;
  }
  mUseTestDc = useTestDc;
  emit useTestDCChanged(mUseTestDc);
}

bool QTdAuthParam::useFileDatabase() const { return mUseFileDatabase; }

void QTdAuthParam::setUseFileDatabase(bool useFileDatabase) {
  if (mUseFileDatabase == useFileDatabase) {
    return;
  }
  mUseFileDatabase = useFileDatabase;
  emit useFileDatabaseChanged(mUseFileDatabase);
}

bool QTdAuthParam::useChatInfoDatabase() const { return mUseChatInfoDatabase; }

void QTdAuthParam::setUseChatInfoDatabase(bool useChatInfoDatabase) {
  if (mUseChatInfoDatabase == useChatInfoDatabase) {
    return;
  }
  mUseChatInfoDatabase = useChatInfoDatabase;
  emit useChatInfoDatabaseChanged(mUseChatInfoDatabase);
}

bool QTdAuthParam::useMessageDatabase() const { return mUseMessageDatabase; }

void QTdAuthParam::setUseMessageDatabase(bool useMessageDatabase) {
  if (mUseMessageDatabase == useMessageDatabase) {
    return;
  }
  mUseMessageDatabase = useMessageDatabase;
  emit useMessageDatabaseChanged(mUseMessageDatabase);
}

bool QTdAuthParam::useSecretChat() const { return mUseSecretChat; }

void QTdAuthParam::setUseSecretChat(bool useSecretChat) {
  if (mUseSecretChat == useSecretChat) {
    return;
  }
  mUseSecretChat = useSecretChat;
  emit useSecretChatsChanged(mUseSecretChat);
}

bool QTdAuthParam::useStorageOptimizer() const { return mUseStorageOptimizer; }

void QTdAuthParam::setUseStorageOptimizer(bool useStorageOptimizer) {
  if (mUseStorageOptimizer == useStorageOptimizer) {
    return;
  }
  mUseStorageOptimizer = useStorageOptimizer;
  emit useStorageOptimizerChanged(mUseStorageOptimizer);
}

qint32 QTdAuthParam::apiId() const { return mApiId; }

void QTdAuthParam::setApiId(const qint32 apiId) {
  if (mApiId == apiId) {
    return;
  }
  mApiId = apiId;
  emit apiIDChanged(mApiId);
}

QString QTdAuthParam::apiHash() const { return mApiHash; }

void QTdAuthParam::setApiHash(const QString &apiHash) {
  if (mApiHash == apiHash) {
    return;
  }
  mApiHash = apiHash;
  emit apiHashChanged(mApiHash);
}

QString QTdAuthParam::systemLanguageCode() const { return mSystemLanguageCode; }

void QTdAuthParam::setSystemLanguageCode(const QString &systemLanguageCode) {
  if (mSystemLanguageCode == systemLanguageCode) {
    return;
  }
  mSystemLanguageCode = systemLanguageCode;
  emit systemLanguageCodeChanged(mSystemLanguageCode);
}

QString QTdAuthParam::deviceModel() const { return mDeviceModel; }

void QTdAuthParam::setDeviceModel(const QString &deviceModel) {
  if (mDeviceModel == deviceModel) {
    return;
  }
  mDeviceModel = deviceModel;
  emit deviceModelChanged(mDeviceModel);
}

QString QTdAuthParam::systemVersion() const { return mSystemVersion; }

void QTdAuthParam::setSystemVersion(const QString &systemVersion) {
  if (mSystemVersion == systemVersion) {
    return;
  }
  mSystemVersion = systemVersion;
  emit systemVersionChanged(mSystemVersion);
}

QString QTdAuthParam::applicationVersion() const { return mApplicationVersion; }

void QTdAuthParam::setApplicationVersion(const QString &applicationVersion) {
  if (mApplicationVersion == applicationVersion) {
    return;
  }
  mApplicationVersion = applicationVersion;
  emit applicationVersionChanged(mApplicationVersion);
}

QString QTdAuthParam::databaseDirectory() const { return mDatabaseDirectory; }

void QTdAuthParam::setDatabaseDirectory(const QString &databaseDirectory) {
  if (mDatabaseDirectory == databaseDirectory) {
    return;
  }
  mDatabaseDirectory = databaseDirectory;
  emit databaseDirectoryChanged(mDatabaseDirectory);
}

QJsonObject QTdAuthParam::marshallJson() {
  return QJsonObject{{"use_test_dc", mUseTestDc},
                     {"use_file_database", mUseFileDatabase},
                     {"use_chat_info_database", mUseChatInfoDatabase},
                     {"use_message_database", mUseMessageDatabase},
                     {"use_secret_chats", mUseSecretChat},
                     {"api_id", mApiId},
                     {"api_hash", mApiHash},
                     {"system_language_code", mSystemLanguageCode},
                     {"device_model", mDeviceModel},
                     {"system_version", mSystemVersion},
                     {"application_version", mApplicationVersion},
                     {"enable_storage_optimizer", mUseStorageOptimizer},
                     {"database_directory", mDatabaseDirectory},
                     {"files_directory", mFileDirectory}};
}
