#define _FILE_OFFSET_BITS 64
#include<stdio.h>
#include<unistd.h>
int
main(int argc, char *argv[])
{
#define  MAX_LEN  10
 
   FILE *stream;
   char buffer[MAX_LEN + 1];
   int  result;
   int  i;
   char ch;
 
   stream = fopen("test.txt", "r");
   for (i = 0; (i  < (sizeof(buffer)-1) &&
       ((ch = fgetc(stream)) != EOF) && (ch != '\n')); i++)
          buffer[i] = ch;
 
   result = fseek(stream, 0L, SEEK_SET);  /* moves the pointer to the */
                                          /* beginning of the file    */
   if (result == 0)
      printf("Pointer successfully moved to the beginning of the file.\n");
   else
      printf("Failed moving pointer to the beginning of the file.\n");
}

