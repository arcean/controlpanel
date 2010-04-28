#include "dcpbriefcomponent.h"
#include "dcpappletmetadata.h"
#include "dcpappletobject.h"

DcpBriefComponent::DcpBriefComponent (
        DcpAppletObject   *applet,
        DcpComponent        *category,
        const QString       &logicalId)
: DcpComponent (category, applet->metadata()->name(), 0, logicalId)
{
    Q_UNUSED(category);
    Q_UNUSED(logicalId);
}


DcpBriefComponent::~DcpBriefComponent()
{
}


void
DcpBriefComponent::setApplet(
        DcpAppletObject* applet)
{
    Q_UNUSED(applet);
}


