#include <stdio.h>
#include <unistd.h>

#include "file_funcs.h"
 
#define    COPY_BUFF_SIZE          10

#define    CP_ARG_COUNT_ERROR     -3

#define    COPY_DONE               0
#define    COPY_ERROR             -10


int int_copyFile(int argc, char *argv[]) {

    char copyBuff[COPY_BUFF_SIZE];

    int readCharsCount = 1;
    int writeCharCount;

    if (argc != 3) {

        printf("%s", "Not Enough Arguments. It should be three.\n");
        return CP_ARG_COUNT_ERROR;
    }

    while (readCharsCount != 0) {

        readCharsCount = int_readFile(argv[1], copyBuff, sizeof(copyBuff));
        writeCharCount = int_writeFile(argv[2], copyBuff, readCharsCount);
    }

    return readCharsCount == writeCharCount ? COPY_DONE : COPY_ERROR;
}

int main(int argc, char *argv[]) {

    int_copyFile(argc, argv);
}