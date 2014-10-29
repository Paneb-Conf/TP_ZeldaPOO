#include "fleche.h"

Fleche::Fleche()
{
}
Fleche::~Fleche()
{
}
Fleche::Fleche(QGraphicsScene* maScene, QPointF leDepart, int cap)
{
    this->setCap(cap);
    this->miseAjourIcone(cap);
    this->setPos(leDepart);
    this->setZValue(Z_MONSTRE);
    maScene->addItem(this);
}
int Fleche::type()const
{
    return TYPE_HEROS_FLECHE;
}
void Fleche::advance(int phase)
{
    if(phase){
        switch(this->getCap()){
        case AXE_BOT:
            this->moveBot();
            this->moveBot();
            if(!this->mouvementOk())
                this->~QGraphicsItem();
            break;
        case AXE_TOP:
            this->moveTop();
            this->moveTop();
            if(!this->mouvementOk())
                this->~QGraphicsItem();
            break;
        case AXE_LEFT:
            this->moveLeft();
            this->moveLeft();
            if(!this->mouvementOk())
                this->~QGraphicsItem();
            break;
        case AXE_RIGHT:
            this->moveRight();
            this->moveRight();
            if(!this->mouvementOk())
                this->~QGraphicsItem();
            break;

        }
    }
}
int Fleche::mouvementOk()
{
    QList<QGraphicsItem *> liste = collidingItems() ;
    liste.clear();
    liste = this->collidingItems();
    int mesCollision = liste.size();

    for(int i =0; i<mesCollision;i++)
    {
        if(liste.at(i)->type()==TYPE_MAP)
            return COLLISION;

    }
    return MOUVEMENTOK;
}
void Fleche::miseAjourIcone(int cap){

    switch(cap){
    case AXE_TOP:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Fleche_top.png");
        break;
    case AXE_BOT:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Fleche_bot.png");
        break;
    case AXE_LEFT:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Fleche_left.png");
        break;
    case AXE_RIGHT:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Fleche_right.png");
        break;
    }

    this->setPixmap(this->getImage());

}
