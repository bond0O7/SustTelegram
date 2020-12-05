#ifndef PHONENUMBERAUTHORIZATION_HPP
#define PHONENUMBERAUTHORIZATION_HPP

#include <QObject>

class PhoneNumberAuthorization : public Authorizer
{
    Q_OBJECT
public:
    PhoneNumberAuthorization();
};

#endif // PHONENUMBERAUTHORIZATION_HPP
