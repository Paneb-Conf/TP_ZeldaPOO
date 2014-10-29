#ifndef FLECHE_H
#define FLECHE_H
#include "elementgraphique.h"
class Fleche: public ElementGraphique
{
public:
    Fleche();
    ~Fleche();
    /* Constructeur scène + position de Zelda */
    Fleche(QGraphicsScene*, QPointF, int);


    int type() const;
    void advance(int);
    int mouvementOk();
    void miseAjourIcone(int);


};

#endif // FLECHE_H
