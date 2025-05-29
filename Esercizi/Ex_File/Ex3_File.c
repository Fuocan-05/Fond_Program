/*
Esercizio 3
Modificare il programma dell’esercitazione precedente per memorizzare il ricettario all’interno di un file.
Il nome del file deve essere passato come parametro da riga di comando.
All’avvio del programma deve essere caricato il contenuto attuale del ricettario nelle opportune strutture dati.
Ogni volta che si vuole inserire una nuova pietanza, questa, oltre ad essere aggiunta alle opportune strutture
dati, deve anche essere memorizzata all’interno del file.
Nota 1: è necessario stabilire il formato che deve avere il file, in termini di separatori tra i vari campi
Nota 2: riflettere sulla modalità di apertura del file più adatta
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PIETANZE 100

struct Pietanza {
    char nome[50];
    int n_ingredienti;
    char ingredienti[10][50];
    float dosi[100];
    float t_cottura;
    char tipo[20]; // "primo", "secondo", "contorno", "dolce"
};
struct Pietanza ricettario[MAX_PIETANZE];
int n_pietanze = 0;

void Nuova_Pietanza(FILE *fp) {
    struct Pietanza p1;
    if (n_pietanze >= MAX_PIETANZE) {
        printf("Limite massimo di pietanze raggiunto.\n");
        return;
    }
    printf("Inserisci il nome della pietanza: ");
    scanf("%s", p1.nome);
    printf("Inserisci il numero di ingredienti: ");
    scanf("%d", &p1.n_ingredienti);
    printf("Inserisci gli ingredienti:\n");
    for (int i = 0; i < p1.n_ingredienti; i++) {
        printf("Ingrediente %d: ", i + 1);
        scanf("%s", p1.ingredienti[i]);
    }
    printf("Inserisci le dosi degli ingredienti (in grammi):\n");
    for (int i = 0; i < p1.n_ingredienti; i++) {
        printf("Dosi per %s: ", p1.ingredienti[i]);
        scanf("%f", &p1.dosi[i]);
    }
    printf("Inserisci il tempo di cottura (in minuti): ");
    scanf("%f", &p1.t_cottura);
    printf("Inserisci il tipo di pietanza (primo, secondo, contorno, dolce): ");
    scanf("%s", p1.tipo);
    // Stampa le informazioni della pietanza
    printf("Ecco il tuo piatto:\n");
    printf("Nome: %s\n", p1.nome);
    printf("Numero di ingredienti: %d\n", p1.n_ingredienti);
    for (int i = 0; i < p1.n_ingredienti; i++) {
        printf("Ingrediente %d: %s, Dosi: %.2f grammi\n", i + 1, p1.ingredienti[i], p1.dosi[i]);
    }
    ricettario[n_pietanze++] = p1;
    // Aggiungi la pietanza al ricettario
    fprintf(fp, "%s;%d;", p1.nome, p1.n_ingredienti);
    for (int i = 0; i < p1.n_ingredienti; i++) {
        fprintf(fp, "%s,%.2f;", p1.ingredienti[i], p1.dosi[i]);
    }
    fprintf(fp, "%.2f;%s\n", p1.t_cottura, p1.tipo);
    fflush(fp);
    fclose(fp);
    printf("Pietanza salvata con successo!\n");
}


void CreaRicettario(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File non trovato, creando un nuovo file.\n");
        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Errore nell'apertura del file.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        // Carica il contenuto del file nel ricettario
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            struct Pietanza p1;
            char *token = strtok(line, ";");
            strcpy(p1.nome, token);
            token = strtok(NULL, ";");
            p1.n_ingredienti = atoi(token);
            for (int i = 0; i < p1.n_ingredienti; i++) {
                token = strtok(NULL, ",");
                strcpy(p1.ingredienti[i], token);
                token = strtok(NULL, ";");
                p1.dosi[i] = atof(token);
            }
            token = strtok(NULL, ";");
            p1.t_cottura = atof(token);
            token = strtok(NULL, "\n");
            strcpy(p1.tipo, token);
            ricettario[n_pietanze++] = p1;
        }
    }
    fclose(fp);
}

void Visualizza_Pietanze() {
    printf("Elenco delle pietanze:\n");
    for (int i = 0; i < n_pietanze; i++) {
        printf("Pietanza %d: %s, Tipo: %s, Tempo di cottura: %.2f minuti\n",
               i + 1, ricettario[i].nome, ricettario[i].tipo, ricettario[i].t_cottura);
        printf("Ingredienti:\n");
        for (int j = 0; j < ricettario[i].n_ingredienti; j++) {
            printf(" - %s: %.2f grammi\n", ricettario[i].ingredienti[j], ricettario[i].dosi[j]);
        }
    }
}

void Visualizza_Ingredienti() {
    char nome[50];
    printf("Inserisci il nome della pietanza da visualizzare: ");
    scanf("%s", nome);
    for (int i = 0; i < n_pietanze; i++) {
        if (strcmp(ricettario[i].nome, nome) == 0) {
            printf("Informazioni della pietanza %s:\n", ricettario[i].nome);
            printf("Numero di ingredienti: %d\n", ricettario[i].n_ingredienti);
            for (int j = 0; j < ricettario[i].n_ingredienti; j++) {
                printf("Ingrediente %d: %s, Dosi: %.2f grammi\n", j + 1, ricettario[i].ingredienti[j], ricettario[i].dosi[j]);
            }
            return;
        }
    }
    printf("Pietanza non trovata.\n");
}

void Visualizza_Tipologia() {
    char tipo[20];
    printf("Inserisci il tipo di pietanza da visualizzare (primo, secondo, contorno, dolce): ");
    scanf("%s", tipo);
    printf("Elenco delle pietanze di tipo %s:\n", tipo);
    for (int i = 0; i < n_pietanze; i++) {
        if (strcmp(ricettario[i].tipo, tipo) == 0) {
            printf("%s\n", ricettario[i].nome);
        }
    }
}

void Visualizza_Ingrediente() {
    char ingrediente[50];
    printf("Inserisci l'ingrediente da cercare: ");
    scanf("%s", ingrediente);
    printf("Pietanze che contengono l'ingrediente %s:\n", ingrediente);
    for (int i = 0; i < n_pietanze; i++) {
        for (int j = 0; j < ricettario[i].n_ingredienti; j++) {
            if (strcmp(ricettario[i].ingredienti[j], ingrediente) == 0) {
                printf("%s\n", ricettario[i].nome);
                break;
            }
        }
    }
}

void Rimuovi_Pietanza() {
    char nome[50];
    printf("Inserisci il nome della pietanza da rimuovere: ");
    scanf("%s", nome);
    for (int i = 0; i < n_pietanze; i++) {
        if (strcmp(ricettario[i].nome, nome) == 0) {
            for (int j = i; j < n_pietanze - 1; j++) {
                ricettario[j] = ricettario[j + 1];
            }
            n_pietanze--;
            printf("Pietanza %s rimossa con successo.\n", nome);
            return;
        }
    }
    printf("Pietanza non trovata.\n");
}

int main(void) {
    CreaRicettario("ricettario.txt");
    FILE *fp = fopen("ricettario.txt", "a");
    if (fp == NULL) {
        printf("Errore nell'apertura del file per scrittura.\n");
        return 1;
    }
    int scelta;
    printf("Menu di gestione del ricettario:\n");
    printf("1. Aggiungi nuova pietanza\n");
    printf("2. Visualizza tutte le pietanze\n");
    printf("3. Visualizza ingredienti di una pietanza\n");
    printf("4. Visualizza pietanze per tipologia\n");
    printf("5. Visualizza pietanze per ingrediente\n");
    printf("6. Rimuovi pietanza\n");
    printf("7. Esci\n");
    while (1) {
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                Nuova_Pietanza(fp);
                break;
            case 2:
                Visualizza_Pietanze();
                break;
            case 3:
                Visualizza_Ingredienti();
                break;
            case 4:
                Visualizza_Tipologia();
                break;
            case 5:
                Visualizza_Ingrediente();
                break;
            case 6:
                Rimuovi_Pietanza();
                break;
            case 7:
                printf("Uscita dal programma.\n");
                fclose(fp);
                return 0;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    }
    return 0;
}