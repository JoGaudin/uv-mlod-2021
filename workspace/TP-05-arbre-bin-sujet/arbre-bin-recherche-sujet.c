#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a){
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire arbre;
	arbre = malloc(sizeof(arbre));
	arbre->val = e;
	arbre->filsDroit = NULL;
	arbre->filsGauche = NULL;
	return arbre;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	if(estVide(a)){
		return creer(e);
	}

	if(a->val == e){
		return a;
	}

	ArbreBinaire arbretemp, noeudtemp = a;

	while(!estVide(noeudtemp)){
		if(a->val == e){
			return a;
		}

		if(e > arbretemp->val){
			noeudtemp = arbretemp->filsDroit;
		}else{
			noeudtemp = arbretemp->filsGauche;
		}

		arbretemp = noeudtemp;
		
	}

	if(e > arbretemp->val){
		arbretemp->filsDroit = creer(e);
	}else{
		arbretemp->filsGauche = creer(e);
	}
	
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	ArbreBinaire temp = NULL;

	if(estVide(a)){
		return creer(e);
	}
		

	if(a->val == e){
		return a;
	}
		
	if(e > a->val){
		a->filsDroit = insere_r(a->filsDroit, e);
	}else
		a->filsGauche = insere_r(a->filsGauche, e);

	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
		if(estVide(a)){
			return 0;
		}else{
			return nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit) + 1;
		}
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if(estVide(a)){
		return -1;
	}

	if(a->val == e){
		return 1;
	}

	int f_gauche = profondeur(a->filsGauche, e);
	int f_droit = profondeur(a->filsDroit, e);

	if(f_gauche != -1){
		return f_gauche + 1;
	}
	if(f_droit != -1){
		return f_droit + 1;
	}

		return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(estVide(a)){
		return 0;
	}

	int hauteur_gauche = nombreDeNoeud(a->filsGauche) + 1;
	int hauteur_droit = nombreDeNoeud(a->filsDroit) + 1;

	if(hauteur_gauche>hauteur_droit){
		return hauteur_gauche;
	}else{
		return hauteur_droit;
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	if(estVide(a) || (a->val == elem)){
		return NULL;
	}

	if(a->val > elem){
		if(!estVide(a->filsGauche)){
			if(a->filsGauche->val == elem){
				return a;
			}else{
				return pere(a->filsGauche, elem);
			}
		}else{
			return NULL;
		}
	}else{
		if(!estVide(a->filsDroit)){
			if(a->filsDroit->val == elem){
				return a;
			}else{
				return pere(a->filsDroit, elem);
			}
		}else{
			return NULL;
		}
	}
}


void afficheRGD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("%i", a->val);
		if(!estVide(a->filsGauche)){
			afficheGRD_r(a->filsGauche);
		}
		if(!estVide(a->filsDroit)){
			afficheGRD_r(a->filsDroit);
		}
	}else{
		printf("L'arbre est vide");
	}
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		if(!estVide(a->filsGauche)){
			afficheGRD_r(a->filsGauche);
		}
		printf("%i", a->val);
		if(!estVide(a->filsDroit)){
			afficheGRD_r(a->filsDroit);
		}
	}else{
		printf("L'arbre est vide");
	}
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a)){
		if(!estVide(a->filsGauche)){
			afficheGRD_r(a->filsGauche);
		}
		if(!estVide(a->filsDroit)){
			afficheGRD_r(a->filsDroit);
		}
		printf("%i", a->val);
	}else{
		printf("L'arbre est vide");
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	if(estVide(a)){
		return NULL;
	}
	if(estVide(a->filsGauche)){
		return a;
	}
	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	if(estVide(a)){
		return NULL;
	}
	if(estVide(a->filsDroit)){
		return a;
	}
	return max(a->filsDroit);
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){
	if(estVide(a)){
		return NULL;
	}

	if(a->val == elem){
		return a;
	}

	if(a->val > elem){
		return recherche_r(a->filsGauche, elem);
	}else{
		return recherche_r(a->filsDroit, elem);
	}

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{
	ArbreBinaire cherche = recherche_r(a, x);

	if(estVide(cherche)){
		return a;
	}
	
	detruire_r(cherche);
	return NULL;
}

void detruire_r(ArbreBinaire a){
	detruire_r(a->filsDroit);
	detruire_r(a->filsGauche);
	free(a);
	a = NULL;
}

