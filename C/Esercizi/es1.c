#include <stdio.h>

int main(void)
{
    int x, y;
    int somma, prodotto;
    float media;

    printf("inserisci due numeri: \n");
    scanf("%d %d", &x, &y);

    somma = x + y;
    prodotto = x * y;
    media = (x + y)/2.0;

    printf("Somma: %d, Prodotto: %d, Media: %f\n", somma, prodotto, media);

    return 0;
}