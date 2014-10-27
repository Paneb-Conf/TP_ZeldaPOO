#ifndef COEUR_H
#define COEUR_H
#include "morceaucarte.h"

class Coeur: public morceauCarte
{
public:
    Coeur();
    ~Coeur();
    Coeur(QGraphicsScene*);

    int type() const;

    void setUtilise(int);
    int getUtilise();

private:
    int _utilise;
};

#endif // COEUR_H
