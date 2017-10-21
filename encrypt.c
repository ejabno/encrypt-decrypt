#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPWDLEN 51 //Hard coded shit!
#define ASCIILENGTH 95 //(From ASCII characters starting from 32-126, i.e. whitespace all the way to ~)
unsigned int GG_maxPwdLen = MAXPWDLEN; 
typedef struct charKey {
    char Key;
    int Freqs[MAXPWDLEN]; 
} charKey;

int main() {
    /*FILE *openFile;*/
    char passwdIn[GG_maxPwdLen];
    char passwdInFlush[GG_maxPwdLen];

    printf("Please enter something: \n");
    //Use a do while loop to ensure correct password input
    //Repeat for an invalid input
    do {
        //Store stuff in a temporary buffer
        fgets(passwdInFlush, GG_maxPwdLen, stdin);
        //Take stuff from that temp buffer and put it in stdin
        sscanf(passwdInFlush, "%[^\n]s", passwdIn);
        if (strlen(passwdIn) == 0) printf("Invalid input, TRY AGAIN! \n");

    } while (strlen(passwdIn) == 0);
    printf("passwdIn read: %s\n", passwdIn);

    //Take the passwdLength
    int passLen = strlen(passwdIn);
    
    //Take the ASCII values of each character, and add them all together as a sum
    int pwdSum = 0;
    for (int i = 0; i < passLen; i++) {
        pwdSum += (int) passwdIn[i];
    }
    
    //Encryption shit here
    //Take each character in the password as a key containing the orders they appear
    //Syntax is <char(in hex ASCII notation)>+(hexindex1).(hexindex2).(hexindexN) with colon ":" as delimiter
    //For example, "abcdabbe"
    //61+0.4:62+1.5.6:63+2:64+3:65+7

    //Here we use tables using arrays to associate each character with its frequency
    charKey charTableFrequency[ASCIILENGTH];
    //Initialize this table
    for(int i = 0; i < ASCIILENGTH; i++) {
        charTableFrequency[i].Key = i + 32;
        for (int j = 0; j < MAXPWDLEN; j++) {
            charTableFrequency[i].Freqs[j] = -1;  //-1 means empty in the char position table
        }
    }

    for (int i = 0; i < passLen; i++) {
        int charVal = passwdIn[i]; //Get current character in the password array
        int jIter = 0; 
        while (charTableFrequency[charVal-32].Freqs[jIter] > -1) {
            jIter++;
        }
        charTableFrequency[charVal-32].Freqs[jIter] = i;
    }

    //Print out encryption Key
    for(int i = 0; i < ASCIILENGTH; i++) {
        if(charTableFrequency[i].Freqs[0] > -1) {
            printf("%x+", charTableFrequency[i].Key);
            int jIter = 0;
            while (charTableFrequency[i].Freqs[jIter] > -1) {
                printf("%x", charTableFrequency[i].Freqs[jIter]);
                jIter++;
                if (charTableFrequency[i].Freqs[jIter] > -1) printf("."); else printf(":");
            }
        }
    }
    printf("\n");
    return 0;
}
