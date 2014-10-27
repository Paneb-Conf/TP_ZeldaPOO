#include "lampepiedestal.h"

LampePiedestal::LampePiedestal()
{
}
LampePiedestal::~LampePiedestal()
{
}
LampePiedestal::LampePiedestal(QGraphicsScene *scene){
    /* On récupère le chemin vers notre ressource */
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Lampe_piedestal1.png");
    this->setNumeroIcone(ICONE1_TORCHE);
    /* On update la valeur de notre paramètre objet à afficher */
    this->setPixmap(this->getImage());
    /* On met à jour la hauteur de l'objet */
    this->setZValue(Z_MAP_ITEM);
    /* On ajoute le mur sur notre carte */
    scene->addItem(this);

}

int LampePiedestal::type() const{
    return TYPE_MAP;
}

void LampePiedestal::advance(int phase){

    if(phase){
        this->miseAjourIcone();
    }


}

void LampePiedestal::miseAjourIcone(){

    if((this->getNumeroIcone()>=ICONE1_TORCHE)&&(this->getNumeroIcone()<ICONE2_TORCHE))
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Lampe_piedestal1.png");
    else if((this->getNumeroIcone()>=ICONE2_TORCHE)&&(this->getNumeroIcone()<ICONE3_TORCHE))
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Lampe_piedestal2.png");
    else if((this->getNumeroIcone()>=ICONE3_TORCHE)&&(this->getNumeroIcone()<ICONE_DUREE_TORCHE))
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Lampe_piedestal3.png");
    else
    {
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Lampe_piedestal3.png");
        this->setNumeroIcone(ICONE1);
    }

    this->setNumeroIcone(this->getNumeroIcone()+1);
    this->setPixmap(this->getImage());
    return;
}
