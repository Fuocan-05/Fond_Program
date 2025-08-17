#include <stdio.h>
#include <string.h>
#include <unistd.h> // per sleep


int CopiaStringa(char str[], char str2[])
{
    printf("Inserisci la prima stringa: ");
    scanf("%s", str);
    sleep(2);
    printf("adesso copiero la prima stringa nella seconda\n");
    strcpy(str2, str); // Copia la stringa str in str2
    printf("La seconda stringa e': %s\n", str2);
}

int ConcatenaStringa(char str[], char str2[])
{
    printf("Inserisci la prima stringa: ");
    scanf("%s", str);
    sleep(2);
    printf("Inserisci la seconda stringa:");
    scanf("%s", str2);
    sleep(2);
    printf("adesso concateno la prima stringa con la seconda\n");
    strcat(str, str2); // Concatena str2 alla fine di str
    printf("La stringa concatenata e': %s\n", str);
    
}

int ComparaStringa(char str[], char str2[])
{
    printf("Inserisci la prima stringa: ");
    scanf("%s", str);
    sleep(2);
    printf("Inserisci la seconda stringa:");
    scanf("%s", str2);
    sleep(2);
    printf("adesso controllo quale delle due stringhe viene prima in ordine alfabetico\n");
    int risultato = strcmp(str, str2); // Confronta le due stringhe
    printf("Il risultato del confronto e': %d\n", risultato);
}

int main(void)
{
    char str[100]; // Array per la prima stringa
    char str2[100]; // Array per la seconda stringa

    
    char scelta[100]; // Array per la scelta dell'utente
    int attivo = 1; // Variabile per controllare se il programma è attivo

    
    while (attivo == 1)
    {

        printf("scegli quello che vuoi fare:\n");
        printf("copia\n");
        printf("concatena\n");
        printf("compara\n");
        printf("esci\n");
        printf("inserisci la tua scelta: ");


        scanf("%s", scelta);
        if (strcmp(scelta, "copia") == 0)
        {
            printf("Hai scelto di copiare la stringa\n");
            CopiaStringa(str, str2); // Chiama la funzione per copiare la stringa
        }
        else if (strcmp(scelta, "concatena") == 0)
        {
            printf("Hai scelto di concatenare la stringa\n");
            ConcatenaStringa(str, str2); // Chiama la funzione per concatenare la stringa
        }
        else if (strcmp(scelta, "esci") == 0)
        {
            printf("Hai scelto di uscire\n");
            attivo = 0; // Imposta attivo a 0 per uscire dal ciclo
        }
        else if (strcmp(scelta, "compara") == 0)
        {
            printf("Hai scelto di comparare la stringa\n");
            ComparaStringa(str, str2); // Chiama la funzione per comparare le stringhe
        }
        else
        {
            printf("Scelta non valida!\n");
        }
    }

    return 0;
}