/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    const char *file = "./test_files/1.txt";
    int fd = open(file, O_RDWR | O_CREAT | O_APPEND);
    int dupfd = dup(fd);

    /* check for file offset */
    /* Moving file offset 10 beyond its current position */
    off_t offset1 = lseek(fd, 10 , SEEK_SET);
    off_t offset2 = lseek(dupfd, 0 , SEEK_CUR);
    assert( offset1 == offset2 );

    /* check for open file status flags */
    int flags1 = fcntl(fd, F_GETFL);
    int flags2 = fcntl(dupfd, F_GETFL);
    assert( flags1 == flags2 );



    return 0;
}
