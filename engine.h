#ifndef _ENGINE_H
#define _ENGINE_H

	typedef enum BOOL { false, true } Boolean;
        int size();
        Boolean insert(char const * const new_string);
        Boolean delete(char const * const target);
        Boolean search(char const * const target);
        char * firstItem();
        char * nextItem();
	unsigned int levenshtein(const char *a, const char *b);
	FILE *loadFile(char *name);
	void getWord(char *word);
	void closeWord(char *fword, char *word,char *best,  FILE *file);

#endif
