#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gestionFenetre.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     game = new GestionFenetre();
    /* PARTIE PARAMETRAGE DE LA FENETRE */
     /* On utilise la classe créée avec QT 4 Designer */
     /* Pour rappel la main window a comme membre :
      * ui
      * scene (type QGraphicsScene)
      * monChemin (variable de type string où sera stocké le chemin de l'application)
      * On a une variable maCarte de type QGraphicView egalement.
      */
     ui->setupUi(this);

     /* On récupère le chemin menant au dossier de l'exécution après l'avoir mis à jour dans l'objet.*/
     this->trouverChemin();
     string monPath = this->getChemin();

     /* On déclare notre icone */
     string imageIcone = "/Images/zelda-link-ds.jpg";
     /* On concatène le chemin absolu de où on se trouve avec l'arborescence de notre dossier*/
     string monPathIcone = monPath + imageIcone;
     /* On change le type de nos variables pour utiliser les fonctions QIcon et QPixmap */
     const char* imageIconeAffiche = monPathIcone.c_str();
     /* Paramétrage de l'icone */
     this->setWindowIcon(QIcon(imageIconeAffiche));


     /* Partie affichage graphique en mode scène */
     this->scene = new QGraphicsScene();
     this->scene->setSceneRect(ui->maCarte->sceneRect());
     ui->maCarte->setScene((this->scene));


     string chemin = monPath +"/Images/Dalle1.png";
      const char* p1 = chemin.c_str();
     ui->maCarte->setBackgroundBrush(QPixmap(p1));


     /* Necessaire pour le chemin relatif des images de QT Design (sinon non affichés) */
     chemin = monPath + "/Images/HeartContainerLoZ.png";
     p1 = chemin.c_str();

     this->ui->coeur1Plein->setPixmap(QPixmap(p1));
     this->ui->coeur2Plein->setPixmap(QPixmap(p1));
     this->ui->coeur3Plein->setPixmap(QPixmap(p1));
     this->ui->coeur4Plein->setPixmap(QPixmap(p1));

     chemin = monPath +"/Images/coeurVide.png";
     p1 = chemin.c_str();

     this->ui->coeurVide1->setPixmap(QPixmap(p1));
     this->ui->coeurVide2->setPixmap(QPixmap(p1));
     this->ui->coeurVide3->setPixmap(QPixmap(p1));
     this->ui->coeurVide4->setPixmap(QPixmap(p1));

     chemin = monPath +"/Images/BlueRupee_iconeTop.png";
     p1 = chemin.c_str();

     this->ui->imageDiamant->setPixmap(QPixmap(p1));

     chemin = monPath+"/Images/logo.png";
     p1 = chemin.c_str();

     this->ui->logo->setPixmap(QPixmap(p1));


     /* On cache le coeur bonus */
     this->ui->coeur4Plein->hide();
     this->ui->coeurVide4->hide();

     game->setScene(this->scene);
     this->nbTouche = PREMIERE_TOUCHE;
     this->game->setNiveauCourant(DEBUT_NIVEAU);


     /* Signaaux de mouvement des monstres sur la carte et de mise à jour des items et joueur */
     connect(&(game->monTimer),SIGNAL(timeout()),this->game,SLOT(bougerMonstre()));
     connect(&(game->monTimer),SIGNAL(timeout()),this,SLOT(miseAjourItem()));
     connect(&(game->monTimerLent),SIGNAL(timeout()),this,SLOT(miseAjourLink()));

}

void MainWindow::choisirDifficulte(int p){
    game->setDifficulte(p);
    if(game->getNiveauCourant()==NIVEAU1)
        monterNiveau1();
    else if(game->getNiveauCourant()==NIVEAU2)
        monterNiveau2();
    else if(game->getNiveauCourant()==NIVEAU3)
        monterNiveau3();

    this->_etatJeu = START_GAME;
    this->gererPause();


}

void MainWindow::monterNiveau1(){
    this->game->_jeuLance = JEU_EN_COURS;
this->ui->logo->hide();
    if((this->game->getNiveauCourant()!=NIVEAU1) || (this->game->getLeJoueur()->getAlive()==DEAD))
      {
        this->game->setLvL(this->scene,NIVEAU1);
        this->game->setTrich(PAS_TRICHE);
    }
}
void MainWindow::monterNiveau2(){
    this->game->_jeuLance = JEU_EN_COURS;
this->ui->logo->hide();
    if((this->game->getNiveauCourant()!=NIVEAU2) || (this->game->getLeJoueur()->getAlive()==DEAD))
    {
        this->game->setLvL(this->scene,NIVEAU2);
        this->game->setTrich(TRICHE);
    }
}
void MainWindow::monterNiveau3(){
    this->game->_jeuLance = JEU_EN_COURS;
this->ui->logo->hide();
    if((this->game->getNiveauCourant()!=NIVEAU3) || (this->game->getLeJoueur()->getAlive()==DEAD))
    {
        this->game->setLvL(this->scene,NIVEAU3);
        this->game->setTrich(TRICHE);
    }
}

void MainWindow::gererPause(){
    if( this->_etatJeu == PAUSE_GAME)
        this->_etatJeu = START_GAME;
    else
        this->_etatJeu = PAUSE_GAME;
    this->game->gestionPause(this->_etatJeu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Setter pour trouver le chemin absolu */
void MainWindow::trouverChemin(){
    this->monChemin = (QCoreApplication::applicationDirPath()).toStdString();
}
/* Getter pour nous retourner le chemin de l'application */
string MainWindow::getChemin(){
    return this->monChemin;
}

void MainWindow::keyPressEvent(QKeyEvent* event){
if(this->game->_jeuLance==JEU_EN_COURS){
    if((this->_etatJeu != PAUSE_GAME) &&(this->game->getLeJoueur()->getHealth()>DEAD) &&(this->game->getNiveauCourant()!=DEBUT_NIVEAU) &&(this->game->_jeuLance == JEU_EN_COURS)){
        int previousCap = this->game->getLeJoueur()->getCap();
                if(event->key()==Qt::Key_A)
                {
                    this->game->getLeJoueur()->moveLeft();
                    this->game->getLeJoueur()->moveTop();
                }
                else if(event->key()==Qt::Key_E)
                {
                    this->game->getLeJoueur()->moveRight();
                    this->game->getLeJoueur()->moveTop();
                }
                else if(event->key()==Qt::Key_W)
                {
                    this->game->getLeJoueur()->moveLeft();
                    this->game->getLeJoueur()->moveBot();
                }
                else if(event->key()==Qt::Key_C)
                {
                    this->game->getLeJoueur()->moveRight();
                    this->game->getLeJoueur()->moveBot();
                }
                else if(event->key()==Qt::Key_D)
                {
                    this->game->getLeJoueur()->setCap(AXE_RIGHT);
                    this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());
                    this->game->getLeJoueur()->moveRight();

                    if(this->game->getLeJoueur()->mouvementOk()==COLLISION)
                      {
                        this->game->getLeJoueur()->moveLeft();
                        this->game->getLeJoueur()->setCap(previousCap);
                        this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());
                    }
                }

                else if(event->key()==Qt::Key_Q)
                 {
                    this->game->getLeJoueur()->setCap(AXE_LEFT);
                    this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());
                    this->game->getLeJoueur()->moveLeft();

                    if(this->game->getLeJoueur()->mouvementOk()==COLLISION)
                      {
                        this->game->getLeJoueur()->moveRight();
                        this->game->getLeJoueur()->setCap(previousCap);
                        this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());

                    }
                }
                else if(event->key()==Qt::Key_Z)
                {   this->game->getLeJoueur()->setCap(AXE_TOP);
                    this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());
                    this->game->getLeJoueur()->moveTop();

                    if(this->game->getLeJoueur()->mouvementOk()==COLLISION)
                       { this->game->getLeJoueur()->moveBot();
                        this->game->getLeJoueur()->setCap(previousCap);
                        this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());

                    }
                }
                else if(event->key()==Qt::Key_S)
                 {
                    this->game->getLeJoueur()->setCap(AXE_BOT);
                    this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());
                    this->game->getLeJoueur()->moveBot();

                    if(this->game->getLeJoueur()->mouvementOk()==COLLISION)
                       { this->game->getLeJoueur()->moveTop();
                        this->game->getLeJoueur()->setCap(previousCap);
                        this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());

                    }
                }
                else if(event->key()==Qt::Key_M)
                 {
                   if(!event->isAutoRepeat())
                   {
                            this->game->getLeJoueur()->linkAttack();
                    }

                }
                /* A decommenter pour se rajouter une vie en appuyant sur P */

                else if(event->key()==Qt::Key_P)
                 {
                            this->game->getLeJoueur()->setHealth(this->game->getLeJoueur()->getHealth()+1);


                }
            }
            else if(this->game->getLeJoueur()->getHealth()<=DEAD)
                this->game->getLeJoueur()->setImageDead();
}
}

void MainWindow::keyReleaseEvent(QKeyEvent* event){

    if(event)
    {
        if(this->game->_jeuLance == JEU_EN_COURS)
            this->miseAjourLink();
    }
}

void MainWindow::miseAjourItem(){
if(this->game->_jeuLance==JEU_EN_COURS){
    /*Update de l'affichage de rubis*/
    this->ui->nbRubis->display(this->game->getLeJoueur()->getRubis());
    if(this->game->getLeJoueur()->getHealth()==DEAD)
     {   this->game->getLeJoueur()->setImageDead();

    }
    /* Update d'affichage de la vie, deux en fonction du ramassage de coeur */

    if(this->game->getLeJoueur()->getCoeur()==NO_HEART){
         this->ui->coeur4Plein->hide();
         this->ui->coeurVide4->hide();
        switch (this->game->getLeJoueur()->getHealth()) {

        case DEAD:
            this->ui->coeur1Plein->hide();
            this->ui->coeur2Plein->hide();
            this->ui->coeur3Plein->hide();
            this->game->getLeJoueur()->setImageDead();
            break;
        case ONE_HEART:
            this->ui->coeur1Plein->show();
            this->ui->coeur2Plein->hide();
            this->ui->coeur3Plein->hide();

            break;
        case TWO_HEART:
            this->ui->coeur1Plein->show();
            this->ui->coeur2Plein->show();
            this->ui->coeur3Plein->hide();
            break;
        case THREE_HEART:
            this->ui->coeur1Plein->show();
            this->ui->coeur2Plein->show();
            this->ui->coeur3Plein->show();
            break;
            /* A priori on rentre dans le défaut si le jeu va trop vite pour infliger des degats, donc mort */
        default:
            this->ui->coeur1Plein->hide();
            this->ui->coeur2Plein->hide();
            this->ui->coeur3Plein->hide();
            this->game->getLeJoueur()->setImageDead();
            break;
        }
        }
    else{
        this->ui->coeurVide4->show();
        switch (this->game->getLeJoueur()->getHealth()) {
        case DEAD:
            this->ui->coeur1Plein->hide();
            this->ui->coeur2Plein->hide();
            this->ui->coeur3Plein->hide();
            this->ui->coeur4Plein->hide();
            this->game->getLeJoueur()->setImageDead();
            break;
        case ONE_HEART:
            this->ui->coeur1Plein->show();
            this->ui->coeur2Plein->hide();
            this->ui->coeur3Plein->hide();
            this->ui->coeur4Plein->hide();

            break;
        case TWO_HEART:
            this->ui->coeur1Plein->show();
            this->ui->coeur2Plein->show();
            this->ui->coeur3Plein->hide();
            this->ui->coeur4Plein->hide();
            break;
        case THREE_HEART:
            this->ui->coeur1Plein->show();
            this->ui->coeur2Plein->show();
            this->ui->coeur3Plein->show();
            this->ui->coeur4Plein->hide();
            break;
        case HEALTH_LINK_PLUS:
            this->ui->coeur1Plein->show();
            this->ui->coeur2Plein->show();
            this->ui->coeur3Plein->show();
            this->ui->coeur4Plein->show();
            break;
            /* A priori on rentre dans le défaut si le jeu va trop vite pour infliger des degats, donc mort */
        default:
            this->ui->coeur1Plein->hide();
            this->ui->coeur2Plein->hide();
            this->ui->coeur3Plein->hide();
            this->game->getLeJoueur()->setImageDead();
            break;
        }
    }

   /* Mise à jour niveau escalier (plus de rubis nécessaire)*/
    QList<QGraphicsItem*> allItems = this->game->getScene()->items();
    int resteRubis = 0;
    QList<QGraphicsItem*> listeEscalier = this->game->getLeJoueur()->collidingItems();
    for(int i = 0; i<allItems.size();i++)
    {    if(allItems.at(i)->type()==TYPE_MAP_ITEM_RUBIS)
        {
            resteRubis++;
        }
    }
    if(!resteRubis)
    for(int i = 0; i<listeEscalier.size();i++)
    {

        if(listeEscalier.at(i)->type()==TYPE_MAP_ITEM_ESCALIER)
            switch(this->game->getNiveauCourant()){
            case NIVEAU1:
                this->game->setLvL(this->game->getScene(),NIVEAU2);
                break;
            case NIVEAU2:
                this->game->setLvL(this->game->getScene(),NIVEAU3);
                break;
            default:
                break;
            }
    }
    /* Fin de la gestion de l'escalier*/
}
}
void MainWindow::miseAjourLink(){


    if(this->game->getLeJoueur()->getHealth()>DEAD)
    {    if(this->nbTouche==TOUCHE_INTOUCHABLE)
          {

            this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());
            this->game->getLeJoueur()->setDamagable(TOUCHABLE);
            this->nbTouche = PREMIERE_TOUCHE;
            this->game->getLeJoueur()->setAttacking(LINK_BASE);

        }
        else if((PREMIERE_TOUCHE<this->nbTouche)&&(this->nbTouche<TOUCHE_INTOUCHABLE))
          {
            this->game->getLeJoueur()->setImageIntouchable();
            this->game->getLeJoueur()->intouchable();
            this->nbTouche = this->nbTouche +1;
          }
        else{

            this->game->getLeJoueur()->miseAjourIcone(this->game->getLeJoueur()->getCap());
            this->game->getLeJoueur()->setDamagable(TOUCHABLE);
            this->game->getLeJoueur()->setAttacking(LINK_BASE);
            this->nbTouche = PREMIERE_TOUCHE;
        }

        if((this->game->getLeJoueur()->isHit()==LINK_DAMAGE) && (this->game->getLeJoueur()->getDamagable()==TOUCHABLE))
        {
                   this->game->getLeJoueur()->updateHealth();
                   this->nbTouche = PREMIERE_TOUCHE + 1;

        }


    }
}
