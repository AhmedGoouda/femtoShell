#include <stdio.h>

/*****************************************************************************************************************/
/*  Tokenize a string based on a char delimiter                                                                  */
/*****************************************************************************************************************/
/*  Function Passed  :  char array and its size, char delimiter, array of strings to save the tokens             */
/*  Function return  :  number of tokens                                                                         */
/*****************************************************************************************************************/
int int_tokenizer(char *string, unsigned int stringSize, char delimiter, char **tokensArray) {

    unsigned int tokensCount = 0;
    unsigned char repeatedDelimiterCount = 0;
    unsigned int stringLen = stringSize;
    
    /*Remove leading spaces of the input string*/
    while (*string == ' ') {
        
        string++;
        stringLen--;
    }
    
    /*Remove trailing spaces of the input string*/
    while (string[stringLen - 2] == ' ') {

        stringLen--;
    }
    string[stringLen - 1] = '\0';
    
    /*Save the start location of the input string*/
    char *start = string;

    /*Remove the extra white spaces in between, if the delimiter isn't a white space*/
    if (delimiter != ' ') {

        char *remove = string;

        do {
            while (*remove == ' ') {
                ++remove;
            }

        }while (*string++ = *remove++);

        string = start; 
    }
    
    while (*start) {

        if (*start == delimiter) {

            while (*(start + 1) == delimiter) {

                repeatedDelimiterCount++;
                start++;
            }

            /*Remove repeated delimiters*/
            *(start - repeatedDelimiterCount) = '\0';
            repeatedDelimiterCount = 0;
            tokensArray[tokensCount] = string;
            tokensCount++;
            string = start + 1;
        }
        start++;
    }

    /*Save the last token*/
    tokensArray[tokensCount] = string;

    return tokensCount + 1;
}