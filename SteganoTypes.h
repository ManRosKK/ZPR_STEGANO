#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QImage>
#include <QWidget>
#include <QVariant>

typedef QSharedPointer<QByteArray> PByteArray;
typedef QList<QVariant> ArgsList;
typedef QSharedPointer<ArgsList> PArgsList;
typedef QSharedPointer<QImage> PImage;
typedef QSharedPointer< QList< std::pair<int,QString> > > PMethodList;
typedef QSharedPointer<QVector<unsigned int> > PVectorInt;
typedef QSharedPointer<QBitArray> PBitArray;

