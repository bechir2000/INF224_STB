## Projet INF224
Ce projet est réalisé par BAAZIZ Bechir.
Ce projet contient deux programmes :
- Un programme cpp qui est le serveur 
- Un programme java swing le client.


## Execution 
Pour compiler et éxecuter le projet :
- Lancer le serveur : aller au dossier cpp puis taper 'make run'
- Lancer le client : aller au dossier swing puis taper 'make run'

REMARQUE : Il faut lancer le serveur avant le client !! 
REMARQUE : le client et le serveur communiquent via socket qui utilise 
le port 3331, pour changer le port, il faut changer la variable PORT 
dans le fichier server.cpp du projet cpp et aussi la variable DEFAULT_PORT 
dans le fichier Client.java du projet swing.

La communication ente client-serveur ce fait par des requêtes et des réponses.
le client java swing peut envoyer des requetes pour :

- Chercher un multimedia : il faut écrire le nom du multimedia(sans terminaison 
comme .jpg ou .mp4 ) dans la barre de recherche et puis appuyer sur le bouton 
"Search Multimedia".

- Chercher un group: taper le nom du group puis appuyer sur le bouton "Search Group".

- Jouer un multimedia: taper le nom du multimedia puis appuyer sur le bouton "Play".

- Lister tout les multimedias : appuyer sur le bouton "List All Files".

Dans ce projet, il existe dejà 3 fichiers: une photo avec le nom "Paris" , une video avec le nom "Lisbonne" 
et un film avec le nom "BB". 
Ces fichiers appartiennent à un groupe "vacances".


## Réponses aux questions 

Etape 4 : 
- Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?
C'est une methode abstraite ou virtuelle pure.
Pour la déclarer il faut mettre au debut le mot clé virtual et la mettre =0 à la fin.
exemple : virtual void play() const =0;

Etape 5 : 
- Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
C'est le polymorphisme.

- Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?
il faut utiliser des pointeurs et déclarer la methode virtuelle dans la classe de base.

- Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou 
des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
Le tableau doit contenir des pointeurs vers des objets (Multimedia*) plutôt que des 
objets. Cela permet de traiter tous les objets dérivés de manière uniforme, et les 
fonctions virtuelles seront appelées correctement. En C++, l'utilisation des pointeurs
est nécessaire pour permettre le polymorphisme, par contre en java, le polymorphisme est 
géré automatiquement.

Etape 7 : 
- Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin 
qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?
C'est la classe Film, Il  faut appeler delete dans le destructeur.

- La copie d'objet peut également poser problème quand ils ont des variables d'instance 
qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?
une simple copie des valeurs des pointeurs ne copie que les adresses mémoire pointées, 
et non les données auxquelles les pointeurs font référence. Cela peut entraîner des 
comportements indésirables. Solution : Définir un constructeur de copie personnalisé.

Etape 8 :
- On rappelle aussi que la liste d'objets doit en fait être une liste de 
pointeurs d'objets. Pourquoi ?
Pour assurer le polymorphysme.


Etape 10 :
- Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets 
puisse en créer de nouveaux ?
Pour empêcher la création d'objets en dehors des méthodes prévues par la classe 
elle-même, on peut utiliser constructeur privé.


