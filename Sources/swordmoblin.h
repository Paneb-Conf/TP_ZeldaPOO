#ifndef SWORDMOBLIN_H
#define SWORDMOBLIN_H
#include "creatures.h"

class SwordMoblin:public Creatures
{
public:
    SwordMoblin();
    SwordMoblin(QGraphicsScene*);
    ~SwordMoblin();

    void miseAjourIcone(int);
};

#endif // SWORDMOBLIN_H
