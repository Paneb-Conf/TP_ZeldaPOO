#include "swordmoblin.h"

SwordMoblin::SwordMoblin()
{
}
SwordMoblin::~SwordMoblin()
{
}

SwordMoblin::SwordMoblin(QGraphicsScene* scene){
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_icone.png");
    this->setPixmap(this->getImage());
    this->setHealth(HEALTH_SWORDMOBLIN);
    this->setCoeur(NO_HEART);
    this->setPotion(NO_POTION);
    this->setAlive(ALIVE);
    this->setTypeMov(NEW_MOVE);
    scene->addItem(this);
}

void SwordMoblin::miseAjourIcone(int cap){

    switch(cap){
    case AXE_BOT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_bot1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_bot2.png");

        else
           {
             this->setNumeroIcone(ICONE0);
             this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_bot1.png");
            }
        break;
    case AXE_TOP:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_top1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_top2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_top1.png");
        }
        break;
    case AXE_LEFT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_left1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_left2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_left1.png");
        }
        break;
    case AXE_RIGHT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_right1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_right2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_right1.png");
        }
        break;
    default:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/SwordMoblin_icone.png");

        break;


    }
    this->setNumeroIcone(this->getNumeroIcone()+1);
    this->setPixmap(this->getImage());
}
