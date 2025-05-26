// Esercizio n1 dell'esercitazione sulle strutture in C
// Descrizione: Creare una struttura per rappresentare una pietanza con nome, numero di ingredienti,
// ingredienti, dosi, tempo di cottura e tipo (primo, secondo, contorno, dolce).


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pietanza {
    char nome[50];
    int n_ingredienti;
    char ingredienti[10][50];
    int dosi[100];
    float t_cottura;
    char tipo[20]; // "primo", "secondo", "contorno", "dolce"
};

int main() {

    struct Pietanza p1; // Dichiarazione della variabile di tipo Pietanza
    // Inizializzazione della pietanza
    printf("Inserisci il nome della pietanza: ");
    fgets(p1.nome, sizeof(p1.nome), stdin);
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
        scanf("%d", &p1.dosi[i]);
    }
    printf("Inserisci il tempo di cottura (in minuti): ");
    scanf("%f", &p1.t_cottura);
    printf("Inserisci il tipo di pietanza (primo, secondo, contorno, dolce): ");
    scanf("%s", p1.tipo);
    // Stampa le informazioni della pietanza
    printf("Ecco il tuo piatto:\n");
    printf("Nome: %s", p1.nome);
    printf("Numero di ingredienti: %d\n", p1.n_ingredienti);
    for (int i = 0; i < p1.n_ingredienti; i++) {
        printf("Ingrediente %d: %s, Dosi: %d grammi\n", i + 1, p1.ingredienti[i], p1.dosi[i]);
    }
    printf("Tempo di cottura: %.2f minuti\n", p1.t_cottura);
    printf("Tipo di pietanza: %s\n", p1.tipo);
    return 0;
}