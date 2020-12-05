#ifndef GLOBALTELEGRAMCONSTANTS_HPP
#define GLOBALTELEGRAMCONSTANTS_HPP
#include <QApplication>
#include <QLocale>
#include <QStandardPaths>
#include <QString>
#include <td/telegram/Client.h>
#include <td/telegram/td_api.hpp>

namespace SustTelegram {
#define TEST_SERVER_ENABLED
inline const QString serverIp =
#if defined(TEST_SERVER_ENABLED)
    "149.154.167.40:443";
bool useTestDcServer = false;
#else
    "149.154.167.50:443";
bool useTestDcServer = true;
#endif

inline constexpr quint32 apiId = 1551810;
inline const QString apiHash = "8b64a6f8133bc1c9f25382d5f955c679";
inline const QString globalPath =
    QStandardPaths::locate(QStandardPaths::HomeLocation, "SustTelegram",
                           QStandardPaths::LocateDirectory);
inline td::Client globalApplicationClient;
inline constexpr double responseTimeOut = 20.0;
inline const td::td_api::tdlibParameters
    globalParameters(useTestDcServer, globalPath.toStdString(),
                     globalPath.toStdString(), true, true, true, false, apiId,
                     apiHash.toStdString(), QLocale().name().toStdString(),
                     "Desktop", QSysInfo::productVersion().toStdString(),
                     qApp->applicationVersion().toStdString(), true, true);
using Request = td::Client::Request;

using Response = td::Client::Response;
namespace HttpProtocol {
namespace Author {
inline constexpr std::uint32_t PhoneNumberAuthorId = 1;
}
namespace RequestAndResponse {
inline constexpr std::uint32_t PhoneNumberRequestId =
    Author::PhoneNumberAuthorId + 10000;
inline constexpr std::uint32_t registerUserRequestId = PhoneNumberRequestId + 1;

} // namespace RequestAndResponse
} // namespace HttpProtocol
} // namespace SustTelegram
#endif // GLOBALTELEGRAMCONSTANTS_HPP
