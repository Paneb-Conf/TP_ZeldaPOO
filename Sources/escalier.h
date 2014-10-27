#ifndef ESCALIER_H
#define ESCALIER_H
#include "morceaucarte.h"
class Escalier: public morceauCarte
{
public:
    Escalier();
    ~Escalier();
    /* Constructeur particulier pour afficher l'icone adéquate */
    Escalier(QGraphicsScene*);
     int type()const;
};

#endif // ESCALIER_H
