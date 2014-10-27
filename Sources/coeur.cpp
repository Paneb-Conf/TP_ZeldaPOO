#include "coeur.h"
Coeur::Coeur()
{
}
Coeur::~Coeur()
{
}
Coeur::Coeur(QGraphicsScene* scene)
{
    /* On récupère le chemin vers notre ressource */
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Coeur_icone.png");

    /* On update la valeur de notre paramètre objet à afficher */
    this->setPixmap(this->getImage());
    /* On met à jour la hauteur de l'objet */
    this->setZValue(Z_MAP_ITEM);
    /* On ajoute le coeur sur la carte */
    scene->addItem(this);
    /* On cache le coeur et on le met en non utilisé par le joeur*/
    this->setUtilise(HEART_UNUSED);
    this->hide();

}

int Coeur::type() const{
    return TYPE_MAP_ITEM_COEUR;
}

void Coeur::setUtilise(int p) {
    this->_utilise = p;
}

int Coeur::getUtilise(){
    return this->_utilise;
}
