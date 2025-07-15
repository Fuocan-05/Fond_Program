#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 50

struct leggiparola
{
    char parola[M];
    struct leggiparola* next;
};

int main()
{
    FILE* fp = fopen("leggiparola.txt", "r");
    char parola[M];
    struct leggiparola* head;
    struct leggiparola* nodo1 = malloc(sizeof(struct leggiparola));

    if (fp == NULL) {
        printf("errore nell'apertura del file");
        exit(1);
    }

    while (fscanf(fp, "%s", parola) != EOF) {
            printf("parola letta: %s\n", parola);
            strcpy(nodo1->parola, parola);
            printf("parola reggistrata nella lista: %s", nodo1->parola);
    }

    free(nodo1);
    fclose(fp);
    return 0;
}

