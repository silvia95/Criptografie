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

    char key[] = "ETAOINSRHLDCUMFPGWYBVKXJQZ";




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




    int theTriadCount[NO_OF_LETTERS];
    for (int count = 0; count < NO_OF_LETTERS; count++)
        theTriadCount[count] = 0;

    int maxLetterId = 0;
    for (int count = 0; count < noOfLetters - 2; count++) {
        if (decryptedText[count] == 'T' && decryptedText[count + 2] == 'E') {
            if (++theTriadCount[text[count + 1] - 'A'] > theTriadCount[maxLetterId]) {
                maxLetterId = text[count + 1] - 'A';
            }
        }
    }

    for (int count = 0; count < noOfLetters; count++) {
        if (text[count] == maxLetterId + 'A') {
            decryptedText[count] = 'H';
        }
    }




    int theDiadCount[NO_OF_LETTERS];
    for (int count = 0; count < NO_OF_LETTERS; count++)
        theDiadCount[count] = 0;

    maxLetterId = 0;
    for (int count = 0; count < noOfLetters - 1; count++) {
        if (decryptedText[count] == 'T' && decryptedText[count + 1] == '*') {
            if (++theDiadCount[text[count + 1] - 'A'] > theDiadCount[maxLetterId]) {
                maxLetterId = text[count + 1] - 'A';
            }
        }
    }

    for (int count = 0; count < noOfLetters; count++) {
        if (text[count] == maxLetterId + 'A') {
            decryptedText[count] = 'O';
        }
    }




    for (int count = 0; count < NO_OF_LETTERS; count++)
        theDiadCount[count] = 0;

    maxLetterId = 0;
    for (int count = 0; count < noOfLetters - 1; count++) {
        if (decryptedText[count] == 'E' && decryptedText[count + 1] == '*') {
            if (++theDiadCount[text[count + 1] - 'A'] > theDiadCount[maxLetterId]) {
                maxLetterId = text[count + 1] - 'A';
            }
        }
    }

    for (int count = 0; count < noOfLetters; count++) {
        if (text[count] == maxLetterId + 'A') {
            decryptedText[count] = 'R';
        }
    }




    for (int count = 0; count < NO_OF_LETTERS; count++)
        theDiadCount[count] = 0;

    maxLetterId = 0;
    for (int count = 0; count < noOfLetters - 1; count++) {
        if (decryptedText[count] == 'A' && decryptedText[count + 1] == '*') {
            if (++theDiadCount[text[count + 1] - 'A'] > theDiadCount[maxLetterId]) {
                maxLetterId = text[count + 1] - 'A';
            }
        }
    }

    for (int count = 0; count < noOfLetters; count++) {
        if (text[count] == maxLetterId + 'A') {
            decryptedText[count] = 'N';
        }
    }




    for (int count = 0; count < NO_OF_LETTERS; count++)
        theTriadCount[count] = 0;

    for (int count = 0; count < noOfLetters - 2; count++) {
        if (decryptedText[count] == 'A' && decryptedText[count + 1] == 'N' && decryptedText[count + 2] == '*') {
            if (++theTriadCount[text[count + 2] - 'A'] > theTriadCount[maxLetterId]) {
                maxLetterId = text[count + 1] - 'A';
            }
        }
    }

    for (int count = 0; count < noOfLetters; count++) {
        if (text[count] == maxLetterId + 'A') {
            decryptedText[count] = 'D';
        }
    }




//    struct Letter doubleLetters[NO_OF_LETTERS];
//
//    for (int i = 0; i < NO_OF_LETTERS; i++) {
//        doubleLetters[i].letter = i + 'A';
//        doubleLetters[i].frequency = 0;
//    }
//
//    for (int count = 0; count < noOfLetters - 1; count++) {
//        if (text[count] == text[count + 1] && decryptedText[count] == '*') {
//            doubleLetters[text[count] - 'A'].frequency++;
//        }
//    }
//
//    qsort(doubleLetters, NO_OF_LETTERS, sizeof(struct Letter), comp);
//
//    for (int i = 0; i < NO_OF_LETTERS; i++) {
//        printf("%c %d\n", doubleLetters[i].letter, doubleLetters[i].frequency);
//    }
//
//    for (int count = 0; count < noOfLetters; count++) {
//        int letterIndex = 0;
//        if (text[count] == doubleLetters[0].letter)
//            decryptedText[count] = 'S';
//        //else if (text[count] == doubleLetters[1].letter)
//        //    decryptedText[count] = 'F';
//        //else if (text[count] == doubleLetters[2].letter)
//        //    decryptedText[count] = 'L';
//        //else if (text[count] == doubleLetters[3].letter)
//        //    decryptedText[count] = 'M';
//    }
//
//

    for (int count = 0; count < noOfLetters; count++) {
        printf("%c", decryptedText[count]);
    }





//    for (int i = 0; i < 25; i++) {
//        if(text[i] == 'T' && text[i+2] == 'E') {
//            frecvThe[text[i+1] - 65]++;
//        }
//    }
//    for (int x = 'A'; x <= 'Z'; x++) {
//        litereThe[nrLitereThe++] = x;
//    }
//
//    for (int i = 0; i < 25; i++) {
//        for (int j = i+1; j < 26; j++) {
//            if (frecvThe[i] < frecvThe[j]) {
//                int aux1;
//                char aux_The;
//                aux1 = frecvThe[i];
//                aux_The = litereThe[i];
//                frecvThe[i] = frecvThe[j];
//                litereThe[i] = litereThe[j];
//                frecvThe[j] = aux1;
//                litereThe[j] = aux_The;
//            }
//        }
//    }
//
//    key['H'-65] = litereThe[0];
//
//    for (int i = 0; i < 25; i++) {
//        if (text[i] == 'T' && text[i] != key[frecvThe[0] - 65]) {
//            frecvTo[text[i+1] - 65]++;
//        }
//    }
//    for (int x = 'A'; x <= 'Z'; x++) {
//        litereTo[nrLitereTo++] = x;
//    }
//
//    for (int i = 0; i < 25; i++) {
//        for ( int j = i+1; j < 26; j++) {
//            if (frecvTo[i] < frecvTo[j]) {
//                int aux2;
//                char aux_To;
//                aux2 = frecvTo[i];
//                aux_To = litereTo[i];
//                frecvTo[i] = frecvTo[j];
//                litereTo[i] = litereTo[j];
//                frecvTo[j] = aux2;
//                litereTo[j] = aux_To;
//            }
//        }
//    }
//
//    key['O' - 65] = litereTo[0];
//
//    cout << "\n";
//    for (int i = 0; i < 26; i++) {
//        cout << "pe pozitia "<< i << " cheia este " << key[i] << "\n";
//    }
}


