//Compilation
// gcc -W -Wall linkedListOfMusic.c mySpitofy.c ../V1/linkedList.c  -o mySpitofy

//Execution
// ./mySpitofy > out.txt

//Diff
// diff out.txt music.csv

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "linkedListOfMusic.h"

Music* readMusic(char* line){
    Music* music = (Music *)malloc(sizeof(Music));
    music->Name = strdup(strsep(&line, ",\n"));
    music->Artist = strdup(strsep(&line, ",\n"));
    music->Album = strdup(strsep(&line, ",\n"));
    music->Genre = strdup(strsep(&line, ",\n"));
    music->Disc_Number = strdup(strsep(&line, ",\n"));
    music->Track_Number = strdup(strsep(&line, ",\n"));
    music->Year = strdup(strsep(&line, ",\n"));

    return music;
}

Liste readPlaylist(FILE* csv){
    Liste l = NULL;
    char *line;
    Music* k;

    line = calloc(256,sizeof(char));
    while (fgets(line, 256, csv) != NULL){
        k = readMusic(line);
        l = ajoutFin_i(k, l);
    }
    free(line);

    return l;    
}

int main(){
    
    Liste listmusic;

    char fileName[] = "music.csv";
    FILE* f;
    if( (f=fopen(fileName,"r")) == NULL) {
        printf ("Code de l'erreur : %d\n", errno);
        return EXIT_FAILURE; 
    }

    listmusic = readPlaylist(f);

    //listmusic = readYear(listmusic);

    afficheListe_i(listmusic);
    detruire_i(listmusic);
    fclose(f);
    

    return EXIT_SUCCESS;
}

    
