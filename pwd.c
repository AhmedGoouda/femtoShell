#include <stdio.h>
#include <unistd.h>

#define     WD_BUFF_SIZE    500

#define     WD_ARG_COUNT_ERROR      -1
#define     WD_LEN_IS_OK             0
#define     WD_LEN_IS_TOO_LONG       1


int int_pwd(int argc) {

    char wdBuff[WD_BUFF_SIZE];

    if (argc != 1) {

        printf("%s", "Argument Error. It should be only one.\n");
        return WD_ARG_COUNT_ERROR;
    }

    if (getcwd(wdBuff, sizeof(wdBuff)) != NULL) {

        printf("CWD is: %s\n", getcwd(wdBuff, sizeof(wdBuff)));
        return WD_LEN_IS_OK;
    }
    else {

        printf("Too long directory.\nPlease increase the size of the cwd buffer, current size is %d.\n", WD_BUFF_SIZE);
        return WD_LEN_IS_TOO_LONG;
    }
}

int main(int argc, char *argv[]) {

    int_pwd(argc);
}