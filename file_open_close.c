#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "file_funcs.h"

#define    READ_ONLY_MODE          0
#define    READ_WRITE_MODE         1   

#define    WRONG_OPTION           -5

#define    SRC_FILE_NOT_FOUND     -2

#define    FILE_CLOSED             0
#define    CLOSE_FILE_ERROR       -7


int int_openFile(char *filePath, int fileOption) {

    int fd;

    if (fileOption == READ_ONLY_MODE) {

        fd = open(filePath, O_RDONLY);
    }
    else if (fileOption == READ_WRITE_MODE) {

        fd = open(filePath, O_WRONLY|O_CREAT, 0644);
    }
    else {
        return WRONG_OPTION;
    }

    if (fd == -1) {

        return SRC_FILE_NOT_FOUND;
    }
    else {

        return fd;
    }
}


int int_closeFile(int fd) {

    if (close(fd) == -1) {

        return CLOSE_FILE_ERROR;
    }
    else {
        return FILE_CLOSED;
    }
}