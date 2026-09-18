//
// Helper routines for the OpenMP set example.
//
#ifndef SET_OPS_H
#define SET_OPS_H

#include <stdio.h>
#include <stdlib.h>

int setSize;                 // The current size of the set = number of items it contains.
int maxSetSize;              // The maximum size for the set.
int *set;                    // The set itself, an array of size maxSetSize.

//
// Initialise the set to the given maximum size.
// Returns 0 if successful, -1 for an allocation error.
//
int initSet( int maxSize )
{
    set = (int*)malloc( maxSize * sizeof(int) );
    if( set==NULL ) return -1;

    setSize = 0;
    maxSetSize = maxSize;
    return 0;
}

//
// Destroy the set (i.e. delete all associated resources).
//
void destroySet()
{
    free( set );
    set = NULL;
    setSize = 0;
    maxSetSize = 0;
}

//
// Print the set.
//
void printSet()
{
    int i;
    for( i=0; i<setSize; i++ )
        printf( "%d ", set[i] );
    printf( "\n" );
}

#endif