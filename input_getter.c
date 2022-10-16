#include <stdio.h>


/*****************************************************************************************************************/
/*  Get the user input string from stdin and save it in the passed array                                         */
/*****************************************************************************************************************/
/*  Function Passed  :  char array and its size                                                                  */
/*  Function return  :  length of the input string                                                               */
/*****************************************************************************************************************/
int int_getUserInput(char *inputString, unsigned int inputStringSize) {

    unsigned int inputStringLen = 0;

    for (inputStringLen; inputStringLen < inputStringSize; inputStringLen++) {

        inputString[inputStringLen] = getchar();

        if (inputString[inputStringLen] == '\n') {

            break;
        }
    }

    return inputStringLen;
}