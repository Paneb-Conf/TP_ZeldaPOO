#include "darknutred.h"

DarknutRed::DarknutRed()
{
}
DarknutRed::~DarknutRed()
{
}
DarknutRed::DarknutRed(QGraphicsScene* scene){
    this->setHealth(HEALTH_DARKNUTRED);
    this->setAlive(ALIVE);
    this->setCoeur(NO_HEART);
    this->setTypeMov(NEW_MOVE);
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_icone.png");
    this->setPixmap(this->getImage());
    scene->addItem(this);

}
void DarknutRed::miseAjourIcone(int cap){

    switch(cap){
    case AXE_BOT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_bot1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_bot2.png");

        else
           {
             this->setNumeroIcone(ICONE0);
             this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_bot1.png");
            }
        break;
    case AXE_TOP:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_top1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_top2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_top1.png");
        }
        break;
    case AXE_LEFT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_left1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_left2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_left1.png");
        }
        break;
    case AXE_RIGHT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_right1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_right2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_right1.png");
        }
        break;
    default:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/DarknutRed_icone.png");

        break;


    }
    this->setNumeroIcone(this->getNumeroIcone()+1);
    this->setPixmap(this->getImage());
}
