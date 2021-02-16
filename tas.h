/*	ELMANYANI AYOUB 11708129	TP Groupe 1		
  	FIJHI ISMAIL    11805303        TP Groupe 1               */


#include"node.h"          /* inclusion de la bibliothèque node */

typedef struct tas_s{		/* Structure du Tas */
	
	int m;			/* Nombre maximum d'éléments du Tas*/
	int n;			/* Nombre d'éléments courants du Tas*/
	node** tab;		/* Tableau contenant des éléments de type 'node *' */
}tas;


/* Déclaration des fonctions */

tas * inic_tas(int nbElements);      /* Cette fonction reçoit un entier avec lequel elle va allouer la mémoire pour un Tas */

int est_vide_tas(tas * nouveauT);	/* Cette fonction renvoie 1 si le tas passé en paramètre est vide, 0 sinon */

void inserer_tas(tas * nouveauT, node * nouveauN);	/* Cette fonction insère un élément de type 'node *' dans le Tas */

tas * saisie_alphabet();    /* Cette fonction demande à l'utilisateur le nombre de différents caractères d'une chaine, avec lequel elle va 
				initialiser le Tas, et puis demander à l'utilisateur chaque caractère et sa fréquence d'apparition , et après 
				les insérer dans le Tas */ 

node * supprimer_tas(tas * nouveauT);	/* Cette fonction renvoie le premier élément du Tas et l'actualise */








