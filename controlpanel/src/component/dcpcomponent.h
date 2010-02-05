#ifndef DCPCOMPONENT_H
#define DCPCOMPONENT_H

#include <DuiWidget>
#include <Pages>

// FIXME: what the hell?
class DcpComponent;

class DcpComponent : public DuiWidget
{
    Q_OBJECT

public:
    explicit DcpComponent(DcpComponent *category,
                                  const QString& title="",
                                  QGraphicsWidget *parent=0,
                                  const QString& logicalId="");

    QString title() const {return m_Title;}
    virtual void setTitle(const QString& title) {m_Title = title;}
    void setSubPage (const PageHandle &subPage) {m_SubPage = subPage;}
    void setSubPage (const PageHandle::PageTypeId id, const QString &param="", 
                     const int widgetId=-1, const bool isStandalone=false)
        { m_SubPage.id = id; m_SubPage.param = param; 
          m_SubPage.widgetId = widgetId; m_SubPage.isStandalone = isStandalone; }
    const PageHandle &subPage() const { return m_SubPage; }
    // Composite Pattern Interface
    //virtual void add(DcpComponent *component) = 0;
    //virtual void remove(DcpComponent *component) = 0;

    virtual DcpComponent* child(int i) const;
    DcpComponent* category() const { return m_Category; }
    
    virtual const QString logicalId() { return m_LogicalId; }
    void setLogicalId(const QString& logicalId) { m_LogicalId = logicalId; }

protected:
    virtual void createContents() = 0;

private:
    QString m_Title;
    QString m_LogicalId;
    DcpComponent* m_Category;
    PageHandle m_SubPage;
};
#endif //DCPCOMPONENT_H
