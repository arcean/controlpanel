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


#include "dcpskeletonwidget.h"
#include <mlayout.h>
#include <mlinearlayoutpolicy.h>
#include <mlabel.h>
#include <mbutton.h>
#include <mwidgetcreator.h>

M_REGISTER_WIDGET_NO_CREATE (SkeletonWidget)

SkeletonWidget::SkeletonWidget (int num, QGraphicsWidget *parent)
	    :DcpStylableWidget(parent)
{
    MLayout *mainLayout = new MLayout(this);
    MLinearLayoutPolicy *mainLayoutPolicy =
            new MLinearLayoutPolicy (mainLayout, Qt::Vertical);
    mainLayout->setPolicy(mainLayoutPolicy);
    mainLayout->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);

    MLabel * label = new MLabel(QString("Page %1").arg(num), this);
    label->setStyleName ("CommonSingleTitleInverted");
    mainLayoutPolicy->addItem(label);

    m_PreventQuitToggle = new MButton("Prevent page close");
    m_PreventQuitToggle->setViewType(MButton::toggleType);
    m_PreventQuitToggle->setCheckable(true);
    mainLayoutPolicy->addItem(m_PreventQuitToggle);

    mainLayoutPolicy->addStretch();

    for (int i=0; i<5; i++) {
        mainLayoutPolicy->addItem(
            createButton (QString::number(i), SLOT (onPageOpenRequest())));
    }

    mainLayoutPolicy->addStretch();
    mainLayoutPolicy->addItem(createButton ("Close page", SIGNAL (closePage())));
    setLayout(mainLayout);
}

MButton* SkeletonWidget::createButton (const QString& title, const char* method) {
    MButton* result = new MButton(title);
    connect (result, SIGNAL(clicked()), this, method);
    return result;
}

void SkeletonWidget::onPageOpenRequest ()
{
    MButton* button = qobject_cast<MButton*>(sender());
    if (!button) return;

    int num = button->text().toInt();
    emit changeWidget (num);
}

SkeletonWidget::~SkeletonWidget()
{
}

bool SkeletonWidget::back()
{
    qDebug ("BACK was asked from me: %d", !m_PreventQuitToggle->isChecked());
    return ! m_PreventQuitToggle->isChecked();
}
