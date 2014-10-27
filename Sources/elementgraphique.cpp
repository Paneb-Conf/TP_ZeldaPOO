#include "elementgraphique.h"

ElementGraphique::ElementGraphique()
{
}
ElementGraphique::~ElementGraphique()
{
}

int ElementGraphique::mouvementOk(){
    return MOUVEMENTOK;
}
void ElementGraphique::miseAjourIcone(int p){
    if(p)
        return;
}

void ElementGraphique::setImage(string p){
    const char* p1 = p.c_str();
    QFileInfo testExistence(p1);
    if(testExistence.exists(p1))
        this->_image.load(p1,0,Qt::AutoColor);
    else
        cout<<"\nErreur, fichier "<<p<<" non trouvé ! Vérifiez les ressources.\n";
}
QPixmap ElementGraphique::getImage(){
    return this->_image;
}

int ElementGraphique::type() const{
    return 0;
}


void ElementGraphique::moveBot(){
    this->setY(this->y()+IMAGE_SIZE);
}
void ElementGraphique::moveTop(){
    this->setY(this->y()-IMAGE_SIZE);
}
void ElementGraphique::moveLeft(){
    this->setX(this->x()-IMAGE_SIZE);
}
void ElementGraphique::moveRight(){
    this->setX(this->x()+IMAGE_SIZE);
}
/* Element nécessaire pour la suite, classe filles */
void ElementGraphique::advance(){
    return;
    }
int ElementGraphique::getNumeroIcone(){
   return this->_numeroIcone;
}
void ElementGraphique::setNumeroIcone(int p){
    this->_numeroIcone = p;
}
int ElementGraphique::getCap(){
    return this->_cap;
}

void ElementGraphique::setCap(int p){
    this->_cap =p;
}
