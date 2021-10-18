#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int main(int argc, char *argv[])
{
    if( argc >= 2){
        char fileName[] = argv[1];
        FILE* f;
        f = fopen(fileName, "r");
    }
    
	

	return EXIT_SUCCESS;
}
