#include "blocmur.h"

blocMur::blocMur()
{
}
blocMur::~blocMur()
{
}
blocMur::blocMur(QGraphicsScene *scene){
    /* On récupère le chemin vers notre ressource */
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/mur_vert_icone.png");

    /* On update la valeur de notre paramètre objet à afficher */
    this->setPixmap(this->getImage());
    /* On met à jour la hauteur de l'objet */
    this->setZValue(Z_MAP_MUR);
    /* On ajoute le mur sur notre carte */
    scene->addItem(this);

}
