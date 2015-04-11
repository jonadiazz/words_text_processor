#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dot.h"

int main( int argc, char *argv[] ) {
   FILE *output;
   hash ethos;
   sprintf( s, "%s.out", argv[2] );
   output = fopen( s, "w+" );

   if( argc != 3 )
      printf( "\nIncorrect call, follow example:\n\t%s 60 data\n\n", argv[0] );

   file = fopen( argv[2], "r");

   ethos.flip = ON;
   ethos.count = 1;
   while( ( ethos.car = fgetc( file ) ) != EOF )
   {
      if( ethos.flip == ON ) {
         if( ethos.count % ( atoi( argv[1] ) ) == 0 ) {
            if( ethos.car == ' ' || ethos.car != '\n' )
               fprintf( output, "\n" );
            else
               ethos.flip = OFF;
         }
         if( ethos.car != '\n' )
            fprintf( output, "%c", ethos.car );
         else
            fprintf( output, " " );
      } else {
         if( ethos.car == ' ' ) {
            ethos.flip = ON;
            fprintf( output, "\n" );
            fprintf( output, "%c", ethos.car );
         } else {
            fprintf( output, "%c", ethos.car );
         }
      }
      ethos.count++;
   }
   fclose( output );
   fclose( file );
}


