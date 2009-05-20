#include <QtGui>
#include <QDebug>
#include "datetimeapplet.h"
#include "datetimewidget.h"
#include "dcpwidget.h"
#include "duilocale.h"
#include <DuiAction>
#include "datetimebrief.h"

namespace {
    const QString AppletTitle = trid("qn_datetime", "Date & Time");
};
Q_EXPORT_PLUGIN2(displayapplet, DateTimeApplet)

void DateTimeApplet::init()
{
};

DcpWidget* DateTimeApplet::constructWidget(int widgetId)
{
    Q_UNUSED(widgetId);
    return new DateTimeWidget();
}

QString DateTimeApplet::title() const
{
        return AppletTitle;
}

QVector<DuiAction*> DateTimeApplet::viewMenuItems()
{
    QVector<DuiAction*> vector;
    return vector;
}

DcpBrief* DateTimeApplet::constructBrief()
{
    return new DateTimeBrief();
}
