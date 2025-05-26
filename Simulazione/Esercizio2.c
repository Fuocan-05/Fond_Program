#include <stdio.h>

int main(void)
{
    int n;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);

    int A[n];

    for (int i = 0; i < n; i++)
    {
        printf("Inserisci il valore di %d: \n", i + 1);
        scanf("%d", &A[i]);
    }

    int doppio = 0;
    
    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if (A[i] == A[j])
            {
                doppio ++;
            }
        }
    }

    printf("Il numero di coppie e': %d\n", doppio);
    

    return 0;
}