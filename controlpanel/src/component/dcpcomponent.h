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

#ifndef DCPCOMPONENT_H
#define DCPCOMPONENT_H

#include <MWidget>
#include <Pages>

class DcpComponent : public MWidget
{
    Q_OBJECT
    Q_PROPERTY (QString mattiID READ mattiID WRITE setMattiID)

public:
    explicit DcpComponent(DcpComponent *category,
                                  const QString& title="",
                                  QGraphicsWidget *parent=0,
                                  const QString& logicalId="");

    virtual QString title() const {return m_Title;}
    virtual void setTitle(const QString& title) {m_Title = title;}
    void setSubPage (const PageHandle &subPage) {m_SubPage = subPage;}
    void setSubPage (const PageHandle::PageTypeId id, const QString &param="", 
                     const int widgetId=-1, const bool isStandalone=false)
        { m_SubPage.id = id; m_SubPage.param = param; 
          m_SubPage.widgetId = widgetId; m_SubPage.isStandalone = isStandalone; }
    const PageHandle &subPage() const { return m_SubPage; }

    DcpComponent* category() const { return m_Category; }
    
    virtual const QString logicalId() { return m_LogicalId; }
    void setLogicalId(const QString& logicalId) { m_LogicalId = logicalId; }

    QString mattiID() const;
    void setMattiID(const QString &mattiID);

private:
    QString m_Title;
    QString m_LogicalId;
    QString m_MattiID;
    DcpComponent* m_Category;
    PageHandle m_SubPage;
};
#endif //DCPCOMPONENT_H
