//Définir type Music
//3 functions externes dans le c
//Dans un main, crée la struct music (caster avec Music*)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../V1/linkedList.h"

typedef struct Music
{
    char* Name;
    char* Artist;
    char* Album;
    char* Genre;
    char* Disc_Number;
    char* Track_Number;
    char* Year;
}Music;

void afficheElement(Element e);

void detruireElement(Element e);

bool equalsElement(Element m1, Element m2);

Liste readYear(Liste list);