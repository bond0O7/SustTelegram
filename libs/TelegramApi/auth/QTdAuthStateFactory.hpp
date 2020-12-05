#ifndef QAUTHSTATEFACTORY_HPP
#define QAUTHSTATEFACTORY_HPP

#include <QJsonObject>
#include <QObject>

class QTdAuthState;
class QAuthStateFactory {
public:
  static QTdAuthState *create(const QJsonObject &json,
                              QObject *parent = nullptr);
};

#endif // QAUTHSTATEFACTORY_HPP
