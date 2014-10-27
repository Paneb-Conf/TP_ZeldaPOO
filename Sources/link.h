#ifndef LINK_H
#define LINK_H
#include "elementgraphique.h"

class Link: public ElementGraphique
{
public:

    Link();
    Link(QGraphicsScene*);
    ~Link();
    /*Classes similaires nos créatures, leurs types est identique et elles ont toutes les même paramètres*/
    /* Getters */
    int getHealth();
    int getDamage();
    bool getAlive();

    /* Setters */
    void setHealth(int);
    void setDamage(int);
    void setImageDefault();
     void setAlive(bool);

    /* Fonctions d'interaction entre objets divers */
    void updateHealth();
    int getRubis();
    void setRubis(int);
    int getEscalier();
    void setEscalier(int);
    int getCoeur();
    void setCoeur(int);
    /* Fonctions pour la partie attaque et ou combat */
    void linkAttack();
    int getAttacking();
    void setAttacking(int);
    int isHit();
    void intouchable();
    int getDamagable();
    void setDamagable(int);
    void setImageIntouchable();
    void setImageDead();
    void miseAjourIcone(int);


    /* Redefinition de QGraphicsPixmapItem */
    int type()const;

    /* Redéfinition depuis Elementgraphique pour un déplacement plus adapté que */
    /* celui de la classe mère (pixel par pixel, plus adaptés aux créatures non */
    /* dirigées par un être humain */
    void moveBot();
    void moveTop();
    void moveLeft();
    void moveRight();
    int mouvementOk();



private:
    int _health;
    int _damage;
    bool _isAlive;
    int _isAttacking;
    int _isDamagable;
    int _rubis;
    int _onEscalier;
    int _coeur;

};

#endif // LINK_H
