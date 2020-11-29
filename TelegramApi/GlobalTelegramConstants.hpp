#ifndef GLOBALTELEGRAMCONSTANTS_HPP
#define GLOBALTELEGRAMCONSTANTS_HPP
#include <QString>
namespace SustTelegram {
inline const QString apiId = "1551810";
inline const QString apiHash = "8b64a6f8133bc1c9f25382d5f955c679";
#define TEST_SERVER_ENABLED
inline const QString serverIp =
#if defined(TEST_SERVER_ENABLED)
    "149.154.167.40:443";
#else
    "149.154.167.50:443"
#endif
} // namespace SustTelegram
#endif // GLOBALTELEGRAMCONSTANTS_HPP
