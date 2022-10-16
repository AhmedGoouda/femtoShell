#include <stdio.h>
#include <unistd.h>

#include "file_funcs.h"

#define    READ_ONLY_MODE          0
#define    READ_WRITE_MODE         1   

#define    SOURCE_FILE_CLOSED      0
#define    SOURCE_FILE_OPENED      1
#define    READ_FILE_ERROR        -6

#define    DEST_FILE_CLOSED        0
#define    DEST_FILE_OPENED        1
#define    WRITE_FILE_ERROR       -4


int int_readFile(char *filePath, char *readBuff, size_t readBuffSize) {

    static int src_fd;
    static unsigned char srcFileStatus = SOURCE_FILE_CLOSED;
    int readCharsCount;

    if (srcFileStatus == SOURCE_FILE_CLOSED) {

        src_fd = int_openFile(filePath, READ_ONLY_MODE);
        srcFileStatus = SOURCE_FILE_OPENED;
    }

    readCharsCount = read(src_fd, readBuff, readBuffSize);

    if (readCharsCount == 0) {

        srcFileStatus = int_closeFile(src_fd);
    }

    return readCharsCount == -1 ? READ_FILE_ERROR : readCharsCount;
}


int int_writeFile(char *filePath, char *writeBuff, size_t writeBuffCount) {

    static int dest_fd;
    static unsigned char destFileStatus = DEST_FILE_CLOSED;
    int writeCharsCount;

    if (destFileStatus == DEST_FILE_CLOSED) {

        dest_fd = int_openFile(filePath, READ_WRITE_MODE);
        destFileStatus = DEST_FILE_OPENED;
    }

    writeCharsCount = write(dest_fd, writeBuff, writeBuffCount);

    if (writeCharsCount == 0) {

        destFileStatus = close(dest_fd);
    }

    return writeCharsCount == -1 ? WRITE_FILE_ERROR : writeCharsCount;
}