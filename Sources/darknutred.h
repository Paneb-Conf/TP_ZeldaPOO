#ifndef DARKNUTRED_H
#define DARKNUTRED_H
#include "creatures.h"
class DarknutRed:public Creatures
{
public:
    DarknutRed();
    DarknutRed(QGraphicsScene*);
    ~DarknutRed();
    void miseAjourIcone(int);
};

#endif // DARKNUTRED_H
