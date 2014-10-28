#ifndef CONSTANTES_H
#define CONSTANTES_H



/* Indice sur la difficulté */
#define DIFFICULTY_EASY 1
#define DIFFICULTY_MEDIUM 2
#define DIFFICULTY_HARD 3
#define DIFFICULTY_HARD_AS_FUCK  8

/* Variables sur les niveaux */
#define NIVEAU1 1
#define NIVEAU2 2
#define NIVEAU3 3

#define SWORDMOBLIN_NIVEAU1 4
#define DARKNUTRED_NIVEAU1  1
#define GIANTGHINI_NIVEAU1  0
#define LAMPE_PIEDNIVEAU1 1
#define ESCALIER_NIVEAU1 1
#define RUPEE_NIVEAU1   3
#define COEUR_NIVEAU1   0
#define POTION_NIVEAU1  1

#define SWORDMOBLIN_NIVEAU2 6
#define DARKNUTRED_NIVEAU2  3
#define GIANTGHINI_NIVEAU2  0
#define LAMPE_PIEDNIVEAU2 5
#define ESCALIER_NIVEAU2 1
#define RUPEE_NIVEAU2   4
#define COEUR_NIVEAU2   1
#define POTION_NIVEAU2  2

#define SWORDMOBLIN_NIVEAU3 6
#define DARKNUTRED_NIVEAU3  8
#define GIANTGHINI_NIVEAU3  1
#define LAMPE_PIEDNIVEAU3 5
#define ESCALIER_NIVEAU3 0
#define RUPEE_NIVEAU3   7
#define COEUR_NIVEAU3   2
#define POTION_NIVEAU3  4






/* Variables générale sur joueur */
#define HEALTH_MAX  100
#define HEALTH_RESTORE_STEP  10

#define ONE_HEART 1
#define TWO_HEART 2
#define THREE_HEART 3
#define TOUCHABLE 1
#define INTOUCHABLE 2
#define PREMIERE_TOUCHE 1
#define TOUCHE_INTOUCHABLE 8
#define ON_ESCALIER 1
#define OUT_SIDE_ESCALIER 0

/*Variables des monstres */
#define Z_MONSTRE 20
#define Z_HEROS 20
#define Z_MAP_MUR   0
#define Z_MAP_ITEM 10
#define TYPE_MONSTRE 70000
#define TYPE_HEROS 80000
#define TYPE_MAP 89999
#define TYPE_MAP_ITEM 90000
#define TYPE_MAP_ITEM_ESCALIER 90001
#define TYPE_MAP_ITEM_RUBIS 90002
#define TYPE_MAP_ITEM_COEUR 90003
#define TYPE_MAP_ITEM_POTION 90004
#define HEALTH_SWORDMOBLIN 1
#define HEALTH_DARKNUTRED 2
#define HEALTH_GIANTGHINI 5
#define HEART 1
#define NO_HEART 2
#define HEART_USED 0
#define HEART_UNUSED 1
#define POTION 1
#define NO_POTION 2
#define POTION_USED 0
#define POTION_UNUSED 1

#define HEALTH_LINK 3
#define HEALTH_LINK_PLUS 4
#define LINK_ATTACK 10
#define LINK_BASE   0
#define LINK_DAMAGE 1
#define LINK_SAFE 0
#define ATTACK_OK 1
#define ATTACK_FAIL 0

#define COUP    1
#define ALIVE   1
#define DEAD    0

#define COLLISION_MAX 3
#define COLLISION_NULL 0

#define NO_MONSTRE 0
#define YES_MONSTRE 1
#define NO_REFRESH 2

/* Variable sur le carte */
/* A note :
 * la VITESSE_MONSTRE est au numérateur du timer de mouvement.
 * L'augmenter ici ralenti donc les monstres. La taille du mur
 * est utilisée pour planter le décor. L'image size est appellé pour déplacer
 * les ennemis de ce nombre de pixel.
*/
#define UN_PIXEL   1
#define IMAGE_SIZE 2
#define IMAGE_SIZE_MUR 25
#define IMAGE_SIZE_LINK 8
#define IMAGE_SIZE_SAFE 50
#define ICONE1  1
#define ICONE2 10
#define ICONE_DUREE 20

#define ICONE1_TORCHE  1
#define ICONE2_TORCHE 10
#define ICONE3_TORCHE 20
#define ICONE_DUREE_TORCHE 30


#define ICONE0 0
#define JUMP    15
#define DUREE_ATTAQUE 900
#define INTERACTIVE 1
#define VITESSE_MONSTRE 25
#define SAME_MOV 100
#define NEW_MOVE 0
#define ONE_MOVE 1
#define AXES_MOUVEMENTS  4
#define AXE_BOT 0
#define AXE_LEFT  1
#define AXE_RIGHT 2
#define AXE_TOP 3
#define PAUSE_GAME   1
#define START_GAME  2
#define COLLISION 0
#define MOUVEMENTOK 1


#define DEBUT_NIVEAU 0



#define JEU_EN_COURS 1
#define JEU_PAS_LANCE 0
#define TRICHE 1
#define PAS_TRICHE 0
#endif // CONSTANTES_H
