#ifndef LAMPEPIEDESTAL_H
#define LAMPEPIEDESTAL_H
#include "morceaucarte.h"
class LampePiedestal: public morceauCarte
{
public:
    LampePiedestal();
    ~LampePiedestal();
    LampePiedestal(QGraphicsScene*);
    int type() const;
    void advance(int phase);
    void miseAjourIcone();
};

#endif // LAMPEPIEDESTAL_H
