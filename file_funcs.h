#include <stdio.h>

int int_openFile(char *filePath, int fileOption);
int int_closeFile(int fd);
int int_readFile(char *filePath, char *readBuff, size_t readBuffSize);
int int_writeFile(char *filePath, char *writeBuff, size_t writeBuffCount);