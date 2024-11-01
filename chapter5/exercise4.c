/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int mydup (int oldfd){
    int newfd = fcntl(oldfd, F_DUPFD);
    if (newfd == -1){
        printf("ERROR duplicating %d\n", oldfd);
        return EXIT_FAILURE;
    }

    return newfd;
}

int main(int argc, char *argv[])
{
    mydup(0);
    return 0;
}
