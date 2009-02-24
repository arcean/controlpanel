#include "mainwindow.h"

#include <DuiApplication>
#include <DuiLocale>
#include <QtDebug>
#include <duitheme.h>


int main(int argc, char *argv[])
{
    DuiApplication app(argc, argv);

    DuiTheme::loadCSS("duicontrolpanel.css");
    
    DuiLocale locale;                                                           
    locale.addTranslationPath("./ts");                                          
    locale.installCategoryCatalog(DuiLocale::DuiLcMessages, "duicontrolpanel"); 
    qDebug() << trid("dcp_test", "Teesttt");
    MainWindow win;
    win.show();

    return app.exec();
}