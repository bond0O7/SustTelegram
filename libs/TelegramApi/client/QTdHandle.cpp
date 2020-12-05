#include "QTdHandle.hpp"
#include <QDebug>
#include <td/telegram/td_json_client.h>
#include <td/telegram/td_log.h>

static void deleteHandle(Handle *handle) {
  qWarning() << "Destroying Handle";
  td_json_client_destroy(handle->handle());
  delete handle;
  handle = nullptr;
}

static QWeakPointer<Handle> sHandle;

QSharedPointer<Handle> QTdHandle::instance() {
  auto handle = sHandle.toStrongRef();
  if (handle.isNull()) {
    handle = QSharedPointer<Handle>(new Handle, deleteHandle);
    sHandle = handle;
  }
  return sHandle.toStrongRef();
}

Handle::Handle() : mHandle(nullptr) {
  mHandle = td_json_client_create();
  td_json_client_execute(
      nullptr,
      "{\"@type\":\"setLogVerbosityLevel\", \"new_verbosity_level\":2}");
}

void *Handle::handle() { return mHandle; }
