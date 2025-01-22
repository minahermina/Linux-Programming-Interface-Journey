#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int 
main(int argc, char *argv[])
{
    /* int i = 0;
    while(environ[i]){
        printf("%s\n", environ[i]);
        i++;
    } */

    int x = 1;
    void* ptr;
    while(x--){
        ptr = malloc(3*sizeof(char));
        printf("x: %d\n", x);
        free(ptr);
    }
    printf("%p\n", ptr);
    return 0;

}
