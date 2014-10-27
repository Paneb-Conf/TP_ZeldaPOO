#ifndef ELEMENTGRAPHIQUE_H
#define ELEMENTGRAPHIQUE_H

#include <QGraphicsPixmapItem>
#include <QtGui>
#include <QGraphicsScene>
#include <iostream>
#include <QFile>
/* Inclusion utiles pour les paramètrages des types et autres par la suite */
#include "constantes.h"


using namespace std;
class ElementGraphique: public QGraphicsPixmapItem
{
public:
    ElementGraphique();
    ~ElementGraphique();
    /* Fonction utile pour les classes filles (polymorphisme) */
    ElementGraphique(QGraphicsScene*);
    virtual int type() const;
    virtual void miseAjourIcone(int);
    int getCap();
    void setCap(int);


    /* Setter et getter */
    QPixmap getImage();
    void    setImage(string);
    int getNumeroIcone();
    void setNumeroIcone(int);

    /* Fonction de mouvement */
    void moveTop();
    void moveBot();
    void moveLeft();
    void moveRight();
    virtual void advance();
    virtual int mouvementOk();
private:
    /* Notre variable où sera stocké l'icone à afficher selon l'élément */
    QPixmap _image;
    int _numeroIcone;
    int _cap;
};

#endif // ELEMENTGRAPHIQUE_H
