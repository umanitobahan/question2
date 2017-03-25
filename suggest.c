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
        printf("-------%s ----\n", word);
}

void closeWord(char *fword, char *word, char *best, FILE *file){
        assert(file != NULL);
        int steps = 0;
	int close = 0;
        if(file != NULL){
                fword = fgets(fword, 100, file);
                if(fword != NULL){
                        steps = levenshtein(word, fword);
                        printf("%d\n", steps);
                        if(steps < 5){
                                result = insert(fword);
                                assert(result == true);
                                result = false;
                        }
                        close = steps;
                        best = strcpy(best, fword);
                        printf("%s\n", best);
                }
                fword = fgets(fword, 100, file);
                while(fword != NULL){
                        steps = levenshtein(word, fword);
                        printf("%d\n", steps);
                        if(steps < 5){
                                result = insert(fword);
                                assert(result == true);
                                result = false;
                        }
                        if(steps < close){
                                close = steps;
                                best = strcpy(best, fword);
                                printf("%s\n", best);
                        }
                        fword = fgets(fword, 100, file);
                }
        }

}



