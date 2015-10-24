#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include<stdlib.h>

using namespace std;

FILE *f = fopen ("plaintext.txt", "r");
FILE *g = fopen ("criptotext.txt", "w");
char text[100000], litere[30], litereCodificate[30];
int frecventaLitere[30];
int nrText = 0, nrLitere = 0;

int main() {
    char c;
    while (! feof(f)) {
        fscanf(f, "%c", &c);
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
            text[nrText++] = toupper(c);
        }
    }
    
    for (char x = 'A'; x <= 'Z'; x++) {
        litere[nrLitere++] = x;
    }

    for (int i = 0; i < nrLitere; i++) {
        frecventaLitere[i] = 0;
    }

    for (int i = 0; i< nrLitere; i++) {
        int key = rand() % nrLitere;
        cout<<"key="<<key<<"\n";
        while (frecventaLitere[key] == 1) {
            key = rand() % nrLitere;
        }
        litereCodificate[i] = litere[key];
        frecventaLitere[key] = 1;
    }
    for (int i = 0; i < nrLitere; i++) {
        cout<<litereCodificate[i]<<" inlocuieste litera "<<litere[i]<<"\n";
    }
    for (int i = 0; i < nrText; i++) {
        text[i] = litereCodificate[text[i] - 65];
    }
    for (int i = 0; i < nrText; i++) {
    fprintf(g, "%c", text[i]);
    }
    return 0;
}
