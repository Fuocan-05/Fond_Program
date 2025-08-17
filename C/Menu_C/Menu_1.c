#include <stdio.h>

int main(void)
{
    
    int Scelta = 0;
    int Opzione1 = 1;
    int Opzione2 = 2;
    int OpzioneA = 1;
    int OpzioneB = 2;

    printf("sleziona l'opzione desiderata: \n [1] Opzione 1 \n [2] Opzione 2 \n La tua scelta: ");
    scanf("%d", &Scelta);

    //Sarebbe più comodo con uno Switch ed i vari case, ma non mi va di usarlo perché preferisco incatenare gli if

    if (Scelta == Opzione1) 
    {
        printf("Hai scelto l'opzione 1\n");
        printf("Ora scegli tra: \n [1] Opzione A \n [2] Opzione B \n La tua scelta: ");
        scanf("%d", &Scelta);

        if (Scelta == OpzioneA) 
        {
            printf("Hai scelto l'opzione A");
        }
        else if (Scelta == OpzioneB) 
        {
            printf("Hai scelto l'opzione B");
        }
        else
        {
            printf("Scelta non valida");
        }

    }
    else if (Scelta == Opzione2) 
    {
        printf("Hai scelto l'opzione 2");
        printf("Ora scegli tra: \n [1] Opzione A \n [2] Opzione B \n La tua scelta: ");
        scanf("%d", &Scelta);

        if (Scelta == OpzioneA) 
        {
            printf("Hai scelto l'opzione A");
        }
        else if (Scelta == OpzioneB) 
        {
            printf("Hai scelto l'opzione B");
        }
        else
        {
            printf("Scelta non valida");
        }
    }
    else
    {
        printf("Scelta non valida");
    }

    return 0;
}