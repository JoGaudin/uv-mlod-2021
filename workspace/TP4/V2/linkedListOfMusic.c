
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListOfMusic.h"

// ============
// Definitions of external functions
// ============

void afficheElement(Element e) {
	Music* music = (Music *)e;
	printf("%s,%s,%s,%s,%s,%s,%s\n", music->Name, music->Artist, music->Album, music->Genre, music->Disc_Number, music->Track_Number, music->Year);
}

void detruireElement(Element e) {
	free(e);
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return true;
}

Liste readYear(Liste list){

	if(estVide(list)){
		return list;
	}

	Liste test = list, after = list, precedent = list, oldprev = list;

	while(!estVide(test)){

		//On teste si l'année de la première valeur est plus vieille que la seconde valeur
		if(strcmp(((Music *)test->val)->Year, ((Music *)after->val)->Year) <= 0){
			oldprev = precedent;
			after = test;
		}
		precedent = test;
		test = test->suiv;
	}

	Liste tampon;
    if (after != list){
        oldprev->suiv = list;
        tampon = list->suiv;
        list->suiv = after->suiv;
        after->suiv = tampon;
    }


	after->suiv = readYear(after->suiv);

	return after;
}