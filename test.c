//-----------------------------------------
//NAME: Liu Han
//STUDENT NUMBER: 7694437
//COURSE: COMP 2160, SECTION: A01
//INSTRUCTOR: Franklin Bristow
//ASSIGNMENT: assignment 3, question 2
//
// REMARKS: Find the most closed word in the dictionary, and list words that less than 5 steps
//
//-----------------------------------------



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
	cleanTable();
	
	
	fclose(file); 
	return EXIT_SUCCESS;
}


