#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "engine.h"




char best[100];


int main(int argc, char *argv[]){
	FILE *file = NULL;
	
	char word[100];
	char fword[100];
	int nodes;
	file = loadFile(argv[1]);
	getWord(word);
	closeWord(fword, word, best, file);
	nodes = size();
	printf("The closed is %s totally  %d words\n", best, nodes);
		

	fclose(file); 
	return EXIT_SUCCESS;
}

