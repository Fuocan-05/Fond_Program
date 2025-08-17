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

int Doppio(int n, int A[n])
{
    int doppio = 0;
    
    for (int i = 0; i < n; i++)
    {
        for( int j = i + 1; j < n; j++)
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

    printf("Ecco l'array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }

    int k;
    int attivo = 0;
    int scelta = 0;
    
    while(attivo == 0)
    {
        printf("cosa vuoi fare?\n");
        printf("1. Maggiore di zero\n");
        printf("2. Doppio\n");
        printf("3. Cambia un valore\n");
        printf("4. Uscire\n");
        scanf("%d", &scelta);
        if(scelta == 1)
        {
            printf("Inserisci il valore di k: \n");
            scanf("%d", &k);
            MaggioreDiZero(A, n, k);
        }
        else if(scelta == 2)
        {
            Doppio(n, A);
        }
        else if(scelta == 3)
        {
            int i, val;
            printf("inserisci la posizione da cambiare: \n");
            scanf("%d", &i);
            if (i = n)
            {
                i = i - 1;
            }
            else if (i > n || i < 0)
            {
                printf("Errore : la posizione non è valida\n");
                continue;
            }
            printf("inserisci il nuovo valore: \n");
            scanf("%d", &val);
            A[i] = val;
            printf("Ecco l'array modificato: \n");
            for (int i; i < n; i++)
            {
                printf("%d\n", A[i]);
            }
        }
        else if(scelta == 4)
        {
            attivo = 1;
            printf("Uscita...\n");
        }
        else
        {
            printf("Scelta non valida, riprova.\n");
        }
    }
    return 0;

}