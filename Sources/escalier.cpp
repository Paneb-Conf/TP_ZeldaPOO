#include "escalier.h"

Escalier::Escalier()
{
}
Escalier::~Escalier()
{
}
Escalier::Escalier(QGraphicsScene *scene){
    /* On récupère le chemin vers notre ressource */
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/EscalierZelda.png");

    /* On update la valeur de notre paramètre objet à afficher */
    this->setPixmap(this->getImage());
    /* On met à jour la hauteur de l'objet */
    this->setZValue(Z_MAP_ITEM);
    /* On ajoute le mur sur notre carte */
    scene->addItem(this);

}

int Escalier::type() const{
    return TYPE_MAP_ITEM_ESCALIER;
}
