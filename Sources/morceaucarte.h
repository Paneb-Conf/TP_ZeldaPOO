#ifndef MORCEAUCARTE_H
#define MORCEAUCARTE_H
#include "elementgraphique.h"

class morceauCarte: public ElementGraphique
{
public:
    morceauCarte();
    ~morceauCarte();
    /* Redéfinition du type pour différencier des autres items*/
    int type() const;
};

#endif // MORCEAUCARTE_H
