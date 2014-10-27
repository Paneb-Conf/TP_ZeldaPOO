#ifndef GESTIONFENETRE_H
#define GESTIONFENETRE_H

#include <iostream>
#include <QGraphicsScene>
#include <QThread>
#include <QList>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>
#include <math.h>
#include "swordmoblin.h"
#include "darknutred.h"
#include "giantghini.h"
#include "blocmur.h"
#include "rubis.h"
#include "escalier.h"
#include "dalle1.h"
#include "lampepiedestal.h"
#include "coeur.h"
#include "link.h"
class GestionFenetre : public QObject
{
    Q_OBJECT
    public:
        GestionFenetre();
        ~GestionFenetre();
        /* Création des niveaux et gestion de la difficulté */
        void setLvL(QGraphicsScene*, int);
        void initMapCadre(QGraphicsScene*);
        void setNiveauCourant(int);
        int getNiveauCourant();
        void setDifficulte(int);
        int getDifficulte();
        void setScene(QGraphicsScene *);
        QGraphicsScene* getScene();
        void setLeJoueur(Link*);
        Link* getLeJoueur();

        /* Fonction pour délimiter le contour de la carte */
        void gestionPause(int);

        /* Fonctions pour vérifier la présence de monstre sur la carte
         * et faire apparaitre l'image de fin du jeu */
        void setVerifMonstre(int);
        int getVerifMonstre();

        /*Timer utilisés pour nos items
         * Le premier concerne les monstres et leurs mouvements,
         * le second plus lent est utilisé pour mettre à jours notre Zelda,
         * et le dernier afin d'empêcher notre Zelda de se faire multi-touché
         * par les ennemis
        */
        QTimer monTimer;
        QTimer monTimerLent;
        QTimer monTimerIntouchable;

        /* Cette variable de contrôle est utilisé pour empêcher des crash si
         * l'utilisateur appuit sur des touches avant qu'un niveau soit initialisé
         */
        int _jeuLance;

        void setTrich(int);
        int getTriche();


public slots:
        /* Nécessaire, appelé depuis mainWindow */
        /* Est utilisé pour mettre à jours nos items par advance */
        void bougerMonstre();

private:
        QGraphicsScene* maScene;
        Link* _leJoueur;
        /* Ces variables sont utilisées pour la gestion du menu supérieur */
        int _niveauCourant;
        int _difficulte;
        int _verifMonstre;

        /* variable pour afficher le message de fin */
        int _triche;

};


#endif // GESTIONFENETRE_H
