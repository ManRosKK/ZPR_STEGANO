#pragma once
#include <QSharedPointer>
#include <QImage>
#include <QWidget>
#include "SteganoMethod.h"
#include "SteganoWidget.h"

typedef QSharedPointer<QByteArray> PByteArray;
typedef QList<QVariant> ArgsList;
typedef QSharedPointer<ArgsList> PArgsList;
typedef QSharedPointer<QImage> PImage;
