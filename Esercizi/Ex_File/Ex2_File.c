/*
Esercizio 2
Scrivere un programma per contare le occorrenze delle 26 lettere dell'alfabeto in un file di testo.
Il risultato deve essere salvato in un nuovo file chiamato frequenza_lettere.txt.
Il contenuto di frequenza_lettere.txt dovrebbe essere di questo tipo:
 Occorrenze di 'a': 124
 Occorrenze di 'b': 52
 Occorrenze di 'c': 83
 ...
Suggerimento: per trasformare un carattere da maiuscolo a minuscolo si può utilizzare la funzione di libreria
tolower, dopo avere incluso l'header <ctype.h>. Esempio: char character = 'F';
 character = tolower(character); // character è diventato 'f'
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ContaLettere(char *namefile) {
    FILE *fp;
    int count[100] = {0}; // Array to count occurrences of each letter
    char riga;
    fp = fopen(namefile, "r");
    if (fp == NULL) {
        printf("Errore apertura file\n");
        return;
    }
    while ((riga = fgetc(fp)) != EOF) {
        if (isalpha(riga)) { // Check if the character is a letter
            riga = tolower(riga); // Convert to lowercase
            count[riga - 'a']++; // Increment the count for the letter
        }
    }

    fclose(fp);
    fp = fopen("frequenza_lettere.txt", "w");
    if (fp == NULL) {
        printf("Errore apertura file\n");
        return;
    }
    for (int i = 0; i < 26; i++) {
        fprintf(fp, "Occorrenze di '%c': %d\n", 'a' + i, count[i]);
    }
    fclose(fp);
}

int main(void) {
    char namefile[100];
    printf("Inserisci il nome del file di cui contare le lettere: \n");
    scanf("%s", namefile);
    strcat(namefile, ".txt"); // Combines the string namefile with .txt
    ContaLettere(namefile);
    return 0;
}