/*	ELMANYANI AYOUB 11708129	TP Groupe 1		
  	FIJHI ISMAIL    11805303        TP Groupe 1               */


#include<stdio.h>
#include<stdlib.h>

typedef struct node_s{       /* Structure de l'arbre binaire */

	char symbol;		 	/* Symbol du caractère */
	int freq;		/* Fréquence d'apparition du caractère */
	struct node_s * fg;	/* Fils gauche */
	struct node_s * fd;	/* Fils droit */
}node;
	


node * creer_node(char s,int f);  /* Déclaration de la fonction creer_node qui crée une feuille à partir du symbol et sa fréquence d'apparition 
					passés en paramètre*/
