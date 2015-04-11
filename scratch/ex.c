#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myCompare (const void * a, const void * b ) {
       const char *pa = *(const char**)a;
           const char *pb = *(const char**)b;

               return strcmp(pa,pb);
}

int main() {
   char **wordlist = malloc(sizeof(char*)); /* pointer to
                                               pointer to words */
   int  i, numwords = 0;
   char *testwords[] = { "hello", "there", "folks", "in",
      "1840" };
   wordlist[0] = strdup( testwords[0]);
   /* This will show how you can add words to the array of pointers */
   for( i = 1; i < sizeof( testwords ) / sizeof( testwords[ 0 ] ); i++ )
   {
      /* Expand our array of pointers by one pointer's
       * worth */
      wordlist = realloc( wordlist, (numwords + 1) * sizeof( char * ) );
      /* Make a duplicate of the word and save the
       * pointer to it */
      wordlist[ numwords ] = strdup( testwords[ i ] );
      numwords++;
   }
   printf( "Added %d words to the array and they are:\n", numwords );

   qsort( wordlist, sizeof(wordlist)/sizeof(char *), sizeof(char *), myCompare );

   for( i = 0; i < numwords; i++ )
      printf( "%s\n", wordlist[ i ] );

   return( 0 );
}
