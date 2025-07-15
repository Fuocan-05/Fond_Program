#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 6

struct noleggi
{
    char ID[M];
    char tipo;
    int giorni;
    struct noleggi* next;
};

void freeall(struct noleggi* p) {
    struct noleggi* temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}

void printfile(struct noleggi* p) {
    FILE* fp = fopen("noleggi.txt", "w");
    while (p != NULL) {
        fprintf(fp, "%s %c %d\n", p->ID, p->tipo, p->giorni);
        p = p->next;
    }
    printf("\nLista reggistrata\n");
    fclose(fp);
}

void aggiungi(struct noleggi** head) {
    char ID[M];
    struct noleggi* p = *head;
    struct noleggi* nuovo = malloc(sizeof(struct noleggi));
    printf("Inserire ID del noleggio\n");
    getchar();
    scanf("%s", ID);
    while (p != NULL) {
        if (strcmp(p->ID, ID) == 0) {
            printf("Questo ID ha già un noleggio\n");
            return;
        }
        p = p->next;
    }
    strcpy(nuovo->ID, ID);

    int errore = 1;
    while (errore == 1) {
        printf("Inserire tipo di veicolo A/B (A = moto / B = auto)\n");
        getchar();
        scanf("%c", &nuovo->tipo);
        if (nuovo->tipo != 'A' && nuovo->tipo != 'B') {
            printf("Tipo di veicolo inserito errato\n");
        } else {
            errore = 0;
        }
    }

    printf("Inserire per quanti giorni durera il noleggio: \n");
    getchar();
    scanf("%d", &nuovo->giorni);

    nuovo->next = *head;
    *head = nuovo;
    printfile(*head);
}

void rimuovi (struct noleggi** head) {
    struct noleggi* current = *head;
    struct noleggi* previus = NULL;
    char ID[M];
    printf("Inserire l'ID del noleggio da eliminare: ");
    getchar();
    scanf("%s", ID);
    while (current != NULL && strcmp(current->ID, ID) != 0) {
        previus = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Errore, ID non trovato\n");
    } else if (previus == NULL) {
        *head = current->next;
    } else {
        previus->next = current->next;
    }

    free(current);
    printf("Noleggio eliminato\n");
    printfile(*head);
}

void totale(struct noleggi* p) {
    int moto = 0;
    int macchina = 0;
    while (p != NULL) {
        if (p->tipo == 'A') {
            moto++;
        } else if (p->tipo == 'B') {
            macchina++;
        }
        p = p->next;
    }
    printf("Totale noleggi: %d moto | %d auto\n", moto, macchina);
}

void media(struct noleggi* p) {
    float mediamoto;
    float mediaauto;
    int sommamoto = 0;
    int sommaauto = 0;
    int moto = 0;
    int macchina = 0;
    while (p != NULL) {
        if (p->tipo == 'A') {
            moto++;
            sommamoto += p->giorni;
        } else if (p->tipo == 'B') {
            macchina++;
            sommaauto += p->giorni;
        }
        p = p->next;
    }
    mediaauto = sommaauto / macchina;
    mediamoto = sommamoto / moto;
    printf("Media di giorni per veicolo: %.2f giorni medi per le moto | %.2f giorni medi per le auto\n", mediamoto, mediaauto);
}

int main()
{
    FILE* fp;
    fp = fopen("noleggi.txt", "r");
    struct noleggi* head = NULL;
    char ID[M];
    char tipo;
    int giorni;

    while (fscanf(fp, "%5s %c %d", ID, &tipo, &giorni) == 3) {
        struct noleggi* nuovo = malloc(sizeof(struct noleggi));
        strcpy(nuovo->ID, ID);
        nuovo->tipo = tipo;
        nuovo->giorni = giorni;
        nuovo->next = head;
        head = nuovo;
    }

    int choice;
    int active = 1;

    while (active == 1) {
        printf("Cosa vuoi fare?: \n");
        printf("1. aggiungi noleggio\n");
        printf("2. rimuovi noleggio\n");
        printf("3. stampare totale noleggi\n");
        printf("4. stampa tempo medio noleggi\n");
        printf("5. esci\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                //aggiungi
                aggiungi(&head);
                break;
            case 2:
                //rimuovi
                rimuovi(&head);
                break;
            case 3:
                //totale
                totale(head);
                break;
            case 4:
                //media
                media(head);
                break;
            case 5:
                //esci
                active = 0;
                break;
            default:
                printf("errore nella scelta\n");
                break;
        }
    }

    fclose(fp);
    printfile(head);
    freeall(head);
    return 0;
}

