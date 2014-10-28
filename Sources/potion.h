#ifndef POTION_H
#define POTION_H
#include "morceaucarte.h"
class Potion: public morceauCarte
{
public:
    Potion();
    ~Potion();
    Potion(QGraphicsScene*);

    int type() const;

    void setUtilise(int);
    int getUtilise();

private:
    int _utilise;
};

#endif // POTION_H
