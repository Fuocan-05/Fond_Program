#include <stdio.h>

int MaggioreDiZero(int A[], int n, int k)
{
    for (int i=0; i<n; i++)
    {
        if (A[i] > 0)
        {
            A[i] = A[i] * k;
            printf("%d\n", A[i]);
        }else if(A[i] <= 0)
        {
            printf("%d\n", A[i]);
        }else
        {
            printf("Errore: i non è maggiore di 0\n");
            break;
        }
    }
    
    return 0;
}

int main(void)
{
    int n = 5;
    int k;
    printf("Inserisci il valore di k: \n");
    scanf("%d", &k);

    int A[n];
    printf("Array A:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("...\n\n");
    MaggioreDiZero(A, n, k);
    
    return 0;
}