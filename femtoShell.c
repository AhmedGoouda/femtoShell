#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

#include "femtoShell.h"


/*femtoShell Commands*/
char *femtoShellCommands[] = {"fexit", "fecho", "fpwd", "fcp", "fmv", "fset", "fexport"};
enum femtoShellCommands {fexit, fecho, fpwd, fcp, fmv, fset, fexport};


/*Extern Environment Variables*/
extern char** environ;

/*Save local variables*/
struct var {

    char name[50];
    char value[50];

}localVar[100];


/*****************************************************************************************************************/
/*  prompt                                                                                                       */
/*****************************************************************************************************************/
void vid_femtoShellPrompt(void) {

    printf("\n*******************************************************\n");
    printf("This is the femtoShell which imitates the Linux Shell\n");
    printf("The femtoShell commands start with the letter f.\n");
    printf("Currently supported commands are:\n");
    printf("1. fexit\n");
    printf("2. fecho\n");
    printf("3. fpwd\n");
    printf("4. fcp\n");
    printf("5. fmv\n");
    printf("*******************************************************\n\n");
}


/*****************************************************************************************************************/
/*  Execute a specific femtoShell command based on user input                                                    */
/*****************************************************************************************************************/
/*  Function Passed  :  void                                                                                     */
/*  Function return  :  error state (int)                                                                        */
/*****************************************************************************************************************/
int int_femtoShell(void) {


    char userInput[INPUT_STRING_SIZE];
    unsigned int userInputLen;

    char *argument[NUMBER_OF_ARGUMENTS];
    unsigned char argumentCount;

    static unsigned char localVarCount;
    unsigned char localVarExist;

    int forkRet;
    int setenvRet;

    while (1) {

        printf("It's the femtoShell >> ");

        userInputLen = int_getUserInput(userInput, INPUT_STRING_SIZE);

        /*reset if user Input nothing*/
        if (userInputLen == 0) {

            continue;
        }

        /*reset tokens values*/
        for(int i = 0; i < NUMBER_OF_ARGUMENTS; i++) {

            argument[i] = NULL;
        }

        /*check if input is a command or assign a variable*/
        if (strchr(userInput, '=') != NULL) {

            argumentCount = int_tokenizer(userInput, userInputLen + 1, '=', argument);

            /*Overwrite the old value if a variable if exist*/
            localVarExist = 0;

            for (int i = 0; i < localVarCount; i++) {

                if (!strcmp(argument[0], localVar[i].name)) {

                    strcpy(localVar[i].value, argument[1]);
                    localVarExist = 1;
                    break;
                }
            }

            if (!localVarExist) {

                strcpy(localVar[localVarCount].name, argument[0]);
                strcpy(localVar[localVarCount].value, argument[1]);

                localVarCount++;
                continue;
            }
            else {

                continue;
            }
        }
        else {

            argumentCount = int_tokenizer(userInput, userInputLen + 1, ' ', argument);
        }

        /*exit*/
        if (!strcmp(argument[0], femtoShellCommands[fexit])) {

            break;
        }
        /*Add local variable*/
        else if (!strcmp(argument[0], femtoShellCommands[fset])) {

            for (int i = 0; i < localVarCount; i++) {

                printf("localVar[%d]: %s = %s\n", i, localVar[i].name, localVar[i].value);
            }

            continue;
        }
        /*export local variable*/
        else if (!strcmp(argument[0], femtoShellCommands[fexport])) {

            setenvRet = -2;
                
            for (int i = 0; i < localVarCount; i++) {

                if (!strcmp(argument[1], localVar[i].name)) {

                    setenvRet = setenv(localVar[i].name, localVar[i].value, 1);
                    break;
                }
            }

            if (setenvRet == -2) {

                printf("Couldn't export [%s], variable doesn't exist.\n", argument[1]);
            }

            continue;
        }

        forkRet = fork();

        if (forkRet < 0) {

            return -1;
        }
        else if (forkRet > 0) {
            
            int childStatus;
            wait(&childStatus);

        }
        else if (forkRet == 0) {

            int execveStatus = execvp(argument[0], argument);
            if (execveStatus == -1) {
                printf("Command doesn't exist in femtoshell or main shell\n");
                return -1;
            }
        }
    }

    return 0;
}



int main() {

    vid_femtoShellPrompt();
    int_femtoShell();
}