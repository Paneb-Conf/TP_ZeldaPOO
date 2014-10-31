TP_ZeldaPOO
===========

<h3>Rendu concernant IHM en C++ avec QTCreator</h3>
ESME Sudria

Liste des dossiers (en gras ceux réellement importants) :
<ul>
<li><b>00_Release_Windows</b></li>
<li>00_build-Zelda_Beta-Desktop-Release_Ubuntu x64</li>
<li>Affichage normal</li>
<li><b>Images</b></li>
<li>Release_UBUNTU_Qmake__ -r -spec linux-g++-64</li>
<li><b>Sources</b></li>
<li>build-Zelda_Beta-Desktop-Release_Ubuntu x64</li>
<li>README.md</li>
</ul>
<br><br>
Contenu du Readme :
<ol>
<li>Instructions de lancement</li>
<li>Informations diverses</li>
<li>Historique des mises en ligne</li>
</ol>
<h1>1. Instructions de lancement</h1>
<h2>DANS TOUS LES CAS LE DOSSIER IMAGE DOIT SE TROUVER A L'ENROIT OU S'EXECUTE L'APPLICATION</h2>
Par exemple sous Windows le dossier Images doit être au même niveau que Zelda_Windows.exe, platforms, etc...
Les messages d'erreur indiquant les ressources manquantes (et le dossier où elles devraient être) ne sont disponibles que par lancement à la console.

<h3>Sous Windows</h3>
Il suffit de télécharger le contenu du dossier <b>00_Release_Windows</b>, qui contient tous les fichiers nécessaire à bonne exécution de l'application (.dll). Il suffit ensuite de double cliquer sur Zelda_Windows.exe pour que le jeu se lance (se référer au dossier en ligne <u>Affichage normal</u> pour savoir si toutes les ressources ont bien été trouvées.<br>
Note pour Windows : les sources disponibles en ligne refuseront de se compiler, en raison de deux lignes de code ou la taille de deux tableaux est alloués en fonction d'autres variables entière. Pour la release sous Windows le code source a donc été modifié afin d'intégrer des tableaux compatibles. Cependant la manière dont est allouée la taille sous Ubuntu étant plus soignée, c'est ce code là qui est en ligne (et qui ne compilera donc pas sous Windows mais sur Ubuntu oui, OS X n'ayant pas été testé je n'en sais rien).

<h3>Sous Ubuntu</h3>
Si la release disponible dans le dossier <b>00_build-Zelda_Beta-Desktop-Release_Ubuntu x64</b> fonctionne sous votre machine, tant mieux. Le cas contraire, voici comment procéder en repassant par QtCreator et les fichiers sources originaux :<br>
	-Générez un nouveau projet sur QTCreator de type Application, de sous type Qt Widgets Application. Nommez-le et placez-le comme vous voulez.<br>
-Copiez ensuite dans ce dossier tout le contenu du dossier sources (on vous demandera d'écraser le main et le ui, dites oui).<br> 
-Clic droit dans QTCreator sur le projet, puis Add existing files, Ctrl+A et ajoutez-les tous (en déselectionnant si vous préférez les .pro).<br>
-Clic droit sur le projet, clean project, puis run QMake.<br>
-Ctrl+B pour build le projet.<br>
Dans le nouveau dossier créé après votre build (à priori build-VotreNom-Desktop-Debug ou build-VotreNom-Desktop-Release selon le mode d'assemblement de Qt), placez le
dossier image. Des messages d'erreurs s'afficheront si les ressources ne sont pas trouvées (uniquement si le programme est lancé en mode console ou dans l'output de Qt).
<br>-Ctrl+R pour lancer l'application.<br><br>
<h3>2. Informations diverses</h3>
Commande : Z,Q,S,D (les déplacement en diagonales sont sur A,E,W,C). Attaque épée : M, Attaque flèche : O.
 Le jeu considère comme de la triche de charger directement les niveaux 2 et 3. Pour gagner il faut commencer du niveau un.<br>
 Prendre tous les rubis activent les escaliers. Au dernier niveau ils ne servent pour l'instant à rien. <br>
 Le nombre de flèche est limité à 2 (elles font autant de dégât qu'un coup d'épée).<br>
 Les DarknutRed peuvent laisser tomber un coeur bonus, qui fera monter votre nombre de coeur à 4 ainsi que régénera totalement votre santé.<br>
 Les SwordMoblins peuvent laisser tomber une potion qui vous restaurera un coeur. <br>
 Il est impossible pour les créatures ou les flèches de passer à travers les lampes. Les escaliers et les rubis ont par contre leur collision de désactivée.<br>
 Deux fins sont disponibles en fonction de votre manière de jouer aux jeux vidéos...<br>
 Les déplacements des créatures sont totalement aléatoires et ne ciblent pas spécifiquement le joueur.<br>
 En raison de la conception même du jeu (double timer, un sur les créature l'autre sur Zelda), il est possible que la mise à jour des animations, notamment sur l'icone fantôme de Link soit un peu décalé.<br>
 Si le jeu semble se comporter de manière étrange (changement de difficulté liée à l'appuis sur touche, dépause-pause succéssive, etc) l'appui sur le bouton pause permet de remettre à plat le système de gestion de la fenêtre.
 
<br>
<h3>3. Historique des mises en ligne</h3>
29.10.2014 :<br>
Mis en ligne version Martin T. Ajout des flèches + mise à jour paramétre cap initial de notre héros.<br>
28.10.2014 :<br>
Mis en ligne version Martin T. Avec gestion des attaques par leur direction (opposées + biais).<br>
27.10.2014 :<br>
Mis en ligne version Martin T. Coeur bonus dispo lvl 2 et 3 (respectivement 1 et 2). La vie passe à 4 + fullregen.


