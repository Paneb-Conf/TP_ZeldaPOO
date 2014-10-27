#ifndef RUBIS_H
#define RUBIS_H
#include "morceaucarte.h"

class rubis:public morceauCarte
{
public:
    rubis();
    ~rubis();
    rubis(QGraphicsScene*);
    int type()const;
};

#endif // RUBIS_H
