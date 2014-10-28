#ifndef CREATURES_H
#define CREATURES_H
/* On souhaite afficher les classes filles des créatures, on dérive donc de notre classe adéquate*/
#include "coeur.h"
#include "potion.h"
#include "elementgraphique.h"

class Creatures: public ElementGraphique
{
public:
    /* Constructeur par défaut */
    Creatures();
    ~Creatures();

    /*Classes communes à toutes nos créatures, leurs types est identique et elles ont toutes les même paramètres*/
    /* Cependant elles diffèrent entre le héros et les PNJs par certains aspects, d'où de possible redéfinition */
    /* et ajustement dans des morceaux de codes très similaires par ailleurs */

    /* Getters */
    int getHealth();
    int getDamage();
    bool getAlive();
    int getCoeur();
    int getPotion();

    /* Setters */
    void setHealth(int);
    void setDamage(int);
    void setAlive(bool);
    void updateHealth();
    void setCoeur(int);
    void setPotion(int);



    /* Redefinition de QGraphicsPixmapItem */
    int type() const;
    void advance(int);


    /* Partie pour un affichage des créatures plus agréable */



    int getTypeMov();
    void setTypeMov(int);
    void setNbDecalage(int);
    int getNbDecalage();
    void uneCollision();
    void toucherParLeJoueur();
    int mouvementOk();


private:

    int _health;
    int _damage;
    bool _isAlive;
    int _move;
    int _nbDecalage;
    int _coeur;
    int _potion;

};

#endif // CREATURES_H
