/*	ELMANYANI AYOUB 11708129	TP Groupe 1		
  	FIJHI ISMAIL    11805303        TP Groupe 1               */

#include"arbre.h"		/* Inclusion de la bibliothèque arbre */

#define traiter(param,param1)     printf ("\033[25;46m\t(%c:%d)\033[00m\n\n",param,param1)  /* Affichage du caractère et sa fréquence */

#define traiterBis(param)     printf ("\033[25;41m%c\033[00m",param)	/* Affichage du code binaire à l'aide d'une boucle 'for' */

#define MAX 1000		/* Définition d'une constante */


int main(int argc, char *argv[]){		/* FONCTION PRINCIPALE */


	tas * nouveauT = NULL;         /* Déclaration et initialisation d'un Tas */
	
	node * nouveauN = NULL;		/* Déclaration et initialisation d'un arbre */		

	char tabBol[MAX];	/* Déclaration d'un tableau qui va enregistrer le code binaire des caractères */
	
	int iZero = 0;		/* Déclaration et initialisation de l'indice de la racine de l'arbre */

	


	nouveauT = saisie_alphabet();	/* Le Tas nul nouveauT reçoit la fonction saisie_alphabet() qui demande à l'utilisateur le nombre de 	 
					différents caractères d'une chaine, avec lequel elle va créer le Tas, et puis demander à l'utilisateur 
					chaque caractère et sa fréquence d'apparition , et finalement les insérer dans le Tas */
	
	
	nouveauN = creer_arbre(nouveauT); /* L'arbre nul nouveauN reçoit la fonction creer_arbre(nouveauT) qui renvoie l'arbre préfixe des 
						éléments du Tas */


	
	printf("\n\n\t\t\t \033[25;42mImpression de l'arbre :\033[00m\n\n");

	imprimer_arbre(nouveauN); 	/* Impression de l'arbre dans l'ordre infixe */

	
	printf("\t\t\t \033[25;42mImpression des codes :\033[00m\n\n");

	imprimer_codes(nouveauN, tabBol, iZero);	/* Impression des codes binaires des caractères en faisant un parcours infixe */

	printf("\n\n\n");

	
	liberer_memoire_tas(&nouveauT);		/*  Désallocation de la mémoire allouée au Tas */
	
	
	printf("\t\t\t\t\t A BIENTÔT\n\n");
	printf("Made By : \n\n\n \t\t\t ELMANYANI AYOUB 11708129\n\t\t\t FIJHI ISMAIL    11805303\n\n");

	return 0;	/* sortir de la fonction principale */
	
}





node * creer_node(char s,int f){	/* Cette fonction crée une feuille à partir du symbole et sa fréquence d'apparition passés en paramètre*/

	node * nouveauN = (node*)malloc(sizeof(node)); /* Allocation de mémoire pour l'arbre nouveauN */

	nouveauN->symbol = s;	/* Enregistrement du symbole */
	nouveauN->freq = f;	/* Enregistrement de la fréquence d'apparition */
	
	
	/* Le fils gauche et le fils droit sont nuls puisque la fonction creer_node renvoie une feuille */
	nouveauN->fg = NULL;	
	nouveauN->fd = NULL;

	return nouveauN;	/* Retourner la feuille nouveauN */ 
};





tas * inic_tas(int nbElements){		/* Cette fonction reçoit un entier avec lequel elle va allouer la mémoire pour un Tas */

	tas * nouveauT = (tas*)malloc(sizeof(tas));	/* Allocation de mémoire pour le Tas nouveauT */

	(nouveauT->m) = nbElements;	/* Enregistrement du nombre maximum d'éléments de nouveauT */
	(nouveauT->n) = 0;		/* Initialiser le nombre d'éléments courants à 0 */
 
	(nouveauT->tab) = (node**)malloc(nbElements*sizeof(node)); /* Allocation de mémoire du tableau du Tas qui va contenir
									 des feuilles de type 'node *' */
	
	return nouveauT;	/* Retourner le Tas */
};






int est_vide_tas(tas * nouveauT){	/* Cette fonction renvoie 1 si le tas passé en paramètre est vide, 0 sinon */

	if( ((nouveauT->n) > 0) && (nouveauT->tab != NULL)) /* Si le Tas nouveauT contient des éléments ; retourner 0 */
		return 0;
	

	return 1;	/* Si nouveauT est vide ; retourner 1 */
};





void inserer_tas(tas * nouveauT, node * nouveauN){    /* Cette fonction insère un élément de type 'node *' dans le Tas qui sera un Tas minimum */

	nouveauT->tab[nouveauT->n] = nouveauN;	/* Ajout d'une feuille de type 'node *' */
	
	(nouveauT->n)++;	/* incrémentation de nombre d'éléments du Tas nouveauT */	
	
	int i ,j;	/* Déclaration de deux variables qu'on en aura besoin pour les deux boucles 'for' */


	/* Algorithme de tri croissant par rapport aux fréquences d'apparition des symboles des éléments de nouveauT */
 
	for (i = 0; i < (nouveauT->n); i++){	/* Pour chaque élément de nouveauT */
     
        	for(j = i; j < (nouveauT->n); j++){	/* On le compare par rapport aux autres */
        


			/* Si la fréquence du symbole d'un élément précèdant un autre est plus grande que celle de ce dernier */

			if((nouveauT->tab[j])->freq < (nouveauT->tab[i])->freq){ 
                                          
				node * temp = nouveauT->tab[i];			/* On les permute */
				nouveauT->tab[i] = nouveauT->tab[j];
				nouveauT->tab[j] = temp;
            		}
       		}
 
	}
	

	/* nouveauT est un Tas minimum */

};




tas * saisie_alphabet (){	/* Cette fonction demande à l'utilisateur le nombre de différents caractères d'une chaine, avec lequel elle va 
				initialiser le Tas, et puis demander à l'utilisateur chaque caractère et sa fréquence d'apparition , et après 
				les insérer dans le Tas */ 

	int nbrDifCarac; /* Déclaration de la variable qui va recevoir le nombre de différents caractères d'une chaine */
	char inutile;	/* Déclaration d'une variable qui va nous aider à éviter des problèmes lors de la saisie */



	/* Demander le nombre de différents caractères construisant la chaine */
 
        printf("\nVeuillez entrer le nombre de différents caractères construisant votre texte : ");
        scanf("%d",&nbrDifCarac);
        inutile = getchar();	

        tas * nouveauT = inic_tas(nbrDifCarac);	/* Initialiser le Tas nouveauT pour contenir nbrDifCarac élément de type 'node *' */
	
        int freq;	/* Déclaration d'une variable qui va recevoir la fréquence d'apparition du symbole */

        char carac;	/* Déclaration d'une variable qui va recevoir le caractère */
                
	for(int i = 0 ; i < nbrDifCarac ; i++){ 


		/* Demander le caractère */
        	printf("\nVeuillez entrer le caractère %d/%d : ",i+1,nbrDifCarac);
                carac = getchar();


		/*Demander sa fréquence d'apparition */
                printf("\n\n\tLe caractère '%c' est de fréquence de : ",carac);
                scanf("%d",&freq);

                inutile = getchar();
		printf("%c",inutile); /* Afficher un saut de ligne */


                inserer_tas(nouveauT, creer_node(carac,freq)); /* Insérer la feuille 'creer_node(carac,freq)' dans nouveauT */
                          

                }

        return nouveauT;	/* Retourner le Tas nouveauT */
};






node * supprimer_tas(tas * nouveauT){	/* Cette fonction renvoie le premier élément du Tas et l'actualise */

	if(est_vide_tas(nouveauT)) /* Si le Tas nouveauT est vide ; retourner NULL */
		return NULL;

	else{			/* Sinon */


		node * temp = nouveauT->tab[0];		/* Enregistrer l'élément contenant la plus basse fréquence */
		nouveauT->tab[0] = nouveauT->tab[(nouveauT->n)-1];	/* Remplacer le premier élément par le dernier */
		(nouveauT->n)--;	/* Décrémenter le nombre d'éléments courants */
	
	
		int i ,j;	/* Déclaration de deux variables qu'on en aura besoin pour les deux boucles 'for' */


		/* Algorithme de tri croissant par rapport aux fréquences d'apparition des symboles des éléments de nouveauT */
 
		for (i = 0; i < (nouveauT->n); i++){	/* Pour chaque élément de nouveauT */
     
        		for(j = i; j < (nouveauT->n); j++){	/* On le compare par rapport aux autres */
        


				/* Si la fréquence du symbole d'un élément précèdant un autre est plus grande que celle de ce dernier */

				if((nouveauT->tab[j])->freq < (nouveauT->tab[i])->freq){ 
                                          
					node * temp = nouveauT->tab[i];			/* On les permute */
					nouveauT->tab[i] = nouveauT->tab[j];
					nouveauT->tab[j] = temp;
            			}
       			}
 
		}
	

		/* nouveauT est un Tas minimum */
	
		return temp;	/* Retourner l'élément supprimé */

	}
};







node * creer_arbre (tas * nouveauT){	/* Cette fonction renvoie l'arbre préfixe des éléments du Tas */


	/* Algorithme de la construction de l'arbre de codage */

	while (nouveauT->n > 1){	/* Tant que le nombre d'éléments du Tas est strictement supérieur à 1 */

		node *z = (node*)malloc(sizeof(node));	/* Allocation de mémoire pour un arbre */
	
		node *x = supprimer_tas (nouveauT);	/* 'x' reçoit l'élément de type 'node *' du Tas contenant la plus basse fréquence */
		node *y = supprimer_tas (nouveauT);	/* 'y' reçoit l'élément de type 'node *' du Tas contenant la plus basse fréquence */
	
		
		z->fg = x;	/* Le fils gauche de l'arbre 'z' reçoit la feuille 'x' */
		z->fd = y;	/* Le fils droit de l'arbre 'z' reçoit la feuille 'y' */

		z->symbol = ' ';	/* Le père de 'x' et 'y' ne contient pas de symbole */
		z->freq = x->freq + y->freq; 	/* La fréquence du père est égale à la somme des fréquences des deux fils */

                inserer_tas(nouveauT, z);	/* Insérer le père dans le Tas nouveauT */

		/* nouveauT est toujours un Tas minimum */                        
                         
                }

		/* Donc le Tas nouveauT contient un seul élément qui est l'arbre de codage */
                
                return supprimer_tas (nouveauT);	/* Retourner l'arbre du codage */
};




int est_feuille(node * nouveauN){	/* Cette fonction renvoie 1 si l'arbre passé en paramètre est une feuille, 0 sinon */

	if((nouveauN->fg == NULL)&&(nouveauN->fd == NULL)) /* Si les deux fils sont nuls ; retourner 1*/
		return 1;

	return 0;	/* Sinon ; retourner 0 */
};



void imprimer_arbre(node * nouveauN){	/* Cette fonction affiche l'arbre dans l'ordre infixe */

	if(nouveauN != NULL){	/* Si l'arbre est non nul */
		
		/* Parcourir l'arbre dans l'ordre infixe */	
	
		imprimer_arbre(nouveauN->fg);	/* Parcourir le fils gauche */

		if(nouveauN->symbol != ' ')	/* Cette condition empêche les noeuds sans symbole d'être afficher */

			traiter(nouveauN->symbol,nouveauN->freq);	/* Affichage du symbole et sa fréquence */

		imprimer_arbre(nouveauN->fd);	/* Parcourir le fils droit */
	}
};



void imprimer_tab(char *tabBol, int n){		/* Cette fonction affiche le tableau enregistrant le code binaire d'un caractère */

	int i;
	
	for(i=0 ; i < n ; i++){

		traiterBis(tabBol[i]);		/* Affichage du tableau tabBol contenant le code binaire d'un caractère */
	}
	
	printf("\n");
	
};




void imprimer_codes(node * nouveauN, char *tabBol, int iZero){	/* Cette fonction affiche le code binaire des caractères entrés par 
								l'utilisateur*/
	
	/* iZero est initialisé à 0, puisque c'est l'indice de la racine */

	/* Parcourir l'arbre dans l'ordre infixe */

	if(nouveauN->fg){	/* Si le fils gauche existe */

		tabBol[iZero] = '0';	/* Enregistrer la valeur '0' dans le tableau de l'indice iZero */
	
		imprimer_codes(nouveauN->fg, tabBol, iZero+1);	/* Parcourir le fils gauche en ajoutant 1 à l'indice iZero */

	}



	if((nouveauN->symbol) != ' '){	/* Cette condition empêche les noeuds sans symbole d'être afficher */

		printf("\n\t%c : ", nouveauN->symbol);		/* Affichage du caractère */

		imprimer_tab(tabBol, iZero);	/* Affichage du code */
	}



	if(nouveauN->fd){	/* Si le fils droit existe */

		tabBol[iZero] = '1';	/* Enregistrer la valeur '1' dans le tableau de l'indice iZero */
	
		imprimer_codes(nouveauN->fd, tabBol, iZero+1);	/* Parcourir le fils droit en ajoutant 1 à l'indice iZero */

	}
};




void supprimer_arbre(node ** p_nouveauN){	/* Cette fonction désalloue la mémoire allouée à l'arbre binaire, elle prend en paramètre
							l'adresse d'un arbre  */

	/* Le passage de la racine par adresse est préférable, pour que l'arbre libéré ne provoquera pas d'erreur mémoire
		en cas d'utilisation */


	node * nouveauN = *p_nouveauN;	/* nouveauN reçoit la valeur de l'adresse p_nouveauN */ 
	
	if(!est_feuille(nouveauN)){	/* Si la racine n'est pas une feuille */
	
		supprimer_arbre(&nouveauN->fg);		/* Parcourir le fils gauche */

		supprimer_arbre(&nouveauN->fd);		/* Parcourir le fils droit */
		
	}
	
	free(nouveauN);		/* libérer la mémoire allouée à la feuille */
	
	*p_nouveauN = NULL; 	/* Pour plus de sûreté on met la feuille à NULL */
	
};



void liberer_memoire_tas(tas ** p_nouveauT){	/* Cette fonction désalloue la mémoire allouée au Tas, elle prend en paramètre
							l'adresse d'un Tas  */

	supprimer_arbre((*p_nouveauT)->tab); /* Désallouer la mémoire allouée à l'arbre binaire */
	
	free(*p_nouveauT);	/* Désallouer la mémoire allouée au Tas */
	
	*p_nouveauT = NULL;	/* Pour plus de sûreté on met le Tas à NULL */

};



