#include "QTdDocument.hpp"

QTdDocument::QTdDocument(QObject *parent) : QTdObject(parent) {}

QString QTdDocument::fileName() const {}

QString QTdDocument::mimeType() const {}

QTdPhotoSize *QTdDocument::thumbnail() const {}

QTdFile *QTdDocument::document() const {}
