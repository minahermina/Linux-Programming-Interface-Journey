/*
# As mentioned in  5.1 O_APPEND guarantees the write operaion to happen `atomically`

## Steps

```bash
$ make 3
$ /exercise3 test_files/1.txt 1000000 & ./exercise3 test_files/1.txt 1000000      # Atomic write operaion
$ /exercise3 test_files/2.txt 1000000 x & ./exercise3 test_files/2.txt 1000000 x  # Atomic write operaion

 
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define CHUNK_SIZE  4096

int main(int argc, char *argv[])
{
    size_t bytes_to_write;

    if (argc < 3){
        printf("Too few arguments");
        return EXIT_FAILURE;
    }

    if (argc == 4 && strcmp(argv[3], "x")){
        printf("Expected \"x\" as an argument but got \"%s\"", argv[3]);
        return EXIT_FAILURE;
    }


    if ((bytes_to_write = atoi(argv[2])) == 0){
        printf("Expected a number as an argument but got \"%s\"", argv[2]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    int fd;
    int flags = O_WRONLY | O_CREAT ;
    mode_t permissions =  S_IRWXU;

    if (argc == 4 ) { /* x is supplied*/
        fd = open(filename, flags, permissions);
        if (fd == -1) 
            perror("Error");

        int offset = lseek(fd, 0, SEEK_END);
        if (offset == -1)
            perror("Error");

    }
    else {
        fd = open(filename, flags | O_APPEND, permissions);
        if (fd == -1) 
            perror("Error");
    }
    
    char buffer[CHUNK_SIZE] = {'B'};

    /* Writing */
    ssize_t written_bytes = 0;
    size_t total_written_bytes = 0;

    while (total_written_bytes < bytes_to_write){
        size_t remaining_bytes = bytes_to_write - total_written_bytes;
        size_t bytes_to_write = (remaining_bytes > CHUNK_SIZE) ? CHUNK_SIZE: remaining_bytes;

        written_bytes = write(fd, buffer, bytes_to_write);
        if (written_bytes == -1){
            perror("Error Writing to file");
            close(fd);
            return EXIT_FAILURE;
        }

        total_written_bytes += written_bytes;
    }
    close(fd);
    return EXIT_SUCCESS;
}
