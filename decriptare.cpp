#include<iostream>
#include<stdio.h>

using namespace std;

FILE *f = fopen ("criptotext.txt", "r");
FILE *g = fopen ("decryption.txt", "w");

char litere[30], text[100000], litereThe[26], litereTo[26], key[26];
int frecventaLitere[30], frecvThe[26], frecvTo[26], 
    nrLitereCodificate = 0, nrLitereTo = 0, 
    nrLitere = 0, nrLitereThe = 0;

int main() {
    char c;
    while (! feof(f)) {
        fscanf (f, "%c", &c);
        text[nrLitereCodificate++] = c;
    }
    for (int i = 0; i < 30; i++) {
        frecventaLitere[i] = 0;
    }

    for (int i = 0; i < nrLitereCodificate; i++) {
        frecventaLitere[text[i] - 65]++;
    }

    for (int x = 'A'; x <= 'Z'; x++) {
        litere[nrLitere++] = x;
    }

    for (int i = 0; i < 25; i++) {
        for (int j = i+1; j < 26; j++) {
            if (frecventaLitere[i] < frecventaLitere[j]) {
                int aux;
                char aux_a;
                aux = frecventaLitere[i];
                aux_a = litere[i];
                frecventaLitere[i] = frecventaLitere[j];
                litere[i] = litere[j];
                frecventaLitere[j] = aux;
                litere[j] = aux_a;
            }
        }
    }
    
    for (int  i = 0; i < 26; i++) {
        cout << "litera "<< litere[i] << " apare cu frecventa "
            << frecventaLitere[i] << "\n";
    }
    for (int i = 0; i < nrLitereCodificate; i++) {
        if (text[i] == litere[0]) {
            fprintf(g, "E");
            key[litere[0] - 65] = litere[0];
            text[i] = 'E';
        } else if (text[i] == litere[1]) {
            fprintf(g, "T");
            key[litere[1] - 65] = litere[1];
            text[i] = 'T';
        } else if (text[i] == litere[2]) {
            fprintf(g, "A");
            key[litere[2] - 65] = litere[2];
            text[i] = 'A';
        } else {
            fprintf(g, "*");
        }
    }
    for (int i = 0; i < 25; i++) {
        if(text[i] == 'T' && text[i+2] == 'E') {
            frecvThe[text[i+1] - 65]++;
        }
    }
    for (int x = 'A'; x <= 'Z'; x++) {
        litereThe[nrLitereThe++] = x;
    }

    for (int i = 0; i < 25; i++) {
        for (int j = i+1; j < 26; j++) {
            if (frecvThe[i] < frecvThe[j]) {
                int aux1;
                char aux_The;
                aux1 = frecvThe[i];
                aux_The = litereThe[i];
                frecvThe[i] = frecvThe[j];
                litereThe[i] = litereThe[j];
                frecvThe[j] = aux1;
                litereThe[j] = aux_The;
            }
        }
    }

    key['H'-65] = litereThe[0];

    for (int i = 0; i < 25; i++) {
        if (text[i] == 'T' && text[i] != key[frecvThe[0] - 65]) {
            frecvTo[text[i+1] - 65]++;
        }
    }
    for (int x = 'A'; x <= 'Z'; x++) {
        litereTo[nrLitereTo++] = x;
    }

    for (int i = 0; i < 25; i++) {
        for ( int j = i+1; j < 26; j++) {
            if (frecvTo[i] < frecvTo[j]) {
                int aux2;
                char aux_To;
                aux2 = frecvTo[i];
                aux_To = litereTo[i];
                frecvTo[i] = frecvTo[j];
                litereTo[i] = litereTo[j];
                frecvTo[j] = aux2;
                litereTo[j] = aux_To;
            }
        }
    }

    key['O' - 65] = litereTo[0];

    cout << "\n";
    for (int i = 0; i < 26; i++) {
        cout << "pe pozitia "<< i << " cheia este " << key[i] << "\n";
    }
}


