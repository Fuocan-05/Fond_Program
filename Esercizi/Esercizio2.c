#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100

int ContaCaratteri(char str[M]) {
    int minuscole = 0;
    int maiuscole = 0;
    int numeri = 0;
    int spazi = 0;
    int caratteriSpeciali = 0;
    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            minuscole++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') 
        {
            maiuscole++;
        }
        else if(str[i] >= '0' && str[i] <= '9') 
        {
            numeri++;
        }
        else if(str[i] == ' ') 
        {
            spazi++;
        }
        else
        {
            caratteriSpeciali++;
        }
    }

    printf("Caratteri minuscoli: %d\n", minuscole);
    printf("Caratteri maiuscoli: %d\n", maiuscole);
    printf("Caratteri numerici: %d\n", numeri);
    printf("Caratteri spazi: %d\n", spazi);
    printf("Caratteri speciali: %d\n", caratteriSpeciali);

    return 0;
}

int main(void){
    char str[M];
    printf("Inserisci una stringa: ");
    scanf("%s", str);
    ContaCaratteri(str);
    return 0;
}