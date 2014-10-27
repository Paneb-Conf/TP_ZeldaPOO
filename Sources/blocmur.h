#ifndef BLOCMUR_H
#define BLOCMUR_H
/* Inclusion de la classe mère de tous nos objet de carte */
#include "morceaucarte.h"

class blocMur:public morceauCarte

{
public:
    blocMur();
    ~blocMur();
    /* Constructeur particulier pour afficher l'icone adéquate */
    blocMur(QGraphicsScene*);
};

#endif // BLOCMUR_H
