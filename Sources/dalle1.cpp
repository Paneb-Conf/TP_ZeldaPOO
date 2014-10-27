#include "dalle1.h"

Dalle1::Dalle1()
{
}

Dalle1::~Dalle1()
{
}

Dalle1::Dalle1(QGraphicsScene *scene){
    /* On récupère le chemin vers notre ressource */
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Dalle1.png");

    /* On update la valeur de notre paramètre objet à afficher */
    this->setPixmap(this->getImage());
    /* On met à jour la hauteur de l'objet */
    this->setZValue(Z_MAP_MUR);
    /* On ajoute le mur sur notre carte */
    scene->addItem(this);

}

int Dalle1::type()const{
    return TYPE_MAP_ITEM;
}
