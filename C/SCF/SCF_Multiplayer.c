#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


//versione letterale
int main()
{
    printf("\033[H\033[J"); // usa il comando clear per il terminale

    char sceltaUtente1[10]; //array di caratteri
    char sceltaUtente2[10];

    printf("Gioca a Sasso, carta,forbice VS\n");
    
    sleep(1); //pausa di 1 secondo

    printf("Giocatore 1, inserisci la tua scelta: ");
    scanf("%s", sceltaUtente1);
    printf("\033[H\033[J"); // usa il comando clear per il terminale

    for (int i = 0; i < strlen(sceltaUtente1); i++) //trasforma la stringa in minuscolo
    {
        sceltaUtente1[i] = tolower(sceltaUtente1[i]);
    }

   if (strcmp(sceltaUtente1, "sasso") != 0 && strcmp(sceltaUtente1, "carta") != 0 && strcmp(sceltaUtente1, "forbice") != 0) //casistica di ERRORE
    {
        printf("Scelta non valida!\n");
        return 1;
    }

    sleep(1);

    printf("Giocatore 2, inserisci la tua scelta: ");
    scanf("%s", sceltaUtente2);
    printf("\033[H\033[J"); // Svuota l'interfaccia del terminale

    for (int i = 0; i < strlen(sceltaUtente2); i++) //trasforma la stringa in minuscolo
    {
        sceltaUtente2[i] = tolower(sceltaUtente2[i]);
    }

   if (strcmp(sceltaUtente2, "sasso") != 0 && strcmp(sceltaUtente2, "carta") != 0 && strcmp(sceltaUtente2, "forbice") != 0) //casistica di ERRORE
    {
        printf("Scelta non valida!\n");
        return 1;
    }

    sleep(2);

    //casistiche di PAREGGIO, VITTORIA e SCONFITTA
    if (strcmp(sceltaUtente1, sceltaUtente2) == 0)
    {
        printf("Pareggio!\n");
    }
    else if (strcmp(sceltaUtente1, "sasso") == 0 && strcmp(sceltaUtente2, "forbice") == 0  || strcmp(sceltaUtente1, "carta") == 0 && strcmp(sceltaUtente2, "sasso") == 0 || strcmp(sceltaUtente1, "forbice") == 0 && strcmp(sceltaUtente2, "carta") == 0)
    {
        printf("Giocatore 1, hai vinto!\n");
    }
    else if (strcmp(sceltaUtente1, "sasso") == 0 && strcmp(sceltaUtente2, "carta") == 0 || strcmp(sceltaUtente1, "carta") == 0 && strcmp(sceltaUtente2, "forbice") == 0 || strcmp(sceltaUtente1, "forbice") == 0 && strcmp(sceltaUtente2, "sasso") == 0)
    {
        printf("Giocatore 2, hai vinto!\n");
    }
    
    return 0;

}
