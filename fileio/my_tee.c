#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE     /* Allow "cc - D" to override definition */
#define BUF_SIZE 1024
#endif


int
main(int argc, char * argv[])
{
    int fd, openFlags, numRead;
    char buf[BUF_SIZE + 1];

    if(argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file {-a}\n", argv[0]);

    openFlags = O_RDWR | O_CREAT;
    if(argc == 3 && strcmp(argv[2], "-a") == 0)
        openFlags |= O_APPEND;
    
    fd = open(argv[1], openFlags,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
            S_IROTH | S_IWOTH); 
    if(fd == -1)
        errExit("open file %s error!", argv[1]);

    while((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
        if(write(fd, buf, numRead) != numRead)
            fatal("couldn't write whole buffer");
        buf[numRead] = '\0';
        printf("%s\n", buf);
    }

    if(close(fd) == -1)
        errExit("close output");

    exit(EXIT_SUCCESS);
}