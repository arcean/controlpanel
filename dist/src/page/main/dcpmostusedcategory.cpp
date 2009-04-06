#include "pages.h"

#include <QtDebug>

#include "dcpappletdb.h"
#include "dcpmaincategory.h"
#include "dcprecentlyusedcomponent.h"

#include "dcplabelcomponent.h"
#include "dcplabel2component.h"
#include "dcplabel2buttoncomponent.h"
#include "dcplabel2imagecomponent.h"
#include "dcplabelbuttoncomponent.h"

#include "dcpmostusedcategory.h"

#include "dcpappletmetadata.h"
#include "dcpapplet.h"


DcpMostUsedCategory::DcpMostUsedCategory(const QString& title, QGraphicsWidget *parent) :
  DcpMainCategory(title, parent)
{
  createContents();

    m_LandscapeLayout->setColumnSpacing(0, 110); //dummy

    setContentsMargins(0, 10, 0, 10);

   //m_Background = new QPixmap("images/backgroundP.png");

}

void DcpMostUsedCategory::createContents()
{
    setMaxColumns(2);

    //dummy code
  /*  addComponent(DcpAppletDb::instance()->applet("Browser"));
    addComponent(DcpAppletDb::instance()->applet("Wallpaper"));
    addComponent(DcpAppletDb::instance()->applet("Positioning"));
    addComponent(DcpAppletDb::instance()->applet("Display"));
    addComponent(DcpAppletDb::instance()->applet("DateTime"));
    addComponent(DcpAppletDb::instance()->applet("Passcode"));*/

    foreach (DcpAppletMetadata *item, DcpAppletDb::instance()->listMostUsed()) {
         addComponent(item);
    }

}

void DcpMostUsedCategory::paint (QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
  DuiWidget::paint(painter, option, widget);
}

void DcpMostUsedCategory::addComponent(DcpAppletMetadata *metadata)
{

  DcpComponent *component = 0;

  switch (metadata->widgetTypeID()) {
      case DCPLABEL :
          component = new DcpLabelComponent(this, metadata);
      break;
      case DCPLABEL2 :
          component = new DcpLabel2Component(this, metadata);
      break;
      case DCPLABELBUTTON :
          component = new DcpLabelButtonComponent(this, metadata);
      break;
      case DCPLABEL2BUTTON :
          component = new DcpLabel2ButtonComponent(this, metadata);
      break;
      case DCPLABEL2IMAGE :
          component = new DcpLabel2ImageComponent(this, metadata);
      break;
  }


    if (component) {
        qDebug() << "DCP: connecting to " << metadata->name();
        component->setSubPage(Pages::APPLETFROMMOSTUSED, metadata->name());
        connect(component, SIGNAL(openSubPage(Pages::Handle)),                  
                this, SIGNAL(openSubPage(Pages::Handle)));
        append(component);
    }
}
