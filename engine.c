#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "engine.h"

//Linked list node definition
typedef struct NODE Node;

struct NODE{
    char *string;
    Node *next;
};


static Node *top = NULL;
static int numNodes = 0;

// used to track where we are for the list traversal methods
static Node *traverseNode = NULL;

int size( )
{
    return numNodes;
}

// add an element to the beginning of the linked list
Boolean insert( char const * const new_string )
{
    assert(new_string != NULL);
    Boolean rc = true;
    Node *newNode = NULL;
    
    newNode = (Node *)malloc( sizeof( Node ) );
    assert(newNode != NULL);
    newNode->next = top;
    top = newNode;
    
    // note that we need to have space for the string as well!
    newNode->string = (char *)malloc( strlen(new_string) + 1 );
    assert(newNode->string != NULL);
    strcpy( newNode->string, new_string );
    assert(strlen(newNode->string) == strlen(new_string));
    assert(newNode->string[strlen(new_string)] == '\0');
    
    numNodes++;
    
    return rc;
}


// remove an element with the given string
Boolean delete( char const * const target )
{
    assert(target != NULL);
    Boolean deleted = false;
    Node *curr = top;
    Node *prev = NULL;
    
    while ( curr != NULL && strcmp( target, curr->string ) != 0 )
    {
        prev = curr;
        curr = curr->next;
    }
    
    if ( curr != NULL )
    {
        if ( prev != NULL )
            prev->next = curr->next;
        else
            top = curr->next;
        
        free( curr->string );
        free( curr );
        deleted = true;
        numNodes--;
    }
    
    return deleted;
}

// tells us whether or not the given string is in the list
Boolean search( char const * const target )
{
    assert(target != NULL);
    Boolean found = false;
    Node *curr = top;
    
    while ( curr != NULL && !found )
    {
        if ( strcmp( target, curr->string ) == 0 )
        {
            found = true;
        }
        
        else
        {
            curr = curr->next;
        }
    }
    
    return found;
}


// starts a list traversal by getting the data at top
char * firstItem()
{
    assert(top != NULL);
    traverseNode = top->next;
    
    return top->string;
}


// gets the data at the current traversal node and increments the traversal
char * nextItem()
{
    char *item = NULL;
    
    // no need to go past the end of the list...
    if ( traverseNode != NULL )
    {
        item = traverseNode->string;
        traverseNode = traverseNode->next;
    }
    
    return item;
}


unsigned int
levenshtein(const char *a, const char *b) {
    unsigned int length = strlen(a);
    unsigned int bLength = strlen(b);
    unsigned int *cache = calloc(length, sizeof(unsigned int));
    unsigned int index = 0;
    unsigned int bIndex = 0;
    unsigned int distance;
    unsigned int bDistance;
    unsigned int result;
    char code;

    /*
     * Shortcut optimizations / degenerate cases.
     */

    if (a == b) {
        return 0;
    }

    if (length == 0) {
        return bLength;
    }

    if (bLength == 0) {
        return length;
    }

    /*
     * initialize the vector.
     */

    while (index < length) {
        cache[index] = index + 1;
        index++;
    }

    /*
     * Loop.
     */
     while (bIndex < bLength) {
        code = b[bIndex];
        result = distance = bIndex++;
        index = -1;

        while (++index < length) {
            bDistance = code == a[index] ? distance : distance + 1;
            distance = cache[index];

            cache[index] = result = distance > result
                ? bDistance > result
                    ? result + 1
                    : bDistance
                : bDistance > distance
                    ? distance + 1
                    : bDistance;
        }
    }

    free(cache);

    return result;
}


