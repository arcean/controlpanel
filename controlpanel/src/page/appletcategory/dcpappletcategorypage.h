#ifndef DCPAPPLETCATEGORYPAGE_H
#define DCPAPPLETCATEGORYPAGE_H

#include <DcpCategoryPage>
#include <Pages>

class DcpAppletMetadata;
class DcpAppletCategoryPage : public DcpCategoryPage
{
    Q_OBJECT

public:
    DcpAppletCategoryPage(const QString &appletCategory = QString());
    virtual ~DcpAppletCategoryPage();
    virtual void createContent();
    const QString appletCategory() const {return m_AppletCategory;};
    void setAppletCategory(const QString &appletCategory){m_AppletCategory=appletCategory;};
    virtual void reload();
    void cleanup();
public slots:
    virtual void back();
protected:
    void addComponent(DcpAppletMetadata *metadata, bool odd);
    void loadContent();
private:
    QString m_AppletCategory;
    QString m_LoadedAppletCategory; // the appletcategory that has already been
                                    // loaded. same as m_AppletCategory if the
                                    // page's content is loaded
};

#endif // DCPAPPLETCATEGORYPAGE_H
