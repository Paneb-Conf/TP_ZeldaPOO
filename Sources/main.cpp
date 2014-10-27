#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{


    /* Création et affichage de notre fenêtre principale */
    QApplication a(argc, argv);
    MainWindow monZelda;

    /* Affichage de la fenêtre paramétrée */
    monZelda.show();
    return a.exec();
}
