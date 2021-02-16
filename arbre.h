/*	ELMANYANI AYOUB 11708129	TP Groupe 1		
  	FIJHI ISMAIL    11805303        TP Groupe 1               */

#include"tas.h"			/* Inclusion de la bibliothèque tas */





/* Déclaration des fonctions */

node * creer_arbre(tas * nouveauT);	/* Cette fonction renvoie l'arbre préfixe des éléments du Tas */

int est_feuille(node * nouveauN);	/* Cette fonction renvoie 1 si l'arbre passé en paramètre est une feuille, 0 sinon */

void imprimer_arbre(node * nouveauN);	/* Cette fonction affiche l'arbre dans l'ordre infixe */

void imprimer_tab(char *tabBol, int n);		/* Cette fonction affiche le tableau enregistrant le code binaire d'un caractère */

void imprimer_codes(node * nouveauN, char *tabBol, int iZero);	/* Cette fonction affiche le code binaire des caractères entrés par 
								l'utilisateur*/


void supprimer_arbre(node ** p_nouveauN); /* Cette fonction désalloue la mémoire allouée à l'arbre binaire */

void liberer_memoire_tas(tas ** nouveauT); /* Cette fonction désalloue la mémoire allouée au Tas */



