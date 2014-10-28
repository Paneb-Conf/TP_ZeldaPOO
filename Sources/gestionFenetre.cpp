#include  "gestionFenetre.h"

/* Constructeur par défaut. Le jeu n'est pas lancé et la difficulté de base est facile */
GestionFenetre::GestionFenetre(){
    setDifficulte(DIFFICULTY_EASY);
    this->_leJoueur=JEU_PAS_LANCE;

}

/* Destructeur vide */
GestionFenetre::~GestionFenetre(){

}

/* Fonction d'initialisation de nos bordures */
/*(tout se base sur des paramètres fixés par la scene passée en paramètre*/
void GestionFenetre::initMapCadre(QGraphicsScene* maScene){
    /* Une liste de notre décors de délimitation, pas utilisé pour le moment.
     * Eventuellement par la suite pour une scène plus dynamique
    */
    QList <blocMur> listeDecors;

    /* Notre élément à ajouter sur la carte */
    blocMur* unMur = NULL;

    /* Coté gauche, on se base sur les délimitations extrêmes de notre carte que l'on parcourt de bout
     * en bout pour ajouter nos éléments murs. */
    for(int i = maScene->sceneRect().topLeft().ry(); i<maScene->sceneRect().bottomLeft().ry();)
    {
        unMur = new blocMur(maScene);

        unMur->setPos(maScene->sceneRect().topLeft().rx(), i);

        i = i+IMAGE_SIZE_MUR;

    }
    /* Coté droit */
    for(int i = maScene->sceneRect().topRight().ry(); i<maScene->sceneRect().bottomRight().ry();)
    {
        unMur = new blocMur(maScene);
        unMur->setPos(maScene->sceneRect().topRight().rx(), i);
        i = i+IMAGE_SIZE_MUR;

    }
    /* Haut de la fenêtre */
    for(int i = maScene->sceneRect().topRight().rx(); i>maScene->sceneRect().bottomLeft().rx();)
    {
        unMur = new blocMur(maScene);
        unMur->setPos(i,maScene->sceneRect().topRight().ry());
        i = i-IMAGE_SIZE_MUR;

    }
    /* Bas de la fenêtre */
    for(int i = maScene->sceneRect().bottomRight().rx(); i>=maScene->sceneRect().bottomLeft().rx();)
    {
        unMur = new blocMur(maScene);
        unMur->setPos(i,maScene->sceneRect().bottomRight().ry());
        i = i-IMAGE_SIZE_MUR;

    }


    /* Notre carte est maintenant initialisé, nous démarrons un timer adapté selon le niveau choisi*/
        monTimer.start(VITESSE_MONSTRE/this->getDifficulte());

    return;
}

/* Fonction que notre mainWindow appelle pour faire avancer les items graphiques,
 * ce qui permet de faire avancer les monstres et mettre à jour les icones (monstres + décors)
*/
void GestionFenetre::bougerMonstre(){

    if(this->_jeuLance==JEU_EN_COURS)
        this->getScene()->advance();

    /* Image end game. On vérifie que nous sommes au dernier niveau
     * et qu'il n'y a plus aucun monstre sur la carte.
    */
    if(this->getNiveauCourant()==NIVEAU3)
    {
        this->setVerifMonstre(NO_MONSTRE);
        QList <QGraphicsItem*> maListe= this->getScene()->items();
        for(int i = 0; i<maListe.size();i++)
            if(maListe.at(i)->type()==TYPE_MONSTRE)
                if(maListe.at(i)->isVisible())
                    this->setVerifMonstre(YES_MONSTRE);

        if(getVerifMonstre() == NO_MONSTRE)
        {
            this->setVerifMonstre(NO_REFRESH);

            string chemin = QCoreApplication::applicationDirPath().toStdString();
            if(this->getTriche()==PAS_TRICHE)
                chemin = chemin+"/Images/Yuffieheader_icone.png";
            else
                chemin = chemin+"/Images/LinkMC.png";
            const char* p1 = chemin.c_str();

            this->getScene()->addPixmap(QPixmap(p1));
            this->getLeJoueur()->hide();
        }


    }

}

/* Setter de la vérification de la présence de monstre */
void GestionFenetre::setVerifMonstre(int p){
    this->_verifMonstre = p;
}
/* Getter de la vérification de la présence de monstre */
int GestionFenetre::getVerifMonstre(){
    return this->_verifMonstre;
}

/* Setter de la scéne sur laquelle notre controlleur va travailler */
void GestionFenetre::setScene(QGraphicsScene *p){
    this->maScene = p;
}
/* Getter de la scéne sur laquelle notre controlleur va travailler */
QGraphicsScene* GestionFenetre::getScene(){
    return this->maScene;
}

/* Getter pour récupérer le niveau actuel de la scène */
int GestionFenetre::getNiveauCourant(){
    return this->_niveauCourant;
}
/* Setter pour paramétrer le niveau actuel de la scène */
void GestionFenetre::setNiveauCourant(int p){
    this->_niveauCourant = p;
}
/* Getter pour récupérer la difficulté actuelle */
int GestionFenetre::getDifficulte(){
    return this->_difficulte;
}
/* Setter pour paramétrer la difficulté actuelle.
 * Cette fonction est utilisée lorsque l'utilisateur interagit avec
 * le menu afficher sur la fenêtre principale.
 */
void GestionFenetre::setDifficulte(int p){
    if(p==DIFFICULTY_EASY)
        this->_difficulte = DIFFICULTY_EASY;
    else if(p==DIFFICULTY_MEDIUM)
        this->_difficulte = DIFFICULTY_MEDIUM;
    else if(p==DIFFICULTY_HARD)
        this->_difficulte = DIFFICULTY_HARD;
    else if(p==DIFFICULTY_HARD_AS_FUCK)
        this->_difficulte = DIFFICULTY_HARD_AS_FUCK;
    else
        this->_difficulte = DIFFICULTY_EASY;
}

/* Fonction permettant de gérer la pause, demandé par
 * l'utilisateur et/ou fonction de changement de difficulté
*/
void GestionFenetre::gestionPause(int choix){
    if(choix ==PAUSE_GAME)
        monTimer.stop();
    else if(choix ==START_GAME)
        monTimer.start(VITESSE_MONSTRE/this->getDifficulte());
}
/* Setter pour configurer le joueur de notre contrôlleur */
void GestionFenetre::setLeJoueur(Link * leJoueur){
    this->_leJoueur= leJoueur;
}
/* Getter pour récupérer le joueur de notre contrôlleur */
Link* GestionFenetre::getLeJoueur(){
    return this->_leJoueur;
}

/* Fonction pour générer un niveau du jeu, prenant en paramètre le niveau voulu */
void GestionFenetre::setLvL(QGraphicsScene* maScene, int niveau){
    /* On nettoie la scène */
    maScene->clear();
    QList <QGraphicsItem*> ancienItems = maScene->items();
    while(!ancienItems.isEmpty())
        ancienItems.first()->~QGraphicsItem();
    /* On initialise la scène de la même manière quel que soit le niveau */
    setNiveauCourant(niveau);
    initMapCadre(maScene);

    /* On récupère les valeurs d'intervalles pour placer aléatoirement nos monstres */
    int varPosX = maScene->sceneRect().topRight().x()-maScene->sceneRect().topLeft().x();
    int varPosY = maScene->sceneRect().bottomRight().y()-maScene->sceneRect().topLeft().y();

    /* Ces listes ne servent à rien pour le moment */
    QList<SwordMoblin*> maListeSwordMoblin;
    QList<DarknutRed*> maListeDarknutRed;
    QList<rubis*> maListeRubis;
    QList<LampePiedestal*> maListeLampe;
    QList<GiantGhini*> maListeGiantGhini;


    /* On initialise et place notre héros */
    Link* monHeros = new Link(maScene);
    this->setLeJoueur(monHeros);
    monHeros->setPos((int)0,(int)0);

    /* Ces paramètres seront mis à jour selon le niveau voulu afin
     * d'être utilisés pour générer notre niveau dans une même fonction.
     */
    int pSwordMoblin,pDarknutRed,pRubis,pLampe,pGiantGhini, pEscalier, pCoeur;

    /* Notre switch pour mettre à jour nos valeurs selon le niveau */
    switch(niveau){
    case NIVEAU1:
        pSwordMoblin = SWORDMOBLIN_NIVEAU1;
        pDarknutRed = DARKNUTRED_NIVEAU1;
        pRubis = RUPEE_NIVEAU1;
        pLampe = LAMPE_PIEDNIVEAU1;
        pGiantGhini = GIANTGHINI_NIVEAU1;
        pEscalier = ESCALIER_NIVEAU1;
        pCoeur = COEUR_NIVEAU1;
        this->setTrich(PAS_TRICHE);
        break;
    case NIVEAU2:
        pSwordMoblin = SWORDMOBLIN_NIVEAU2;
        pDarknutRed = DARKNUTRED_NIVEAU2;
        pRubis = RUPEE_NIVEAU2;
        pLampe = LAMPE_PIEDNIVEAU2;
        pGiantGhini = GIANTGHINI_NIVEAU2;
        pEscalier = ESCALIER_NIVEAU2;
        pCoeur = COEUR_NIVEAU2;
        break;
    case NIVEAU3:
        pSwordMoblin = SWORDMOBLIN_NIVEAU3;
        pDarknutRed = DARKNUTRED_NIVEAU3;
        pRubis = RUPEE_NIVEAU3;
        pLampe = LAMPE_PIEDNIVEAU3;
        pGiantGhini = GIANTGHINI_NIVEAU3;
        pEscalier = ESCALIER_NIVEAU3;
        pCoeur = COEUR_NIVEAU3;
        break;
    }

    /* Création et placement des monstres.
     * Le système de placement est le même quel que soit l'objet de manière générale.
     * On souhaite éviter les collisions initiales, on les replace donc tant qu'ils ne
     * sont pas loin les un des autres (même si par la suite les rubis ne sont pas considérés comme
     * des obstacles. Les escaliers ne seront toujours qu'un et sa présence et booleene, d'où un simple
     * test d'existence. Le reste est indexé sur des valeurs définies au préalables
    */
    for(int i = 0;i<pSwordMoblin;i++)
    {
        SwordMoblin* monstre = new SwordMoblin(maScene);
        maListeSwordMoblin.append(monstre);
        do
        {
            monstre->setPos((rand()%varPosX)+maScene->sceneRect().topLeft().x(),(rand()%varPosY)+maScene->sceneRect().topLeft().y());
        }while(!monstre->collidingItems().isEmpty());
    }
    for(int i = 0;i<pDarknutRed;i++)
    {
        DarknutRed* monstre = new DarknutRed(maScene);
        maListeDarknutRed.append(monstre);

        do
        {
            monstre->setPos((rand()%varPosX)+maScene->sceneRect().topLeft().x(),(rand()%varPosY)+maScene->sceneRect().topLeft().y());
        }while(!monstre->collidingItems().isEmpty());
    }
    for(int i = 0;i<pGiantGhini;i++)
    {
        GiantGhini* monstre = new GiantGhini(maScene);
        maListeGiantGhini.append(monstre);

        do
        {
            monstre->setPos((rand()%varPosX)+maScene->sceneRect().topLeft().x(),(rand()%varPosY)+maScene->sceneRect().topLeft().y());
        }while(!monstre->collidingItems().isEmpty());
    }
    for(int i = 0;i<pRubis;i++)
    {
        rubis* monstre = new rubis(maScene);
        maListeRubis.append(monstre);

        do
        {
            monstre->setPos((rand()%varPosX)+maScene->sceneRect().topLeft().x(),(rand()%varPosY)+maScene->sceneRect().topLeft().y());
        }while(!monstre->collidingItems().isEmpty());
    }
    if(pEscalier)
         {
        Escalier* niveauSup = new Escalier(maScene);
        do{
             niveauSup->setPos((rand()%varPosX)+maScene->sceneRect().topLeft().x(),(rand()%varPosY)+maScene->sceneRect().topLeft().y());
        }while(!niveauSup->collidingItems().isEmpty());
    }

    if(pCoeur){
        int tab[maListeDarknutRed.size()];
        int i;
        for(int j = 0; j<pCoeur;j++)
        {
            /* On ajoute des coeurs sur la scène et on met à jour l'indicateur
             * des monstres qui en font apparaitre un ou pas. La variable coeur
             * n'est pas utilisé directement ici car on ne fait que l'instancier.
             * La condition n'est là que pour enlever un warning */
            Coeur* unCoeur = new Coeur(maScene);
            if(unCoeur)
            {}

            int doublon;
            do{
                doublon = 0;
                i = rand()%maListeDarknutRed.size();
                for(int k =0; k<maListeDarknutRed.size();k++)
                    if(tab[k]==i)
                        doublon = 1;

            }while(doublon);
            tab[j]=i;
            maListeDarknutRed.at(i)->setCoeur(HEART);
        }
    }

    /* Ces variables sont mise à jour pour éviter que les lampes à piedestals
     * soient placées de manière aléatoire trop proches des murs et empêchent le
     * passage des monstres de manières répétées
    */
    varPosX = varPosX - IMAGE_SIZE_SAFE;
    varPosY = varPosY -IMAGE_SIZE_SAFE;
    for(int i = 0;i<pLampe;i++)
    {
        LampePiedestal* monstre = new LampePiedestal(maScene);
        maListeLampe.append(monstre);
        do
        {
         monstre->setPos((rand()%varPosX)+maScene->sceneRect().topLeft().x(),(rand()%varPosY)+maScene->sceneRect().topLeft().y());
        }while(!monstre->collidingItems().isEmpty());
    }

    return;
}


void GestionFenetre::setTrich(int p){
    this->_triche = p;
}

int GestionFenetre::getTriche(){
    return this->_triche;
}
