/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Karoliina T. Salminen <karoliina.t.salminen@nokia.com>
**
** This file is part of duicontrolpanel.
**
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include <QObject>
#include <QGraphicsSceneMouseEvent>

#include <dcpmaincategory.h>


#include "ut_dcpmaincategory.h"
#include <DcpComponent>

void Ut_DcpMainCategory::init()
{
    m_subject = new DcpMainCategory();
}

void Ut_DcpMainCategory::cleanup()
{
    delete m_subject;
    m_subject = 0;
}

void Ut_DcpMainCategory::initTestCase()
{
}

void Ut_DcpMainCategory::cleanupTestCase()
{
}
void Ut_DcpMainCategory::testCreation()
{
    QVERIFY(m_subject->layout() != 0);
}

void Ut_DcpMainCategory::testAppendWidget() 
{
    DcpComponent *component1 = new DcpComponent(0, "test");
    QGraphicsLayoutItem *item1 = 0;
    m_subject->appendWidget(component1);
    item1 = m_subject->layout()->itemAt(0);
    QCOMPARE((void*)component1, (void*)(QGraphicsWidget*)item1);
    delete component1;
}

void Ut_DcpMainCategory::testGetItemCount() 
{
    QCOMPARE(m_subject->getItemCount(), 0);

    DcpComponent* component1 = new DcpComponent(0, "test");
    DcpComponent* component2 = new DcpComponent(0, "test");
    DcpComponent* component3 = new DcpComponent(0, "test");
    m_subject->appendWidget(component1);
    QCOMPARE(m_subject->getItemCount(), 1);

    m_subject->appendWidget(component2);
    QCOMPARE(m_subject->getItemCount(), 3);

    m_subject->appendWidget(component3);
    QCOMPARE(m_subject->getItemCount(), 5);

    delete component1;
    delete component2;
    delete component3;
}

void Ut_DcpMainCategory::testMLayout()
{
    QVERIFY(m_subject->mLayout());
    QCOMPARE((void*)m_subject->mLayout(), (void*)m_subject->layout());
}

void Ut_DcpMainCategory::testDeleteItems() 
{
    DcpComponent *component1 = new DcpComponent(0, "test1");
    m_subject->appendWidget(component1);
    DcpComponent *component2 = new DcpComponent(0, "test2");
    m_subject->appendWidget(component2);
    QVERIFY(m_subject->layout()->count() != 0); 
    m_subject->deleteItems();
    QCOMPARE(m_subject->layout()->count(), 0);
}

QTEST_APPLESS_MAIN(Ut_DcpMainCategory)
