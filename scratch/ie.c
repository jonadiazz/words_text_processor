#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int myCompare (const void * a, const void * b ) {
   const char *pa = *(const char**)a;
   const char *pb = *(const char**)b;

   return strcmp(pa,pb);
}

int main() {
   int i;
   const char **input;

   input[0] = strdup("wack");
   input[1] = strdup("ak");
   input[2] = strdup("orange");
   input[3] = strdup("apple");
   input[4] = strdup("mobile");
   input[5] = strdup("car");

   int stringLen = sizeof(input) / sizeof(char *);
   qsort(input, stringLen, sizeof(char *), myCompare);

   for (i=0; i<stringLen; ++i)
      printf("%d: %s\n", i, input[i]);
}

