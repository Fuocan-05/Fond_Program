#include <stdio.h>

int main(void)
{
    int secondi, minuti, ore;
    int tot_secondi;

    printf("Inserisci un orario (hh:mm:ss): ");
    scanf("%d:%d:%d", &ore, &minuti, &secondi);

    tot_secondi = secondi + minuti * 60 + ore * 3600;

    printf("Totale secondi = %d", tot_secondi);

    return 0;
}