/*
Esercizio 1
Scrivere un programma che chieda all'utente il nome di un file di testo e conti il numero di righe presenti nel
file.
Suggerimento: leggere il file un carattere alla volta e contare il numero di ritorni a capo.
*/

#include <stdio.h>
#include <string.h>

void ContaRighe(char *namefile) {
    FILE *fp;
    int count = 0;
    char riga;
    fp = fopen(namefile, "r");
    if (fp == NULL) {
        printf("Errore apertura file\n");
        return;
    }
    while ((riga = fgetc(fp)) != EOF) {
        if (riga == '\n') {
            count++;
        }
    }
    fclose(fp);
    printf("Numero di righe: %d\n", count +1); // +1 to count the last line if it doesn't end with a newline
}

int main(void) {
    char namefile[100];
    printf("Inserisci il nome del file di cui contare le righe: \n");
    scanf("%s", namefile);  
    strcat(namefile, ".txt"); // combina la stringa namefile con .txt
    ContaRighe(namefile);
    return 0;
}