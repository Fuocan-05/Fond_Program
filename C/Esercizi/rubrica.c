#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 50
#define m 11

struct rubrica
{
    char nome[M];
    char cognome[M];
    char numero[m];
    struct rubrica* next;
};

void ordinalista (struct rubrica** head) {
    struct rubrica* i;
    struct rubrica* j;
    char tnome[M], tcognome[M], tnumero[m];
    if (*head == NULL) {
        printf("Rubrica vuota\n");
        return;
    }

    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->nome, j->nome) > 0) {
                strcpy(tnome, i->nome);
                strcpy(tcognome, i->cognome);
                strcpy(tnumero, i->numero);

                strcpy(i->nome, j->nome);
                strcpy(i->cognome, j->cognome);
                strcpy(i->numero, j->numero);

                strcpy(j->nome, tnome);
                strcpy(j->cognome, tcognome);
                strcpy(j->numero, tnumero);
            }
        }
    }
}

void printfile(struct rubrica* p) {
    FILE* fp = fopen("rubrica.txt", "w");
    while(p != NULL) {
        fprintf(fp, "%s %s %s\n", p->nome, p->cognome, p->numero);
        p = p->next;
    }
    fclose(fp);
}

void freeall(struct rubrica* p) {
    struct rubrica* temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}


int main(){
    FILE* fp;
    struct rubrica* head = NULL;
    char nome[M], cognome[M], numero[m];
    fp = fopen("rubrica.txt", "r");
    while(fscanf(fp, "%s %s %s", nome, cognome, numero) == 3) {
        struct rubrica* nuovo = malloc(sizeof(struct rubrica));
        strcpy(nuovo->nome, nome);
        strcpy(nuovo->cognome, cognome);
        strcpy(nuovo->numero, numero);
        nuovo->next = head;
        head = nuovo;
    }
    ordinalista(&head);
    fclose(fp);
    printfile(head);

    freeall(head);
    return 0;
}

