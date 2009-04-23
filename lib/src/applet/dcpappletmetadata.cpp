#include <QDateTime>
#include "dcpappletmetadata.h"
#include "dcpapplet.h"
#include <duilocale.h>
#include <QDebug>
#include "dcpappletmetadata_p.h"
#include "dcpwidgettypes.h"
enum  {
    KeyCategory = 0,
    KeyOrder,
    KeyOnPicture,
    KeyOffPicture,
    KeyDisabledPicture,

    KeyWidgetType,
    KeyAlign,
    KeyToggle,
    KeySmallToggle,

    KeyText2,
    KeyImage,
    KeyButtonCSS,
    KeyLabel1CSS,
    KeyLabel2CSS,
    KeyUsage,
    KeyBinary,

    KeyName,
    KeyNameId,
    KeyNameCatalog,

    KeyValuePath,
    KeyCount,
};

const QString Keys[KeyCount] = {
    "DCP/Category",
    "DCP/Order",
    "DCP/OnPicture",
    "DCP/OffPicture",
    "DCP/DisabledPicture",

    "DCP/WidgetType",
    "DCP/Align",
    "DCP/Toggle",
    "DCP/SmallToggle",

    "DCP/Text2",
    "DCP/Image",
    "DCP/ButtonCSS",
    "DCP/Label1CSS",
    "DCP/Label2CSS",
    "DCP/Usage",
    "DUI/X-DUIApplet-Applet",

    "Desktop Entry/Name",
    "Desktop Entry/X-logical-id",
    "Desktop Entry/X-translation-catalog",
    "DCP/ValuePath"
};

DcpAppletMetadata::DcpAppletMetadata(const QString& filename) 
    : DuiDesktopEntry(filename), d (new DcpAppletMetadataPrivate)
{
   
}

DcpAppletMetadata::~DcpAppletMetadata()
{
}

bool
DcpAppletMetadata::isValid()
{
    return DuiDesktopEntry::isValid();
}

bool
DcpAppletMetadata::isModified()
{
    QFileInfo info(d->m_FileInfo.fileName());
    bool modified = info.lastModified() >  d->m_FileInfo.lastModified();
    d->m_FileInfo = info;
    return modified;
}

QString
DcpAppletMetadata::category() const
{
    return value(Keys[KeyCategory]).toString();
}

QString
DcpAppletMetadata::icon() const
{
    return "";
}

QString
DcpAppletMetadata::binary() const
{
    return value(Keys[KeyBinary]).toString();
}

QString
DcpAppletMetadata::fullBinary() const
{
    return DcpApplet::Lib + binary();
}

QString DcpAppletMetadata::widgetType()
{
    return value(Keys[KeyWidgetType]).toString();
}

int DcpAppletMetadata::widgetTypeID()
{
  QString type = value(Keys[KeyWidgetType]).toString();
  
  for(int i=0; i<WIDGETN; i++) 
    if (WIDGETNAME[i]==type)
      return i;
  
  return -1;  //error

}

Qt::Alignment DcpAppletMetadata::align()
{
  if (value(Keys[KeyAlign]).toString().toUpper() == "LEFT")
    return Qt::AlignLeft;

  return Qt::AlignRight;
}

bool DcpAppletMetadata::toggle()
{
  if (value(Keys[KeyToggle]).toString() == "TRUE")
    return true;

  return false;
}

bool DcpAppletMetadata::smallToggle()
{
  if (value(Keys[KeySmallToggle]).toString() == "TRUE")
    return true;

  return false;
}

QString DcpAppletMetadata::text1()
{
    QString id = value(Keys[KeyNameId]).toString();
    QString name = value(Keys[KeyName]).toString();
//    QString catalog = value(Keys[KeyNameCatalog]).toString();
    return DuiLocale::trid(qPrintable(id), qPrintable(name));
}

QString DcpAppletMetadata::text2()
{
    QString val = settingsValue();
    if (val.isEmpty())
        val = value(Keys[KeyText2]).toString();
    return val;
}

QString DcpAppletMetadata::image()
{
    return value(Keys[KeyImage]).toString();
}

QString DcpAppletMetadata::buttonCSS()
{
    return value(Keys[KeyButtonCSS]).toString();
}

QString DcpAppletMetadata::label1CSS()
{
    return value(Keys[KeyLabel1CSS]).toString();
}

QString DcpAppletMetadata::label2CSS()
{
    return value(Keys[KeyLabel2CSS]).toString();
}

int DcpAppletMetadata::usage()
{
    return value(Keys[KeyUsage]).toInt();
}


int DcpAppletMetadata::order()
{
    return value(Keys[KeyOrder]).toInt();
}

QString DcpAppletMetadata::settingsValue()
{
    QSettings settings("Maemo", "DuiControlPanel");
    QString val = "";
    QString confKey = "";
    QString key = Keys[KeyValuePath];
    if (contains(key))
     {
        confKey = value(key).toString();
        val = settings.value(confKey).toString();
     }
    qDebug() << "DCP" << key << confKey << val;
    return val;
}


