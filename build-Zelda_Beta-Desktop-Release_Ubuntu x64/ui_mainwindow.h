/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCharger_une_partie;
    QAction *actionSauvegarder;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QGraphicsView *maCarte;
    QPushButton *loadLevel1;
    QPushButton *loadLevel2;
    QPushButton *quitter;
    QComboBox *choixDiff;
    QLabel *InfoDiff;
    QLabel *InfoGroup;
    QPushButton *bouttonPause;
    QPushButton *loadLevel3;
    QLabel *commandes;
    QLabel *imageDiamant;
    QLCDNumber *nbRubis;
    QLabel *infoFleche;
    QLabel *coeur1Plein;
    QLabel *coeur2Plein;
    QLabel *coeur3Plein;
    QLabel *coeurVide1;
    QLabel *coeurVide2;
    QLabel *coeurVide3;
    QLabel *logo;
    QLabel *label;
    QLabel *coeur4Plein;
    QLabel *coeurVide4;
    QMenuBar *menubar;
    QMenu *menuOption_de_jeu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1060, 713);
        MainWindow->setMinimumSize(QSize(800, 700));
        QFont font;
        font.setFamily(QStringLiteral("rsfs10"));
        font.setItalic(true);
        MainWindow->setFont(font);
        actionCharger_une_partie = new QAction(MainWindow);
        actionCharger_une_partie->setObjectName(QStringLiteral("actionCharger_une_partie"));
        actionSauvegarder = new QAction(MainWindow);
        actionSauvegarder->setObjectName(QStringLiteral("actionSauvegarder"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        maCarte = new QGraphicsView(centralwidget);
        maCarte->setObjectName(QStringLiteral("maCarte"));
        maCarte->setEnabled(false);
        maCarte->setGeometry(QRect(0, 60, 791, 571));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(maCarte->sizePolicy().hasHeightForWidth());
        maCarte->setSizePolicy(sizePolicy);
        maCarte->setMinimumSize(QSize(256, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("URW Chancery L"));
        font1.setPointSize(12);
        maCarte->setFont(font1);
        QBrush brush(QColor(40, 204, 64, 255));
        brush.setStyle(Qt::Dense4Pattern);
        maCarte->setBackgroundBrush(brush);
        maCarte->setSceneRect(QRectF(-200, -200, 700, 500));
        loadLevel1 = new QPushButton(centralwidget);
        loadLevel1->setObjectName(QStringLiteral("loadLevel1"));
        loadLevel1->setGeometry(QRect(0, 30, 141, 31));
        loadLevel1->setFont(font1);
        loadLevel2 = new QPushButton(centralwidget);
        loadLevel2->setObjectName(QStringLiteral("loadLevel2"));
        loadLevel2->setEnabled(true);
        loadLevel2->setGeometry(QRect(140, 30, 141, 31));
        loadLevel2->setFont(font1);
        quitter = new QPushButton(centralwidget);
        quitter->setObjectName(QStringLiteral("quitter"));
        quitter->setGeometry(QRect(670, 0, 131, 61));
        quitter->setFont(font1);
        choixDiff = new QComboBox(centralwidget);
        choixDiff->setObjectName(QStringLiteral("choixDiff"));
        choixDiff->setGeometry(QRect(430, 30, 141, 31));
        choixDiff->setFont(font1);
        choixDiff->setEditable(false);
        choixDiff->setFrame(true);
        InfoDiff = new QLabel(centralwidget);
        InfoDiff->setObjectName(QStringLiteral("InfoDiff"));
        InfoDiff->setGeometry(QRect(430, 0, 261, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("URW Chancery L"));
        font2.setPointSize(11);
        InfoDiff->setFont(font2);
        InfoGroup = new QLabel(centralwidget);
        InfoGroup->setObjectName(QStringLiteral("InfoGroup"));
        InfoGroup->setGeometry(QRect(10, 0, 371, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("URW Chancery L"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        InfoGroup->setFont(font3);
        bouttonPause = new QPushButton(centralwidget);
        bouttonPause->setObjectName(QStringLiteral("bouttonPause"));
        bouttonPause->setGeometry(QRect(580, 30, 87, 27));
        QFont font4;
        font4.setFamily(QStringLiteral("URW Chancery L"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        bouttonPause->setFont(font4);
        loadLevel3 = new QPushButton(centralwidget);
        loadLevel3->setObjectName(QStringLiteral("loadLevel3"));
        loadLevel3->setEnabled(true);
        loadLevel3->setGeometry(QRect(280, 30, 141, 31));
        loadLevel3->setFont(font1);
        commandes = new QLabel(centralwidget);
        commandes->setObjectName(QStringLiteral("commandes"));
        commandes->setGeometry(QRect(0, 620, 541, 51));
        QFont font5;
        font5.setFamily(QStringLiteral("URW Palladio L"));
        commandes->setFont(font5);
        imageDiamant = new QLabel(centralwidget);
        imageDiamant->setObjectName(QStringLiteral("imageDiamant"));
        imageDiamant->setGeometry(QRect(40, 70, 58, 17));
        imageDiamant->setPixmap(QPixmap(QString::fromUtf8("../build-untitled-Desktop-Debug/Images/BlueRupee_iconeTop.png")));
        nbRubis = new QLCDNumber(centralwidget);
        nbRubis->setObjectName(QStringLiteral("nbRubis"));
        nbRubis->setGeometry(QRect(10, 70, 64, 23));
        nbRubis->setSegmentStyle(QLCDNumber::Outline);
        infoFleche = new QLabel(centralwidget);
        infoFleche->setObjectName(QStringLiteral("infoFleche"));
        infoFleche->setGeometry(QRect(700, 630, 411, 16));
        QFont font6;
        font6.setFamily(QStringLiteral("URW Palladio L"));
        font6.setBold(false);
        font6.setWeight(50);
        infoFleche->setFont(font6);
        coeur1Plein = new QLabel(centralwidget);
        coeur1Plein->setObjectName(QStringLiteral("coeur1Plein"));
        coeur1Plein->setGeometry(QRect(100, 60, 41, 41));
        coeur1Plein->setPixmap(QPixmap(QString::fromUtf8("../build-Zelda_Beta-Desktop-Debug/Images/HeartContainerLoZ.png")));
        coeur2Plein = new QLabel(centralwidget);
        coeur2Plein->setObjectName(QStringLiteral("coeur2Plein"));
        coeur2Plein->setGeometry(QRect(140, 60, 51, 41));
        coeur2Plein->setPixmap(QPixmap(QString::fromUtf8("../build-Zelda_Beta-Desktop-Debug/Images/HeartContainerLoZ.png")));
        coeur3Plein = new QLabel(centralwidget);
        coeur3Plein->setObjectName(QStringLiteral("coeur3Plein"));
        coeur3Plein->setGeometry(QRect(180, 60, 41, 41));
        coeur3Plein->setPixmap(QPixmap(QString::fromUtf8("../build-Zelda_Beta-Desktop-Debug/Images/HeartContainerLoZ.png")));
        coeurVide1 = new QLabel(centralwidget);
        coeurVide1->setObjectName(QStringLiteral("coeurVide1"));
        coeurVide1->setGeometry(QRect(100, 60, 51, 41));
        coeurVide1->setPixmap(QPixmap(QString::fromUtf8("../build-Zelda_Beta-Desktop-Debug/Images/coeurVide.png")));
        coeurVide2 = new QLabel(centralwidget);
        coeurVide2->setObjectName(QStringLiteral("coeurVide2"));
        coeurVide2->setGeometry(QRect(180, 50, 51, 61));
        coeurVide2->setPixmap(QPixmap(QString::fromUtf8("../build-Zelda_Beta-Desktop-Debug/Images/coeurVide.png")));
        coeurVide3 = new QLabel(centralwidget);
        coeurVide3->setObjectName(QStringLiteral("coeurVide3"));
        coeurVide3->setGeometry(QRect(140, 50, 41, 61));
        coeurVide3->setPixmap(QPixmap(QString::fromUtf8("../build-Zelda_Beta-Desktop-Debug/Images/coeurVide.png")));
        logo = new QLabel(centralwidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(270, 240, 181, 121));
        logo->setPixmap(QPixmap(QString::fromUtf8("../build-untitled-Desktop-Debug/Images/logo.png")));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(790, 110, 491, 471));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        coeur4Plein = new QLabel(centralwidget);
        coeur4Plein->setObjectName(QStringLiteral("coeur4Plein"));
        coeur4Plein->setGeometry(QRect(220, 60, 41, 41));
        coeur4Plein->setPixmap(QPixmap(QString::fromUtf8("../build-Zelda_Beta-Desktop-Debug/Images/HeartContainerLoZ.png")));
        coeurVide4 = new QLabel(centralwidget);
        coeurVide4->setObjectName(QStringLiteral("coeurVide4"));
        coeurVide4->setGeometry(QRect(220, 50, 41, 61));
        coeurVide4->setPixmap(QPixmap(QString::fromUtf8("../build-Zelda_Beta-Desktop-Debug/Images/coeurVide.png")));
        MainWindow->setCentralWidget(centralwidget);
        choixDiff->raise();
        maCarte->raise();
        loadLevel1->raise();
        quitter->raise();
        loadLevel2->raise();
        InfoDiff->raise();
        InfoGroup->raise();
        bouttonPause->raise();
        loadLevel3->raise();
        commandes->raise();
        imageDiamant->raise();
        nbRubis->raise();
        infoFleche->raise();
        coeur1Plein->raise();
        coeur2Plein->raise();
        coeur3Plein->raise();
        coeurVide1->raise();
        coeurVide2->raise();
        coeurVide3->raise();
        logo->raise();
        label->raise();
        coeur4Plein->raise();
        coeurVide4->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1060, 26));
        menuOption_de_jeu = new QMenu(menubar);
        menuOption_de_jeu->setObjectName(QStringLiteral("menuOption_de_jeu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(loadLevel1, loadLevel2);
        QWidget::setTabOrder(loadLevel2, quitter);
        QWidget::setTabOrder(quitter, maCarte);

        menubar->addAction(menuOption_de_jeu->menuAction());
        menuOption_de_jeu->addAction(actionCharger_une_partie);
        menuOption_de_jeu->addAction(actionSauvegarder);
        menuOption_de_jeu->addAction(actionQuitter);

        retranslateUi(MainWindow);
        QObject::connect(loadLevel2, SIGNAL(clicked()), MainWindow, SLOT(monterNiveau2()));
        QObject::connect(quitter, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(loadLevel1, SIGNAL(clicked()), MainWindow, SLOT(monterNiveau1()));
        QObject::connect(choixDiff, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(choisirDifficulte(int)));
        QObject::connect(bouttonPause, SIGNAL(clicked()), MainWindow, SLOT(gererPause()));
        QObject::connect(loadLevel3, SIGNAL(clicked()), MainWindow, SLOT(monterNiveau3()));

        choixDiff->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCharger_une_partie->setText(QApplication::translate("MainWindow", "Charger une partie...", 0));
        actionSauvegarder->setText(QApplication::translate("MainWindow", "Sauvegarder", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        loadLevel1->setText(QApplication::translate("MainWindow", "Charger niveau 1", 0));
        loadLevel2->setText(QApplication::translate("MainWindow", "Charger niveau 2", 0));
        quitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        choixDiff->clear();
        choixDiff->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Difficult\303\251 facile", 0)
         << QApplication::translate("MainWindow", "Difficult\303\251 normale", 0)
         << QApplication::translate("MainWindow", "Difficult\303\251 dure", 0)
         << QApplication::translate("MainWindow", "Hero of Hyrule", 0)
        );
        InfoDiff->setText(QApplication::translate("MainWindow", "Changer la difficult\303\251 mettra le jeu en pause\n"
" et n\303\251cessitera d'appuyer sur \"Pause\".", 0));
        InfoGroup->setText(QApplication::translate("MainWindow", "Zelda - M2C : IHM en C++ avec QT", 0));
        bouttonPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        loadLevel3->setText(QApplication::translate("MainWindow", "Charger niveau 3", 0));
        commandes->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Mouvement : Z,Q,S,D || Attaque : M (\303\251p\303\251e) ; O (fl\303\250che, 2 max)</p></body></html>", 0));
        imageDiamant->setText(QString());
        infoFleche->setText(QApplication::translate("MainWindow", "Les fl\303\250ches peuvent \303\252tre utilis\303\251es pour changer la difficult\303\251", 0));
        coeur1Plein->setText(QString());
        coeur2Plein->setText(QString());
        coeur3Plein->setText(QString());
        coeurVide1->setText(QString());
        coeurVide2->setText(QString());
        coeurVide3->setText(QString());
        logo->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Bienvenue dans le Zelda de M2C !\n"
"Voici quelques r\303\250gles \303\240 connaitre :\n"
"- Les escaliers pour mener au niveau \n"
"suivant ne seront activ\303\251s qu'une fois \n"
"tous les rubis ramass\303\251s.\n"
"-Lorsque notre princesse est touch\303\251e\n"
"le fant\303\264me de Link apparait pour \n"
"la prot\303\251ger un court instant !\n"
"-Les DarknutRed ont besoin de deux \n"
"coups pour mourir, les SwordMoblins un \n"
"et le grand fant\303\264me 5 !\n"
"-Les DarknutsRed peuvent faire tomber\n"
"un coeur bonus pour le niveau(limite de \n"
"4,mais regen) et les SwordMoblin une \n"
"potion(regen de un coeur)\n"
"-Une image de fin s'affiche une \n"
"fois le jeu fini.\n"
"-Des ralentissements sont \303\240 pr\303\251voir\n"
" si pr\303\251sence de nombreux objets \n"
"dynamiques.", 0));
        coeur4Plein->setText(QString());
        coeurVide4->setText(QString());
        menuOption_de_jeu->setTitle(QApplication::translate("MainWindow", "Option de jeu", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
