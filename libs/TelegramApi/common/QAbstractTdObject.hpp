#ifndef QTDOBJECT_HPP
#define QTDOBJECT_HPP

#include <QObject>

class QTdObject : public QObject
{
    Q_OBJECT
public:
    explicit QTdObject(QObject *parent = nullptr);

signals:

};

#endif // QTDOBJECT_HPP
