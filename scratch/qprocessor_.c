#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dot.h"

int myCompare (const void * a, const void * b ) {
   const char *pa = *(const char**)a;
   const char *pb = *(const char**)b;

   return strcmp(pa,pb);
}

int main( int argc, char *argv[] ) {
   FILE *output, *dos;
   hash ethos;
   sprintf( s, "%s.out", argv[2] );
   output = fopen( s, "w+" );
   sprintf( s, "%s.words", argv[2] );
   dos = fopen( s, "w+" );

   if( argc != 3 )
      printf( "\nIncorrect call, follow example:\n\t%s 60 data\n\n", argv[0] );

   file = fopen( argv[2], "r");

   while( ( ethos.car = fgetc( file ) ) != EOF )
   {
      wurd[0] = 0;
      while( ethos.car != ' ' && ethos.car != '\n' ) {
         if( ethos.car == EOF )
            break;
         strcat(wurd, &ethos.car);
         ethos.car = fgetc( file );
      }
 /*     *w = (char*) realloc(*w, ethos.count*sizeof(char*) );*/
      w[ethos.count++] = strdup( wurd );
      printf( "%s ", w[ethos.count-1] );

      fprintf( output, "%s ", wurd );
   }

   ethos.count = sizeof(w)/sizeof(char *);
   qsort( w, ethos.count, sizeof(char *), myCompare );
   ethos.count = 0;
   while( ethos.count < 98 )
      printf( "\n%s", w[ethos.count++] );

   putchar( '\n' );
   printf( "%d", ethos.count );
   fclose( output );
   fclose( file );
}

