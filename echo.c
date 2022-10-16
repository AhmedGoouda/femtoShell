#include <stdio.h>


/*****************************************************************************************************************/
/*  Echo user input string from stdin                                                                            */
/*****************************************************************************************************************/
/*  Function Passed  :  pointer to char                                                                          */
/*  Function return  :  error state (int)                                                                        */
/*****************************************************************************************************************/
int int_echoString(char *inputString) {

    if (inputString != NULL) {

        printf("%s ", inputString);
        return 0;
    }
    else {

        printf("\n");
        return -1;
    }
}

int main(int argc, char *argv[]) {

    if (argc == 1) {

        int_echoString(argv[1]);
    }
    else {

        for (int i = 1; i < argc; i++) {

            int_echoString(argv[i]);
        }
        printf("\n");
    }
}