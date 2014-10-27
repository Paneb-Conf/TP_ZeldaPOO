#include "link.h"


Link::Link()
{

}
Link::~Link()
{

}

Link::Link(QGraphicsScene* maScene){
    /* Paramétrage personnage */
    this->setHealth(THREE_HEART);
    this->setAlive(ALIVE);
    this->setRubis(DEBUT_NIVEAU);
    this->setDamagable(TOUCHABLE);
    this->setCoeur(NO_HEART);
    /* Paramétrage graphique */
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_bot1.png");
    this->setPixmap(this->getImage());
    this->setZValue(Z_HEROS);

    maScene->addItem(this);
}

void Link::setImageDefault(){
    setAttacking(LINK_BASE);
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Link_icone.png");
    this->setPixmap(this->getImage());

}

void Link::setImageIntouchable(){

    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Link_icone_intouchable.png");
    this->setPixmap(this->getImage());
    this->intouchable();

}
void Link::setImageDead(){
    setAttacking(LINK_BASE);
    this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_dead.png");
    this->setPixmap(this->getImage());


}

void Link::miseAjourIcone(int cap){

    switch(cap){
    case AXE_BOT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_bot1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_bot2.png");

        else
           {
             this->setNumeroIcone(ICONE0);
             this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_bot1.png");
            }
        break;
    case AXE_TOP:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_top2.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_top2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_top2.png");
        }
        break;
    case AXE_LEFT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_left1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_left2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_left1.png");
        }
        break;
    case AXE_RIGHT:
        if((this->getNumeroIcone()>=ICONE1)&&(this->getNumeroIcone()<ICONE2))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_right1.png");
        else if((this->getNumeroIcone()>=ICONE2)&&(this->getNumeroIcone()<ICONE_DUREE))
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_right2.png");

        else
        {
            this->setNumeroIcone(ICONE0);
            this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_right1.png");
        }
        break;
    default:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_bot1.png");

        break;


    }
    this->setNumeroIcone(this->getNumeroIcone()+1);
    this->setPixmap(this->getImage());
}


int Link::getHealth(){
    return this->_health;
}
void Link::setHealth(int p){
    this->_health = p;
}

void Link::setDamage(int p){
    this->_damage = p;
}
int Link::getDamage(){
    return this->_damage;
}

int Link::type() const{
    return this->_isAttacking;
}

int Link::getRubis(){
    return this->_rubis;
}

void Link::setRubis(int p){
    this->_rubis = p;

}

int Link::getCoeur(){
    return this->_coeur;
}

void Link::setCoeur(int p){
    this->_coeur = p;
}

int Link::mouvementOk(){
    QList<QGraphicsItem *> liste = collidingItems() ;
    liste.clear();
    liste = this->collidingItems();
    int mesCollision = liste.size();

    for(int i =0; i<mesCollision;i++)
    {
        if(liste.at(i)->type()==TYPE_MAP )
            return COLLISION;
        else if(liste.at(i)->type()==TYPE_MAP_ITEM_RUBIS)
          {  liste.at(i)->~QGraphicsItem();
            int nbRubis = this->getRubis()+1;
            this->setRubis(nbRubis);
        }
        else if
           (liste.at(i)->type()==TYPE_MAP_ITEM_ESCALIER)
        {
            this->setEscalier(ON_ESCALIER);
        }
        else if(liste.at(i)->type() == TYPE_MAP_ITEM_COEUR){
            if(liste.at(i)->isVisible())
            {
                this->setHealth(HEALTH_LINK_PLUS);
                this->setCoeur(HEART);
                liste.at(i)->hide();
            }
        }

    }
    return MOUVEMENTOK;
}
int Link::getEscalier(){
    return this->_onEscalier;
}
void Link::setEscalier(int p){
    this->_onEscalier = p;
}



void Link::moveBot(){
    this->setY(this->y()+IMAGE_SIZE_LINK);
}
void Link::moveTop(){

    this->setY(this->y()-IMAGE_SIZE_LINK);
}
void Link::moveLeft(){

    this->setX(this->x()-IMAGE_SIZE_LINK);
}
void Link::moveRight(){

    this->setX(this->x()+IMAGE_SIZE_LINK);
}

void Link::linkAttack(){


    switch(this->getCap()){
    case AXE_BOT:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_botAttack.png");
        break;
    case AXE_TOP:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_topAttack.png");
        break;
    case AXE_LEFT:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_leftAttack.png");
        break;

    case AXE_RIGHT:
        this->setImage((QCoreApplication::applicationDirPath()).toStdString()+"/Images/Zelda_rightAttack.png");
        break;
    default:
        break;
    }


      this->setPixmap(this->getImage());
      setAttacking(LINK_ATTACK);


}
int Link::isHit(){
    QList<QGraphicsItem *> liste = collidingItems() ;
    liste.clear();
    liste = this->collidingItems();
    for(int i = 0;i<liste.size();i++)
    {
        if((liste.at(i)->type()==TYPE_MONSTRE) && (this->getAttacking()!=LINK_ATTACK))

            return LINK_DAMAGE;
    }
    return LINK_SAFE;

}

void Link::updateHealth(){
    if(this->getDamagable()!=INTOUCHABLE)
     {   this->_health=this->_health-COUP;

        this->intouchable();

    }

    if(this->_health!=DEAD)
        setAlive(ALIVE);
    else if(this->_health==DEAD)
        setAlive(DEAD);
}

bool Link::getAlive(){
    return this->_isAlive;
}

void Link::setAlive(bool p){
    this->_isAlive = p;
}

int Link::getAttacking(){
    return this->_isAttacking;
}

void Link::setAttacking(int p){
    this->_isAttacking = p;
}

void Link::intouchable(){
    this->setDamagable(INTOUCHABLE);
}

void Link::setDamagable(int p){
    this->_isDamagable = p;
}

int Link::getDamagable(){
    return this->_isDamagable;
}
