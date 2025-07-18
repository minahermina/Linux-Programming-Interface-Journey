/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int mydup (int oldfd){
    int newfd = fcntl(oldfd, F_DUPFD);
    if (newfd == -1){
        printf("ERROR duplicating %d\n", oldfd);
        return EXIT_FAILURE;
    }

    return newfd;
}

int mydup2 (int oldfd, int newfd){
    if (oldfd == newfd){
        int test = fcntl(oldfd, F_GETFL);
        if (test == -1 ){
            errno = EBADF;
            return -1;
        }
        return newfd;
    }


    int res = fcntl(oldfd, F_DUPFD, newfd);

    if (res == -1){
        printf("ERROR duplicating %d\n", oldfd);
        return EXIT_FAILURE;
    }

    return res;
}
int main(int argc, char *argv[])
{
    const char *file = "./test_files/1.txt";
    int fd = open(file, O_CREAT);
    /* case 1 */
    // mydup2(fd, fd );
    /* case 2 */
    // mydup2(5, 5 );
    return 0;
}
