/* -*- Mode: C; indent-tabs-mode: s; c-basic-offset: 4; tab-width: 4 -*- */
/* vim:set et ai sw=4 ts=4 sts=4: tw=80 cino="(0,W2s,i2s,t0,l1,:0" */

#define DEBUG
#include "../../../lib/src/dcpdebug.h"

#include "pages.h"

PageHandle::PageHandle (
        PageTypeId      pageType, 
        const QString  &name,
        int             widgetId):
    id (pageType),
    param (name),
    m_widgetId (widgetId)
{
}


QString
PageHandle::getStringVariant () const
{
    const char *typeName = "Unknown";

    switch (id) {
        case NOPAGE:
            typeName = "NOPAGE";
            break;

        case MAIN:
            typeName = "MAIN";
            break;

        case CATEGORY_PAGEID_START:
            typeName = "CATEGORY_PAGEID_START";
            break;

        case LOOKANDFEEL:
            typeName = "LOOKANDFEEL";
            break;

        case CONNECTIVITY:
            typeName = "CONNECTIVITY";
            break;

        case SOUND:
            typeName = "SOUND";
            break;

        case REGIONALSETTING:
            typeName = "REGIONALSETTING";
            break;

        case DEVICEUTILITIES:
            typeName = "DEVICEUTILITIES";
            break;

        case ACCOUNTSANDAPPLICATIONS:
            typeName = "ACCOUNTSANDAPPLICATIONS";
            break;

        case DEVICESYSTEM:
            typeName = "DEVICESYSTEM";
            break;

        case CATEGORY_PAGEID_END:
            typeName = "CATEGORY_PAGEID_END";
            break;

        case APPLET:
            typeName = "APPLET";
            break;

        case APPLETCATEGORY:
            typeName = "APPLETCATEGORY";
            break;

        case PAGEID_COUNT:
            typeName = "PAGEID_COUNT";
            break;
    }

    return QString (typeName) + "://" 
        + param + "/" 
        + QString::number (m_widgetId);
}