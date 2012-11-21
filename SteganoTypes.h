#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QImage>
#include <QWidget>
#include <QVariant>


class CSteganoMethod;
class CSteganoWidget;
typedef QSharedPointer<QByteArray> PByteArray;
typedef QList<QVariant> ArgsList;
typedef QSharedPointer<ArgsList> PArgsList;
typedef QSharedPointer<QImage> PImage;
typedef QSharedPointer<CSteganoMethod> PSteganoMethod;
typedef QSharedPointer<CSteganoWidget> PSteganoWidget;
typedef QSharedPointer< QList< std::pair<int,QString> > > PMethodList;
