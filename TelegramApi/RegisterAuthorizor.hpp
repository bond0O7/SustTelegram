#ifndef SIGNUPAUTHORIZOR_HPP
#define SIGNUPAUTHORIZOR_HPP

#include <QObject>

class SignUpAuthorizor : public QObject
{
    Q_OBJECT
public:
    explicit SignUpAuthorizor(QObject *parent = nullptr);

signals:

};

#endif // SIGNUPAUTHORIZOR_HPP
