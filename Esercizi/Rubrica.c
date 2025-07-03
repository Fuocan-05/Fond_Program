#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20 

struct Rubrica {
    char nome[MAX];
    char numero[11];
    struct Rubrica* next;
};


void printlist(struct Rubrica* p) {
    printf("\n");
    printf("\n Ecco i tuoi contatti: \n");
    while(p != NULL) {
        printf("- %s\n", p->nome);
        p = p->next;
    }
    printf("\n");
}

void NuovoContatto(struct Rubrica** head, char nome[MAX], char numero[10]) {
    struct Rubrica* nuovocontatto = malloc(sizeof(struct Rubrica));
    printf("\n Inserisci il nome del contatto: ");
    fgets(nuovocontatto->nome, MAX, stdin);
    nuovocontatto->nome[strcspn(nuovocontatto->nome, "\n")] = 0;
    printf("\n Inserisci il numero di telefono: ");
    fgets(nuovocontatto->numero, 11, stdin);
    nuovocontatto->numero[strcspn(nuovocontatto->numero, "\n")] = 0;
    nuovocontatto->next = *head;
    *head = nuovocontatto;
    printlist(*head);
}

void CercaContatto(struct Rubrica* head, char nome[MAX]) {
    struct Rubrica* temp = head;
    printf("\nChi vuoi cercare?\n");
    fgets(nome, MAX, stdin);
    nome[strcspn(nome, "\n")] = 0;
    while(temp != NULL) {
        if (strcmp(temp->nome, nome) == 0) {
            printf("\n Contatto trovato: %s, Numero: %s\n", temp->nome, temp->numero);
            return;
        }
        temp = temp->next;
    }
    printf("\n Contatto non trovato.\n");
}

void LiberaTutto(struct Rubrica* p) {
    while (p != NULL) {
        struct Rubrica* temp = p;
        p = p->next;
        free(temp);
    }
}


int main()
{
    char nome[MAX];
    char numero[11];

    struct Rubrica* head = NULL;


    int turno = 1;
    int scelta;

    while (turno == 1) {
        printf("\n Ciao cosa vuoi fare?");
        printf("\n  1. Inserire nuovo contatto");
        printf("\n  2. Cercare contatto");
        printf("\n  3. Stampa rubrica");
        printf("\n  4. Uscire");

        printf("\n Inserire la tua scelta: ");
        scanf("%d", &scelta);
        getchar();
        switch(scelta) {
            case 1:
                //nuovo contatto
                NuovoContatto(&head, nome, numero);
                break;
            case 2:
                //cerca contatto
                CercaContatto(head, nome);
                break;
            case 3:
                //stampa rubrica
                printlist(head);
                break;
            case 4:
                //esci
                printf(" ciao!");
                turno = 0;
                break;
            default:
                printf(" errore");
                break;
        }  
    }
    // Libera la memoria allocata per la rubrica
    LiberaTutto(head);
    return 0;
}
