#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINPUT 100

int main() {
    char inputInFlush[MAXINPUT]; 
    char inputToDecrypt[MAXINPUT];
    char *decryptCursor;
    printf("Enter encryption code: \n");
    fgets(inputInFlush, MAXINPUT, stdin);
    sscanf(inputInFlush, "%[^\n]", inputToDecrypt);
    printf("inputToDecrypt: %s\n", inputToDecrypt);

    //Note to self: sizeof() != strlen()!!!!!!
    printf("strlen() returned: %lu\n", strlen(inputToDecrypt));

    int stringLength = (int) strlen(inputToDecrypt);
    printf("stringLength = %d\n", stringLength);
    decryptCursor = &inputToDecrypt[0];
    for (int i = 0; i < stringLength; i++) {
        printf("%c\n", *decryptCursor);
        decryptCursor++;
    }

    /*decryptCursor = &inputToDecrypt[0];*/
    /*printf("decryptCursor: %c\n", *decryptCursor);*/
    /*decryptCursor++;*/
    /*printf("decryptCursor: %c\n", *decryptCursor);*/

    /*while ()*/
}                                                                                                                        
