#ifndef DATETIMEBRIEF_H
#define DATETIMEBRIEF_H

#include "dcpbrief.h"

class DateTimeBrief: public DcpBrief{
    Q_OBJECT
public:
    DateTimeBrief();
    virtual QString valueText() const;

};


#endif // DATETIMEBRIEF_H
