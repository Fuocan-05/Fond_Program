#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20
struct Spesa {
    char nome[M];
    float prezzo;
    int quantità;
    struct Spesa* next;
};

void printlist(struct Spesa* p) {
    printf("\n");
    while (p != NULL) {
        printf("- %d %s, $%.2f  \n", p->quantità, p->nome, p->prezzo);
        p = p->next;
    }
}

void add(struct Spesa** head) {
    struct Spesa* new = malloc(sizeof(struct Spesa));
    struct Spesa* p = *head;
    printf("Cosa vuoi aggiungere?\n");
    fgets(new->nome, M, stdin);
    new->nome[strcspn(new->nome, "\n")] = 0;
    printf("Qual e' la quantita'?\n");
    scanf("%d", &new->quantità);
    getchar();
    while (p != NULL) {
        if (strcmp(new->nome, p->nome) == 0) {
            p->quantità+=new->quantità;
            free(new);
            printlist(*head);
            return;
        }
        p = p->next;
    }
    printf("Qual e' il prezzo?\n");
    scanf("%f", &new->prezzo);
    getchar();
    new->next = *head;
    *head = new;
    printlist(*head);
}

void rimuovi(struct Spesa** head) {
    struct Spesa* current = *head;
    struct Spesa* previus = NULL;
    char nome[M];
    printf("Qual e' il prodotto da rimuovere?\n");
    scanf("%s", nome);
    getchar();
    while (current != NULL && strcmp(current->nome, nome) != 0) {
        previus = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Prodotto non trovato");
        return;
    }

    if (previus == NULL) {
        *head = current->next;
    } else {
        previus->next = current->next;
    }

    free(current);
    printf("prodotto eliminiato");
    printf("nuova lista:\n");
    printlist(*head);
}

void totale(struct Spesa* p) {
    float sommaprezzo = 0;
    float totale = 0;
    while (p != NULL) {
        sommaprezzo = p->prezzo * p->quantità;
        totale += sommaprezzo;
        p = p->next;
    }
    printf("Totale spesa:\n %.2f\n", totale);
}

void media(struct Spesa* p) {
    float sommaprezzo = 0;
    int sommaquantità = 0;
    float totale = 0;
    float media = 0;
    while (p != NULL) {
        sommaprezzo = p->prezzo * p->quantità;
        sommaquantità += p->quantità;
        totale += sommaprezzo;
        p = p->next;
    }
    media = totale/sommaquantità;
    printf("Media:\n %.2f\n", media);
}

void salvalista(struct Spesa* head, const char* filename) {
    FILE* f = fopen(filename, "w");
    struct Spesa* p = head;
    fprintf(f, "Lista della spesa:\n");
    while (p != NULL) {
        fprintf(f, "- %d %s %.2f\n", p->quantità, p->nome, p->prezzo);
        p = p->next;
    }
    fclose(f);
    printf("Lista salvata su %S\n", filename);
}

void freeall(struct Spesa* p) {
    struct Spesa* temp = p;
    while(p != NULL) {
        p = p->next;
        free(temp);
        temp = p;
    }
}

int main()
{
    char nome[M];
    float prezzo;
    int quantità;
    struct Spesa* head;
    struct Spesa* P1 = malloc(sizeof(struct Spesa));
    struct Spesa* P2 = malloc(sizeof(struct Spesa));
    struct Spesa* P3 = malloc(sizeof(struct Spesa));
    head = P1;
    strcpy(P1->nome, "Pane");
    strcpy(P2->nome, "Latte");
    strcpy(P3->nome, "Uova");
    prezzo = 0.50;
    P1->prezzo = prezzo;
    prezzo = 1.00;
    P2->prezzo = prezzo;
    prezzo = 2.50;
    P3->prezzo = prezzo;
    quantità = 3;
    P1->quantità = quantità;
    quantità = 1;
    P2->quantità = quantità;
    quantità = 5;
    P3->quantità = quantità;
    P1->next = P2;
    P2->next = P3;
    P3->next = NULL;
    printf("Questa e' la tua lista della spesa:");
    printlist(head);
    int attivo = 1;
    int scelta;
    while(attivo == 1) {
        printf("Cosa vuoi fare?\n");
        printf("1. Aggiungere un prodotto alla lista \n");
        printf("2. Rimuovere un prodotto\n");
        printf("3. Scoprire il prezzo totale\n");
        printf("4. Scoprire il prezzo medio\n");
        printf("5. Salva la lista della spesa su file\n");
        printf("6. Esci\n");
        scanf("%d", &scelta);
        getchar();
        switch(scelta) {
            case 1:
                //aggiungi prodotto
                add(&head);
                break;
            case 2:
                //rimuovi prodotto
                rimuovi(&head);
                break;
            case 3:
                //prezzo totale
                totale(head);
                break;
            case 4:
                //prezzo medio
                media(head);
                break;
            case 5:
                salvalista(head, "Spesa.txt");
                break;
            case 6:
                attivo = 0;
                break;
            default:
                printf("scelta non valida");
                break;
        }
    }
    freeall(head);
    return 0;
}
