#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


//versione letterale
int main()
{
    char sceltaUtente[10]; //array di caratteri

    srand(time(NULL));

    printf("Gioca a Sasso, carta, forbice con me!\n");
    scanf("%s", sceltaUtente);

    for (int i = 0; i < strlen(sceltaUtente); i++) //trasforma la stringa in minuscolo
    {
        sceltaUtente[i] = tolower(sceltaUtente[i]);
    }

   if (strcmp(sceltaUtente, "sasso") != 0 && strcmp(sceltaUtente, "carta") != 0 && strcmp(sceltaUtente, "forbice") != 0) //casistica di ERRORE
    {
        printf("Scelta non valida!\n");
        return 1;
    }

    int sceltaComputer;
    sceltaComputer = rand() % 3; //genera un numero casuale tra 0 e 2

    //stampa la scelta del computer
    if (sceltaComputer == 0)
    {
        printf("Il computer ha scelto: sasso\n");
    }
    else if (sceltaComputer == 1)
    {
        printf("Il computer ha scelto: carta\n");
    }
    else if (sceltaComputer == 2)
    {
        printf("Il computer ha scelto: forbice\n");
    }

    //casistiche di PAREGGIO, VITTORIA e SCONFITTA
    if (strcmp(sceltaUtente, "sasso") == 0 && sceltaComputer == 0 || strcmp(sceltaUtente, "carta") == 0 && sceltaComputer == 1 || strcmp(sceltaUtente, "forbice") == 0 && sceltaComputer == 2)
    {
        printf("Pareggio!\n");
    }
    else if (strcmp(sceltaUtente, "sasso") == 0 && sceltaComputer == 2 || strcmp(sceltaUtente, "carta") == 0 && sceltaComputer == 0 || strcmp(sceltaUtente, "forbice") == 0 && sceltaComputer == 1)
    {
        printf("Hai vinto!\n");
    }
    else if (strcmp(sceltaUtente, "sasso") == 0 && sceltaComputer == 1 || strcmp(sceltaUtente, "carta") == 0 && sceltaComputer == 2 || strcmp(sceltaUtente, "forbice") == 0 && sceltaComputer == 0)
    {
        printf("Hai perso!\n");
    }

    return 0;

}



/* Versione numerale
int main()
{

    srand(time(NULL));
    

    printf(" Gioca a Sasso, carta, forbice con me!\n Sasso [0], Carta [1], Forbice [2]\n");
    

    int sceltaUtente;
    scanf("%d", &sceltaUtente);

    
    if (sceltaUtente > 2) //casistica di ERRORE
    {
        printf("Scelta non valida!\n"); 
        return 0;
    }


    int sceltaComputer;
    sceltaComputer = rand() % 3;


    printf("Hai scelto: %d\n", sceltaUtente);
    printf("Il computer ha scelto: %d\n", sceltaComputer);


    if (sceltaUtente == sceltaComputer) //casistica di PAREGGIO
    {
        printf("Pareggio!\n");
    }
    else if (sceltaUtente == 0 && sceltaComputer == 2 || sceltaUtente == 1 && sceltaComputer == 0 || sceltaUtente == 2 && sceltaComputer == 1) //casistica di VITTORIA
    {
        printf("Hai vinto!\n");
    }
    else if (sceltaUtente == 0 && sceltaComputer == 1 || sceltaUtente == 1 && sceltaComputer == 2 || sceltaUtente == 2 && sceltaComputer == 0) //Casistica di SCONFITTA
    {
        printf("Hai perso!\n");
    }
    

    return 0;

}
*/
