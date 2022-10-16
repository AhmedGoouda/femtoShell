#ifndef     FEMTOSHELL_H
#define     FEMTOSHELL_H

#define INPUT_STRING_SIZE        500
#define NUMBER_OF_ARGUMENTS      15

/*****************************************************************************************************************/
/*  Get the user input string from stdin and save it in the passed array                                         */
/*****************************************************************************************************************/
/*  Function Passed  :  char array and its size                                                                  */
/*  Function return  :  length of the input string                                                               */
/*****************************************************************************************************************/
int int_getUserInput(char *inputString, unsigned int inputStringSize);


/*****************************************************************************************************************/
/*  Tokenize a string based on a char delimiter                                                                  */
/*****************************************************************************************************************/
/*  Function Passed  :  char array and its size, char delimiter, array of strings to save the tokens             */
/*  Function return  :  number of tokens                                                                         */
/*****************************************************************************************************************/
int int_tokenizer(char *string, unsigned int stringSize, char delimiter, char **tokensArray);


/*****************************************************************************************************************/
/*  Execute a specific femtoShell command based on user input                                                    */
/*****************************************************************************************************************/
/*  Function Passed  :  void                                                                                     */
/*  Function return  :  error state (int)                                                                        */
/*****************************************************************************************************************/
int int_femtoShell(void);


#endif