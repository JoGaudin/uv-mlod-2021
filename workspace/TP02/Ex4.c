#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Ex4.h"

enum Mois{
    janvier = 1,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
};

struct Date
{
    int jour;
    enum Mois mois;
    int annee;
};
typedef enum Mois Mois;
typedef struct Date Date;



void initialiseDate(Date *d){
    printf("Jour :\n");
    scanf("%i", &d->jour);
    printf("Mois :\n");
    scanf("%i", (int *)&d->mois);
    printf("Annee :\n");
    scanf("%i", &d->annee);
}

void afficheDate(Date *d){
    char *Mois;
    switch (d->mois)
    {
    case 1:
        Mois = "janvier";
        break;
    case 2:
        Mois = "février";
        break;
    case 3:
        Mois = "mars";
        break;
    case 4:
        Mois = "avril";
        break;
    case 5:
        Mois = "mai";
        break;
    case 6:
        Mois = "juin";
        break;
    case 7:
        Mois = "juillet";
        break;
    case 8:
        Mois = "août";
        break;
    case 9:
        Mois = "septembre";
        break;
    case 10:
        Mois = "octobre";
        break;
    case 11:
        Mois = "novembre";
        break;
    case 12:
        Mois = "décembre";
        break;    
    }
    printf("%i %s %i\n", d->jour, Mois, d->annee);
}

Date creerDateParCopie(){
    Date e;
    printf("Jour :\n");
    scanf("%i", &e.jour);
    printf("Mois :\n");
    scanf("%i", (int *)&e.mois);
    printf("Annee :\n");
    scanf("%i", &e.annee);
}

int main(){

    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);
    
    Date e;
    e = creerDateParCopie();
    afficheDate(&d);


    return 0;
}

