# projet_C_code-huffman

I - Introduction : 
Le codage de Huffman est un algorithme de compression de données sans perte. Le codage de Huffman utilise un code à longueur variable pour représenter un symbole de la source (par exemple un caractère dans un fichier). Le code est déterminé à partir d'une estimation des probabilités d'apparition des symboles de source, un code court étant associé aux symboles de source les plus fréquents.  Un code de Huffman est optimal au sens de la plus courte longueur pour un codage par symbole, et une distribution de probabilité connue.    

II - Principe  : Le principe du codage de Huffman repose sur la création d'une structure d'arbre composée de nœuds.  On recherche tout d'abord le nombre d'occurrences de chaque caractère, chaque caractère constitue une des feuilles de l'arbre à laquelle on associe un poids égal à son nombre d'occurrences.  L'arbre est créé suivant un principe simple : on associe à chaque fois les deux nœuds de plus faibles poids, pour donner un nouveau nœud dont le poids équivaut à la somme des poids de ses fils. On réitère ce processus jusqu'à n'en avoir plus qu'un seul nœud : la racine. 
On associe ensuite par exemple le code 0 à chaque embranchement partant vers la gauche et le code 1 vers la droite.  
Pour obtenir le code binaire de chaque caractère, on remonte l'arbre à partir de la racine jusqu'aux feuilles en rajoutant à chaque fois au code un 0 ou un 1 selon la branche suivie. 

III - Objectif :  
L’objectif de ce projet est d’implémenter en langage C le codage binaire préfixe d’un ensemble de n caractères avec leur respective fréquence d’apparition qui sera saisie par l’utilisateur du programme.

IV - Description des fonctions implémentées :

creer_node(char ,int ) : Cette fonction crée une feuille à partir du symbole et sa fréquence d'apparition passés en paramètre.

inic_tas(int) : Cette fonction reçoit un entier avec lequel elle va allouer la mémoire  pour un Tas, en initialisant le nombre d’éléments courant à 0.

est_vide_tas(tas * ) : Cette fonction renvoie 1 si le tas passé en paramètre est vide, 0 sinon .

inserer_tas(tas *, node *) : Cette fonction insère un élément de type 'node *' dans le Tas qui sera un Tas minimum  en utilisant l’algorithme de tri croissant.

saisie_alphabet () : Cette fonction demande à l'utilisateur le nombre de différents caractères d'une chaine , avec lequel elle va initialiser le Tas, et puis demander à l'utilisateur chaque caractère et sa fréquence d'apparition , et après les insérer dans ce Tas .

supprimer_tas(tas * ) :  Cette fonction renvoie le premier élément du Tas et l'actualise , pour cela on enregistre le premier élément du tas contenant la basse fréquence, et puis on le remplace par le dernier élément, à l’aide de l’algorithme de tri croissant on le réorganise pour obtenir encore un Tas minimum, et finalement cette fonction retourne le premier élément enregistré.

creer_arbre (tas * ) : Cette fonction renvoie l'arbre préfixe des éléments du Tas  en utilisant l’algorithme de la construction de l’arbre de codage donné en énoncé du mini-projet qui est basé sur le principe du codage de Huffman qui repose sur la création d'une structure d'arbre composée de nœuds. (Veuillez regarder le principe de Huffman en haut )

est_feuille(node *) : Cette fonction renvoie 1 si l'arbre passé en paramètre est une feuille, 0 sinon .

imprimer_arbre(node * ) : Cette fonction récursive affiche l'arbre dans l'ordre infixe , elle n’affiche pas les nœuds sans symboles.

imprimer_tab(char * , int) : Cette fonction affiche le tableau enregistrant le code binaire d'un caractère.

imprimer_codes(node * , char *, int ) : Cette fonction récursive affiche le code binaire des caractères entrés par l'utilisateur en faisant un parcours infixe de l’arbre passé en paramètre, pour cela on utilise une variable iZero qui égale à 0, si on visite le fils gauche on ajoute au tableau la valeur ‘0’ en position de iZero, et on appel récursivement la fonction avec le fils gauche et l’index iZero + 1 , on fait pareil si l’on visite le fils droit , mais au lieu de ‘0’  on met ‘1’ et l’index iZero +1. 

supprimer_arbre(node ** ) : Cette fonction désalloue la mémoire allouée à l'arbre binaire, elle prend en paramètre l'adresse d'un arbre.

liberer_memoire_tas(tas **) : Cette fonction désalloue la mémoire allouée au Tas, elle prend en paramètre l'adresse d'un Tas .

V - Méthode d’exécution du programme :
L’utilisateur doit ouvrir le Terminal dans le dossier contenant le programme. Et puis taper dans le Terminal la commande : gcc -Wall -o main main.c Après taper la commande : ./main
