#include "rubis.h"

rubis::rubis()
{
}
rubis::~rubis()
{
}
rubis::rubis(QGraphicsScene *scene){
    /* On récupère le chemin vers notre ressource */
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/BlueRupee_icone.png");

    /* On update la valeur de notre paramètre objet à afficher */
    this->setPixmap(this->getImage());
    /* On met à jour la hauteur de l'objet */
    this->setZValue(Z_MAP_ITEM);
    /* On ajoute le rubis sur notre carte */
    scene->addItem(this);


}

int rubis::type() const{
    return TYPE_MAP_ITEM_RUBIS;
}
