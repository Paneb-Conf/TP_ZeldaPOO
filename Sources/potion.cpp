#include "potion.h"

Potion::Potion()
{
}

Potion::~Potion()
{
}
Potion::Potion(QGraphicsScene* scene)
{
    /* On récupère le chemin vers notre ressource */
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Potion_Rouge_icone.png");

    /* On update la valeur de notre paramètre objet à afficher */
    this->setPixmap(this->getImage());
    /* On met à jour la hauteur de l'objet */
    this->setZValue(Z_MAP_ITEM);
    /* On ajoute le coeur sur la carte */
    scene->addItem(this);
    /* On cache le coeur et on le met en non utilisé par le joeur*/
    this->setUtilise(POTION_UNUSED);
    this->hide();

}

int Potion::type() const{
    return TYPE_MAP_ITEM_POTION;
}

void Potion::setUtilise(int p) {
    this->_utilise = p;
}

int Potion::getUtilise(){
    return this->_utilise;
}
