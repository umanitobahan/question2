#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "engine.h"

static Boolean result = false;


FILE *loadFile(char *name){
        FILE *file = NULL;
        assert(name != NULL);
        if(name != NULL){
                file = fopen(name, "r");
        }
        assert(file != NULL);
        return file;
}

void getWord(char *word){
        int i = 0;
        scanf("%s", word);

        while(word[i]){
                while(isalpha(word[i]) == 0){
                        int a = i;
                        while(word[a]){
                                word[a] = word[a+1];
                                a++;
                        }
                }
                i++;
        }

        i = 0;
        while(word[i]){
                word[i] = tolower(word[i]);
                i++;
        }
}

void closeWord(char *fword, char *word, char *best, FILE *file){
        assert(file != NULL);
        int steps = 0;
	int close = 0;
        if(file != NULL){
                fword = fgets(fword, 100, file);
                if(fword != NULL){
                        steps = levenshtein(word, fword);
                        if(steps < 5){
                                result = insert(fword);
                                assert(result == true);
                                result = false;
                        }
                        close = steps;
                        best = strcpy(best, fword);
                }
                fword = fgets(fword, 100, file);
                while(fword != NULL){
                        steps = levenshtein(word, fword);
                        if(steps < 5){
                                result = insert(fword);
                                assert(result == true);
                                result = false;
                        }
                        if(steps < close){
                                close = steps;
                                best = strcpy(best, fword);
                        }
                        fword = fgets(fword, 100, file);
                }
        }

}


void moreWords(){
	int number = 1;
	int nodes = size();
        char ch = getchar();
        if(ch == 'y'){
                printf("\n");
                printf("%s\n", firstItem());
                for(int i=1; i<10; i++){
                        printf("%s\n",nextItem());
                }
		number += 10;
		while(number < nodes){
			ch = getchar();
			if(ch == 'y'){
			for(int i=0; i<10; i++){
				printf("%s\n",nextItem());
			}		
			number += 10;
			}
			else if(ch == 'n'){
				number = nodes +1;
			} 
			else{
				printf("Please enter 'y' or 'n' : ");
			}
	
        }
	}
	else if(ch == 'n'){
	}
	else{
		printf("Please enter 'y' or 'n' : ");
	}
}

