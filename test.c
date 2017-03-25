#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "engine.h"




char best[100];


//void moreWords();

int main(int argc, char *argv[]){
	FILE *file = NULL;
	char word[100];
	char fword[100];
	int nodes;
	char ch;
	file = loadFile(argv[1]);
	printf("What word should I check? ");
	getWord(word);
	printf("\n");
	closeWord(fword, word, best, file);
	printf("Did you mean... %s", best);
	printf("?\n");
	nodes = size();
	printf("There are %d other similar words, would you like to see them? (y/n)", nodes-1);
	ch = getchar();
	if(ch == 'y'){

}
	moreWords();

	fclose(file); 
	return EXIT_SUCCESS;
}

/*void moreWords(){
	char ch = getchar();
        if(ch == 'y'){
                printf("\n");
                printf("%s\n", firstItem());
                for(int i=1; i<10; i++){
                        printf("%s\n",nextItem());
                }
        }
}*/

