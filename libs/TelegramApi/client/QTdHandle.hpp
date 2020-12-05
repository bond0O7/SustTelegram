#ifndef QTDHANDLE_HPP
#define QTDHANDLE_HPP

#include <QSharedPointer>

class Handle {
  void *mHandle;

public:
  explicit Handle();
  void *handle();
};

struct QTdHandle {
  static QSharedPointer<Handle> instance();
};

#endif // QTDHANDLE_HPP
