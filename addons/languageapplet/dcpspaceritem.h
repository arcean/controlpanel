#ifndef DCPSPACERITEM_H
#define DCPSPACERITEM_H

#include <DuiWidget>

class DcpSpacerItem : public DuiWidget
{
public:
    DcpSpacerItem(DuiWidget *parent, int width, int height, 
                  QSizePolicy::Policy hPolicy = QSizePolicy::Minimum,
                  QSizePolicy::Policy vPolicy = QSizePolicy::Minimum);
    ~DcpSpacerItem();

    void changeSize(int width, int height,
                    QSizePolicy::Policy hPolicy = QSizePolicy::Minimum,
                    QSizePolicy::Policy vPolicy = QSizePolicy::Minimum);
};
#endif // DCPSPACERITEM_H