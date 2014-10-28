#include "giantghini.h"

GiantGhini::GiantGhini()
{
}
GiantGhini::GiantGhini(QGraphicsScene* scene)
{   this->setHealth(HEALTH_GIANTGHINI);
    this->setCoeur(NO_HEART);
    this->setPotion(NO_POTION);
    this->setAlive(ALIVE);
    this->setTypeMov(NEW_MOVE);
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/GiantGhini_icone.png");
    this->setPixmap(this->getImage());
    scene->addItem(this);
}
GiantGhini::~GiantGhini()
{
}
