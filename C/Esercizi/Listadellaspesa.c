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

void printfile(struct spesa* p) {
    FILE* fp = fopen("Listadellaspesa.txt", "w");
    while (p != NULL) {
        fprintf(fp, "\n%d %s %.2f\n", p->quantita, p->nome, p->prezzo);
        p = p->next;
    }
    fclose(fp);
}

void freeall(struct spesa* p) {
    struct spesa* temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}

void aggiungi(struct spesa** head) {
    struct spesa* nuovo = malloc(sizeof(struct spesa));
    struct spesa* p = *head;
    char nome[M];
    FILE* fp;
    fp = fopen("Listadellaspesa.txt", "a");
    printf("\nCosa vuoi aggiungere?: \n");
    scanf("%d", &nuovo->quantita);
    scanf("%s", nome);
    strcpy(nuovo->nome, nome);
    while (p != NULL) {
        if (strcmp(p->nome, nuovo->nome) == 0) {
            p->quantita += nuovo->quantita;
            fclose(fp);
            printfile(*head);
            free(nuovo);
            return;
        }
        p = p->next;
    }
    scanf("%f", &nuovo->prezzo);

    printf("Elemento da aggiungere in lista:\n - %d | %s | %.2f\n", nuovo->quantita, nuovo->nome, nuovo->prezzo);
    fprintf(fp, "\n%d %s %.2f\n", nuovo->quantita, nuovo->nome, nuovo->prezzo);
    nuovo->next = *head;
    *head = nuovo;
    printf("Elemento inserito nel file\n");
    fclose(fp);
}

void elimina(struct spesa** head) {
    char nome[M];
    struct spesa* current = *head;
    struct spesa* previus = NULL;
    FILE* fp = fopen("Listadellaspesa.txt", "w");
    printf("Inserire il nome dell'elemento da eliminare: \n");
    scanf("%s", nome);
    while (current != NULL && strcmp(current->nome, nome) != 0) {
        previus = current;
        current = current->next;
    }

    if (previus == NULL) {
        *head = current->next;
    } else if (current = NULL) {
        printf("Elemento non trovato in lista \n");
        return;
    } else {
        previus->next = current->next;
    }

    free(current);
    printf("Elemneto eliminato\n");

    previus = *head;
    while (previus != NULL) {
        fprintf(fp, "%d %s %.2f\n", previus->quantita, previus->nome, previus->prezzo);
        previus = previus->next;
    }
    printf("Lista aggiornata\n");
    fclose(fp);
    
}

void totale(struct spesa* p) {
    float sommaprezzo = 0;
    float totale = 0;
    while (p != NULL) {
        sommaprezzo = p->prezzo * p->quantita;
        totale += sommaprezzo;
        p = p->next;
    }
    printf("Totale spesa:\n %.2f\n", totale);
}

void media(struct spesa* p) {
    float sommaprezzo = 0;
    int sommaquantità = 0;
    float totale = 0;
    float media = 0;
    while (p != NULL) {
        sommaprezzo = p->prezzo * p->quantita;
        sommaquantità += p->quantita;
        totale += sommaprezzo;
        p = p->next;
    }
    media = totale/sommaquantità;
    printf("Media:\n %.2f\n", media);
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
    fclose(fp);

    int attivo = 1;
    int scelta;
    
    while(attivo == 1) {
        printf("\nCosa vuoi fare?: \n");
        printf("1. Aggiungere elemento alla lista della spesa\n");
        printf("2. Eliminare elemnto dalla lista della spesa\n");
        printf("3. Calcolare il costo totale della spesa\n");
        printf("4. Calcolare il prezzo medio della spesa\n");
        printf("5. Uscire\n");
        scanf("%d", &scelta);
        switch(scelta) {
            case 1:
                //aggiungi
                aggiungi(&head);
                break;
            case 2:
                //elimina
                elimina(&head);
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
                printf("Arrivederci\n");
                attivo = 0;
                break;
            default:
                printf("Selezione non presente all'interno del menu\n");
                break; 
        }
    }
    

    freeall(head);
    return 0;
}