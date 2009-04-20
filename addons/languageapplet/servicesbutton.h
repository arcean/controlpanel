#ifndef SERVICESBUTTON_H
#define SERVICESBUTTON_H

#include <DuiButton>

class DuiLayout;
class DuiLabel;
class QPixmap;

class ServicesButton : public DuiButton
{
    Q_OBJECT

public:
    ServicesButton(DuiWidget *parent = 0, const QString &title = "");
    virtual ~ServicesButton();

    //! reimp
    virtual void resizeEvent(QGraphicsSceneResizeEvent *event);
    virtual void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
    //! reimp_end

private:
    DuiLayout       *m_mainLayout;
    const QPixmap   *m_background;
    DuiLabel        *m_label;
};
#endif // SERVICESBUTTON_H
