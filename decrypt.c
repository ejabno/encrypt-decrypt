#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINPUT 100

int main() {
    char inputInFlush[MAXINPUT]; 
    char inputToDecrypt[MAXINPUT];
    fgets(inputInFlush, MAXINPUT, stdin);
    sscanf(inputInFlush, "%[^\n]", inputToDecrypt);
    printf("inputToDecrypt: %s\n", inputToDecrypt);
}                                                                                                                        
