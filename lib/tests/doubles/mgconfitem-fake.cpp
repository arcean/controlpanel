/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Karoliina T. Salminen <karoliina.t.salminen@nokia.com>
**
** This file is part of duicontrolpanel.
**
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include <MGConfItem>
#include <QMap>

static QMap<QString, QVariant> database;

struct MGConfItemFake {
    MGConfItemFake(const QString &key_) : key(key_) {}
    QString key;
};

static QMap<const MGConfItem*, MGConfItemFake*> fakeMap;
#define FAKE fakeMap[this]


MGConfItem::MGConfItem(const QString &key, QObject *parent)
{
    Q_UNUSED(parent);
    fakeMap.insert(this, new MGConfItemFake(key));
}

MGConfItem::~MGConfItem()
{
    delete fakeMap.take(this);
}

QVariant MGConfItem::value() const
{
    return value(QVariant());
}

QVariant MGConfItem::value(const QVariant &def) const
{
    const QVariant& item = database[FAKE->key];
    if (item != QVariant::Invalid)
        return item;
    else
        return def;
}

void MGConfItem::set(const QVariant &val)
{
    database[FAKE->key] = val;
}


void MGConfItem::unset()
{
    set (QVariant());
}

QList<QString> MGConfItem::listDirs() const
{
    QList<QString> dummy;
    return dummy;
}

QList<QString> MGConfItem::listEntries() const
{
    QList<QString> dummy;
    return dummy;
}

