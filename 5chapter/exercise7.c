/*
 */
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/*
ssize_t readv(int fd, const struct iovec *iov, int iovcnt);
ssize_t writev(int fd, const struct iovec *iov, int iovcnt);
*/


#include <sys/uio.h>
struct myiovec {
   void   *iov_base;
   size_t  iov_len;
};

ssize_t myreadv(int fd, const struct myiovec *iov, int iovcnt);
ssize_t mywritev(int fd, const struct myiovec *iov, int iovcnt);

ssize_t myreadv(int fd, const struct myiovec *iov, int iovcnt)
{
    // TODO: do error handling
    ssize_t bytes_read = 0; 
    for (size_t i = 0; i < iovcnt; i++){
        bytes_read += read(fd, iov[i].iov_base, iov[i].iov_len);
    }

    return bytes_read;
}
ssize_t mywritev(int fd, const struct myiovec *iov, int iovcnt){

    // TODO: do error handling
    ssize_t bytes_written = 0; 
    for (size_t i = 0; i < iovcnt; i++){
        bytes_written += write(fd, iov[i].iov_base, iov[i].iov_len);
    }

    return bytes_written;

}

int main(int argc, char *argv[]) {
    #define STR1_SIZE  6
    #define STR2_SIZE  4
    #define IOV_SIZE  2

    char str1[STR1_SIZE] = "test12";
    char str2[STR2_SIZE] = "ZOBY";

    const char *file = "./test_files/1.txt";
    int fd = open(file, O_RDWR);

    struct iovec iov[IOV_SIZE];
    iov[0].iov_base = str1;
    iov[0].iov_len = STR1_SIZE;

    iov[1].iov_base = str2;
    iov[1].iov_len = STR2_SIZE;

    int numread = 0;
    numread = writev(fd, iov, IOV_SIZE);
    printf("numread: %d\n", numread);
    // printf("str1: %s\n", str1);
    // printf("str2: %s\n", str2);


    return 0;
}
