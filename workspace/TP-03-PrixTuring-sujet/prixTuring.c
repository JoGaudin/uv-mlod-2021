/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */

typedef struct Winner
{
	int year;
	char* name;
	char* description;
} Winner;

char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

Winner* readWinners(int nb_win){
	Winner* winners;
	winners = (Winner*)malloc(nb_win*sizeof(Winner));

	for(int i = 0; i < nb_win; i++){
		winners[i].year = scanLineAsInt();
		winners[i].name = scanLine();
		winners[i].description = scanLine();
	}
	
	return winners;
}

void printWinners(Winner* winners, int nb_win){
	
	for(int j = 0; j < nb_win; j++){
		printf("%d\n", winners[j].year);
		printf("%s\n", winners[j].name);
		printf("%s\n", winners[j].description);
	}
}

void infosAnnee(Winner* winners, int nb_win, int annee){
	for(int i = 0; i < nb_win; i++){
		if(winners[i].year == annee){
			printf("L'annee %d, le(s) gagnant(s) ont été : ", winners[i].year);
			printf("%s\n", winners[i].name);
			printf("Nature des travaux : ");
			printf("%s\n", winners[i].description);
		}
	}
}

int main(int argc, char *argv[])
{

	int nbGagnants = scanLineAsInt();
	printf("%i\n",nbGagnants);

	printWinners(readWinners(nbGagnants), nbGagnants);
	//infosAnnee(readWinners(nbGagnants), nbGagnants, atoi(argv[1]));

	return EXIT_SUCCESS;
}
