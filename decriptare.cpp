#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_LETTERS 26
#define TEXT_LEN 10000

using namespace std;

FILE *fin  = fopen ("criptotext.txt", "r");
FILE *fout = fopen ("decryption.txt", "w");

char litereThe[NO_OF_LETTERS];
char litereTo[NO_OF_LETTERS];
char key[NO_OF_LETTERS];


int frecvTo[NO_OF_LETTERS]; 
int frecvThe[NO_OF_LETTERS];

int nrLitere           = 0;
int nrLitereTo         = 0;
int nrLitereThe        = 0;

struct Letter {
    char letter;
    int frequency;
};

int comp(const void *a, const void *b)
{
    return (((struct Letter*)b)->frequency - ((struct Letter*)a)->frequency);
}


void replaceMultad(char *decryptedText, int noOfLetters, char *text, char *string, char replace, char *key) {
    int theTriadCount[NO_OF_LETTERS];
    for (int count = 0; count < NO_OF_LETTERS; count++)
        theTriadCount[count] = 0;

    int maxLetterId = 0;
    for (int count = 0; count < noOfLetters - 2; count++) {
        int ok = 1;
        for (int it = 0; it < strlen(string); it++)
            if (decryptedText[count + it] != string[it])
                ok = 0;
        int starPos = strchr(string, '*') - string;
        if (ok) {
            if (++theTriadCount[text[count + starPos] - 'A'] > theTriadCount[maxLetterId]) {
                maxLetterId = text[count + starPos] - 'A';
            }
        }
    }

    for (int count = 0; count < noOfLetters; count++) {
        if (text[count] == maxLetterId + 'A') {
            decryptedText[count] = replace;
        }
    }
    key[replace - 'A'] = maxLetterId + 'A';
}

int main() {

    struct Letter letters[NO_OF_LETTERS];

    for (int i = 0; i < NO_OF_LETTERS; i++) {
        letters[i].letter = i + 'A';
        letters[i].frequency = 0;
    }

    char newCharacter;
    char text[TEXT_LEN];
    int noOfLetters = 0;
    while (fscanf(fin, "%c", &newCharacter) == 1) {
        text[noOfLetters++] = newCharacter;
        letters[newCharacter - 'A'].frequency++;
    }

    qsort(letters, NO_OF_LETTERS, sizeof(struct Letter), comp);

    char decryptedText[TEXT_LEN];
    for (int count = 0; count < noOfLetters; count++) {
        int letterIndex = 0;
        if (text[count] == letters[0].letter)
            decryptedText[count] = 'E';
        else if (text[count] == letters[1].letter)
            decryptedText[count] = 'T';
        else if (text[count] == letters[2].letter)
            decryptedText[count] = 'A';
        else
            decryptedText[count] = '*';
    }

    char key[NO_OF_LETTERS];
    for (int count = 0; count < NO_OF_LETTERS; count++) {
        key[count] = '*';
    }
    key['E' - 'A'] = letters[0].letter;
    key['T' - 'A'] = letters[1].letter;
    key['A' - 'A'] = letters[2].letter;

    replaceMultad(decryptedText, noOfLetters, text, "T*E",  'H', key);
    replaceMultad(decryptedText, noOfLetters, text, "T*",   'O', key);
    replaceMultad(decryptedText, noOfLetters, text, "E*",   'R', key);
    replaceMultad(decryptedText, noOfLetters, text, "A*",   'N', key);
    replaceMultad(decryptedText, noOfLetters, text, "*N",   'I', key);
    replaceMultad(decryptedText, noOfLetters, text, "A*",   'S', key);
    replaceMultad(decryptedText, noOfLetters, text, "*OR",  'F', key);
    replaceMultad(decryptedText, noOfLetters, text, "HI*",  'M', key);
    replaceMultad(decryptedText, noOfLetters, text, "O*",   'U', key);
    replaceMultad(decryptedText, noOfLetters, text, "*OU",  'Y', key);
    replaceMultad(decryptedText, noOfLetters, text, "HA*E", 'V', key);
    replaceMultad(decryptedText, noOfLetters, text, "*ITH", 'W', key);
    replaceMultad(decryptedText, noOfLetters, text, "IN*",  'G', key);
    replaceMultad(decryptedText, noOfLetters, text, "*AN",  'C', key);
    replaceMultad(decryptedText, noOfLetters, text, "*UT",  'B', key);
    replaceMultad(decryptedText, noOfLetters, text, "*UT",  'P', key);
    replaceMultad(decryptedText, noOfLetters, text, "E*",   'D', key);
    replaceMultad(decryptedText, noOfLetters, text, "*E",   'K', key);
    replaceMultad(decryptedText, noOfLetters, text, "U*",   'P', key);



    struct Letter doubleLetters[NO_OF_LETTERS];

    for (int i = 0; i < NO_OF_LETTERS; i++) {
        doubleLetters[i].letter = i + 'A';
        doubleLetters[i].frequency = 0;
    }

    for (int count = 0; count < noOfLetters - 1; count++) {
        if (text[count] == text[count + 1] && decryptedText[count] == '*') {
            doubleLetters[text[count] - 'A'].frequency++;
        }
    }

    qsort(doubleLetters, NO_OF_LETTERS, sizeof(struct Letter), comp);

    for (int count = 0; count < noOfLetters; count++) {
        int letterIndex = 0;
        if (text[count] == doubleLetters[0].letter)
            decryptedText[count] = 'L';
    }


    printf("%s\n", key);
    for (int count = 0; count < NO_OF_LETTERS; count++) {
        printf("%c", count + 'A');
    }
    printf("\n");

    for (int count = 0; count < noOfLetters; count++) {
        printf("%c", decryptedText[count]);
    }

}


