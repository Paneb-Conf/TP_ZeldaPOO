#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <string>
#include "gestionFenetre.h"
using namespace std;


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void trouverChemin();
    string getChemin();
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    ~MainWindow();
    int nbTouche;
public slots:
        void monterNiveau2();
        void monterNiveau1();
        void monterNiveau3();
        void choisirDifficulte(int);
        void gererPause();
        void miseAjourItem();
        void miseAjourLink();

private:
    int _etatJeu; /*Gestion pause*/
    int _monterScene; /*Gestion clavier capturé*/
    Ui::MainWindow *ui;     /* Issue de QT4 designer*/
    QGraphicsScene *scene; /* Scène où seront placés nos éléments*/
    string monChemin;    /* Contiendra le chemin de notre application (pour les images)*/
    GestionFenetre *game; /*Notre controlleur de fenêtre*/

};

#endif // MAINWINDOW_H
