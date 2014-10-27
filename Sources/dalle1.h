#ifndef DALLE1_H
#define DALLE1_H
#include "morceaucarte.h"
class Dalle1: public morceauCarte
{
public:
    Dalle1();
    Dalle1(QGraphicsScene*);

    int type() const;
    ~Dalle1();
};

#endif // DALLE1_H
