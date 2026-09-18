//
// Helper routines for the MPI histogram example.
//
#ifndef HISTOGRAM_IO_H
#define HISTOGRAM_IO_H

#include <stdio.h>
#include <stdlib.h>

//
// Read the whole file into memory. Appends spaces so the total size is a
// multiple of numProcs. Returns NULL on error. The result must be free()'d.
//
char *readText( const char *filename, int *totalChars, int numProcs )
{
	FILE *fp = fopen( filename, "r" );
	if( fp==NULL )
	{
		printf( "Could not open file '%s'.\n", filename );
		return NULL;
	}

	fseek( fp, 0, SEEK_END );
	long fileSize = ftell( fp );
	fseek( fp, 0, SEEK_SET );

	int padding = (numProcs - (fileSize % numProcs)) % numProcs;
	int size = (int)fileSize + padding;
	if( size==0 ) size = numProcs;			// Avoid a zero-size allocation for an empty file.

	char *text = (char*)malloc( size * sizeof(char) );
	if( text==NULL )
	{
		fclose( fp );
		return NULL;
	}

	if( fileSize>0 && fread( text, 1, fileSize, fp ) != (size_t)fileSize )
	{
		free( text );
		fclose( fp );
		return NULL;
	}

	int i;
	for( i=0; i<padding; i++ )
		text[fileSize+i] = ' ';

	fclose( fp );
	*totalChars = size;
	return text;
}

//
// Map an alphabetic character to its letter code (0-25); returns -1 otherwise.
// Case is not considered (i.e. 'a' is the same as 'A').
//
int letterCodeForChar( char c )
{
	if( c>='a' && c<='z' ) return c - 'a';
	if( c>='A' && c<='Z' ) return c - 'A';
	return -1;
}

//
// Print a letter-count histogram.
//
void saveHist( int *hist, int size )
{
	int i;
	for( i=0; i<size; i++ )
		printf( "'%c': %d\n", 'a'+i, hist[i] );
}

#endif