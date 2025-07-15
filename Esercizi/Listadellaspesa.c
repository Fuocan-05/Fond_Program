#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 50

struct spesa
{
    char nome[M];
    float prezzo;
    int quantita;
    struct spesa* next;
};

void printlist(struct spesa* p) {
    printf("\nEcco la tua lista della spesa: \n");
    while (p != NULL) {
        printf("- %d | %s | %.2f\n", p->quantita, p->nome, p->prezzo);
        p = p->next;
    }
}

void freeall(struct spesa* p) {
    struct spesa* temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    FILE* fp = fopen("Listadellaspesa.txt", "r");

    if (fp == NULL) {
        printf("Errore nell'apertura del file");
        exit(1);
    }

    struct spesa* head = NULL;
    char nome[M];
    int quantita;
    float prezzo;

    while (fscanf(fp, "%d %s %f", &quantita, nome, &prezzo) == 3) {
        struct spesa* nuovo = malloc(sizeof(struct spesa));
        nuovo->quantita = quantita;
        strcpy(nuovo->nome, nome);
        nuovo->prezzo = prezzo;
        nuovo->next = head;
        head = nuovo;
    }

    
    printlist(head);
    freeall(head);
    fclose(fp);
    
    return 0;
}