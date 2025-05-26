#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int get_element(int i, int j, int righe, int colonne, int matrice[righe][colonne], bool valido)
{
    
    printf("inserisci la riga e la colonna da cui estrarre il valore: ");
    while (valido == true) {
    scanf("%d %d", &i, &j);

    // Controlla se gli indici sono validi
    if(i < 1 || i > righe || j < 1 || j > colonne) {
        printf("Indici non validi. Riprova.\n");
        valido = true;
    }else if (i > 1 || i < righe || j > 1 || j < colonne) {
        // Decrementa di 1 per l'indice zero-based
        i = i - 1; 
        j = j - 1;
        printf("Il valore in riga %d e in colonna %d e': %d\n", i + 1, j + 1, matrice[i][j]);
        valido = false;
    }
    }

    return 0;
}

int set_element(int i, int j, int righe, int colonne, int matrice[righe][colonne], bool valido)
{
    printf("inserisci la riga e la colonna di cui vuoi cambiare il valore: ");
    while (valido == true)
    {
        scanf("%d %d", &i, &j);
        // Controlla se gli indici sono validi
        if(i < 1 || i > righe || j < 1 || j > colonne) {
            printf("Indici non validi. Riprova.\n");
            valido = true;
        }else if (i > 1 || i < righe || j > 1 || j < colonne) {    
            // Decrementa di 1 per l'indice zero-based
            i = i - 1; 
            j = j - 1;
            printf("inserisci il nuovo valore: ");
            int nuovo_valore;
            scanf("%d", &nuovo_valore);
            matrice[i][j] = nuovo_valore;
            printf("Il valore in riga %d e in colonna %d e' stato cambiato in: %d\n", i + 1, j + 1, matrice[i][j]);
            printf("La matrice ora e':\n");

            // Stampa la matrice
            printf("Matrice:\n");
            for (int i = 0; i < righe; i++) {
                for (int j = 0; j < colonne; j++) {
                    printf("%d ", matrice[i][j]);
                }
                printf("\n");
            }
            valido = false;
        }
    }

    return 0;
}

int main(void)
{
    bool valido = true;
    int righe, colonne;
    printf("Inserisci il numero di righe: ");
    scanf("%d", &righe);
    printf("Inserisci il numero di colonne: ");
    scanf("%d", &colonne);

    int matrice[righe][colonne];
    srand(time(NULL));

    // Inizializza la matrice con valori casuali
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            matrice[i][j] = rand() % 101; // Valori casuali tra 0 e 100
        }
    }

    // Stampa la matrice
    printf("Matrice:\n");
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    get_element(0, 0, righe, colonne, matrice, valido);
    set_element(0, 0, righe, colonne, matrice, valido);

    return 0;
}