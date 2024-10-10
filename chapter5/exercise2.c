/*
Open the man page for lseek:
If the O_APPEND file status flag is set on the open file description, then a write(2) always moves the file offset to the end of the file, regardless of the use of lseek().
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    const char *filename = "test_files/1.txt";
    char *buffer= "Test";
    int fd = open(filename, O_WRONLY | O_APPEND);

    if (fd == -1)
        printf("ERROR Opening the file\n");

    int curr_seek = lseek(fd, 0, SEEK_SET);
    printf("Current seek: %d\n", curr_seek);

    if (write(fd, buffer, strlen(buffer)) == -1)
        printf("ERROR Writing to the file\n");

    close(fd);
    return 0;
}
