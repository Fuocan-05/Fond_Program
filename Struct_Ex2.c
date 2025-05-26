/*
Esercizio 2
Si implementi un programma per la gestione del ricettario digitale di un ristorante. Il ricettario contiene un
elenco di pietanze (massimo 100) con i relativi ingredienti e tempi di cottura (si riusi la struct dell’esercizio
precedente). Attraverso un menu testuale deve essere possibile:
a. inserire una nuova pietanza;
b. visualizzare gli ingredienti e le dosi di una pietanza il cui nome è inserito da tastiera;
c. visualizzare l’elenco delle pietanze in base alla tipologia (inserita da tastiera). Per esempio, l’elenco
degli antipasti o dei primi;
d. visualizzare il nome delle pietanze che contengono un certo ingrediente (inserito da tastiera);
e. visualizzare l’elenco delle pietanze con un tempo di cottura minore di un valore inserito da tastiera;
f. uscire dal programma o effettuare una nuova scelta.
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

void Nuova_Pietanza(){
    struct Pietanza p1; // Dichiarazione della variabile di tipo Pietanza
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
    printf("Nome: %s", p1.nome);
    printf("Numero di ingredienti: %d\n", p1.n_ingredienti);
    for (int i = 0; i < p1.n_ingredienti; i++) {
        printf("Ingrediente %d: %s, Dosi: %f grammi\n", i + 1, p1.ingredienti[i], p1.dosi[i]);
    }
    printf("Tempo di cottura: %.2f minuti\n", p1.t_cottura);
    printf("Tipo di pietanza: %s\n", p1.tipo);
    
    // Aggiungi la pietanza al ricettario
    ricettario[n_pietanze] = p1;
    n_pietanze++;
}

void Visualizza_Ingredienti(){
    struct Pietanza; // Dichiarazione della variabile di tipo Pietanza
    char nome[50];
    printf("Inserisci il nome della pietanza da visualizzare: ");
    scanf("%s", nome);
    for (int i = 0; i < n_pietanze; i++) {
        if (strcmp(ricettario[i].nome, nome) == 0) {
            // Stampa le informazioni della pietanza
            printf("Informazioni della pietanza %s:\n", ricettario[i].nome);
            printf("Numero di ingredienti: %d\n", ricettario[i].n_ingredienti);
            for (int j = 0; j < ricettario[i].n_ingredienti; j++) {
                printf("Ingrediente %d: %s, Dosi: %.2f grammi\n", j + 1, ricettario[i].ingredienti[j], ricettario[i].dosi[j]);
            }
            return;
        }
    }
}

void Visualizza_Tipologia(){
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

void Visualizza_Ingrediente(){
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

void Visualizza_Tempo_Cottura(){
    float tempo;
    printf("Inserisci il tempo di cottura massimo (in minuti): ");
    scanf("%f", &tempo);
    printf("Pietanze con un tempo di cottura minore di %.2f minuti:\n", tempo);
    for (int i = 0; i < n_pietanze; i++) {
        if (ricettario[i].t_cottura < tempo + 0.001) { // Aggiunta di una piccola tolleranza per evitare problemi di precisione
            printf("%s\n", ricettario[i].nome);
        }
    }
}

int main(void){
    struct Pietanza p1; // Dichiarazione della variabile di tipo Pietanza
    int scelta;

    printf("Menu di gestione del ricettario:\n");
    printf("1. Inserire una nuova pietanza\n");
    printf("2. Visualizzare gli ingredienti e le dosi di una pietanza\n");
    printf("3. Visualizzare l'elenco delle pietanze in base alla tipologia\n");
    printf("4. Visualizzare il nome delle pietanze che contengono un certo ingrediente\n");
    printf("5. Visualizzare l'elenco delle pietanze con un tempo di cottura minore di un valore\n");
    printf("6. Uscire dal programma\n");

    int turno = 0;

    while(turno == 0) {
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);
        switch (scelta)  // Assuming 'scelta' is defined and set somewhere in the code
        {
        case 1:
            Nuova_Pietanza();
            break;
        case 2:
            Visualizza_Ingredienti();
            break;
        case 3:
            Visualizza_Tipologia();
            break;
        case 4:
            Visualizza_Ingrediente();
            break;
        case 5:
            Visualizza_Tempo_Cottura();
            break;
        case 6:
            printf("Uscita dal programma.\n");
            turno = 1; // Set to 1 to exit the loop
            break;
        default:
            printf("Scelta non valida. Riprova.\n");
            break;
        }
    }
return 0;
}