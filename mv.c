#include <stdio.h>
#include <unistd.h>

#include "file_funcs.h"

#define     MV_ARG_COUNT_ERROR  -2

#define     MOVE_DONE            0
#define     MOVE_ERROR          -11


int int_moveFile(int argc, char *argv[]) {

    char copyBuff[100];

    int readCharsCount = 1;
    int writeCharCount;

    if (argc != 3) {

        printf("%s", "Not Enough Arguments. It should be three.\n");
        return MV_ARG_COUNT_ERROR;
    }

    while (readCharsCount != 0) {

        readCharsCount = int_readFile(argv[1], copyBuff, sizeof(copyBuff));
        writeCharCount = int_writeFile(argv[2], copyBuff, readCharsCount);
    }

    remove(argv[1]);

    return readCharsCount == writeCharCount ? MOVE_DONE : MOVE_ERROR;
}

int main(int argc, char *argv[]) {

    int_moveFile(argc, argv);
}