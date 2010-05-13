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

/* -*- Mode: C; indent-tabs-mode: s; c-basic-offset: 4; tab-width: 4 -*- */
/* vim:set et ai sw=4 ts=4 sts=4: tw=80 cino="(0,W2s,i2s,t0,l1,:0" */
#ifndef DCPBRIEFWIDGET_H
#define DCPBRIEFWIDGET_H

#include <MWidget>

class DcpAppletObject;
class DcpButton;
class DcpButtonImage;
class DcpButtonToggle;
class QShowEvent;
class QHideEvent;
class DcpBriefWidgetPrivate;

/*!
 * \brief An activatable entry in the control panel.
 * 
 * The #DcpBriefWidget is an activatable widget in the control panel. It
 * usually has a #DcpAppletObject associated with it, so when the user clicks
 * on the widget the applet variant is activated. The widget connects its
 * clicked() signal to the activate() signal of the #DcpAppletObject object,
 * so the applet variant will be started when the widget is clicked.
 *
 * This class implements the connection between the brief shown on the screen
 * and the applet describing the applet variant.
 *
 * Inside the #DcpBriefWidget there is a #DcpButton, a #DcpButtonImage or a 
 * #DcpButtonToggle as an actual widget.
 *
 * THIS CLASS IS DEPRECATED. Please use #DcpContentItem instead, that works
 * the same.
 */

#ifdef DCP_DISABLE_DEPRECATION_WARNING
class DcpBriefWidget:
#else
class Q_DECL_DEPRECATED DcpBriefWidget:
#endif
    public MWidget
{
    Q_OBJECT

public:
    DcpBriefWidget (
            DcpAppletObject *applet, 
            MWidget         *parent = 0);

    DcpBriefWidget (
            int               widgetTypeId,
            const QString    &line1,
            const QString    &line2,
            MWidget        *parent = 0);

    ~DcpBriefWidget();


    void setApplet (DcpAppletObject *applet);
    DcpAppletObject *applet () const;

public slots:
    void updateContents();

signals:
    void clicked();

protected:
    virtual void retranslateUi();
    virtual void showEvent (QShowEvent *event);
    virtual void hideEvent (QHideEvent *event);

    virtual void constructRealWidget (int widgetTypeId);
    DcpButtonImage *constructImage (const DcpAppletObject* applet);
    DcpButtonToggle *constructToggle (const DcpAppletObject* applet);

private:
    DcpBriefWidgetPrivate* const d_ptr;
};


#endif 
