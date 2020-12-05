#ifndef QTDTHREAD_HPP
#define QTDTHREAD_HPP

#include "QTdHandle.hpp"
#include <QSharedPointer>

class QTdWorker : public QObject {
  Q_DISABLE_COPY(QTdWorker)
  Q_OBJECT
public:
  explicit QTdWorker(QObject *parent = nullptr);
  ~QTdWorker();

signals:
  void recv(const QJsonObject &data);

public slots:
  void run();

private:
  QSharedPointer<Handle> mTdlib;
};

#endif // QTDTHREAD_HPP
