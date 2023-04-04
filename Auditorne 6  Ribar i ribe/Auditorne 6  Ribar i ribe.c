#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 300

int optimalnovrijeme(char unos[MAX], int velicinarijeke)
{
    int i, ribica = 0;
    for (i = 0; i < velicinarijeke; i++)
    {
        if (unos[i] != '.')
        {
            ribica += (int)unos[i] - 64;
            i += 2;
        }
    }
    return ribica;
}

int main()
{
    int velicinarijeke, i, k = 0, kolicina = 0, max = 0, trenutak = 0;
    char unos[300] = { 0 };
    scanf("%d", &velicinarijeke);
    for (i = 0; i < velicinarijeke; i++)
    {
        scanf(" %c", &unos[i]);
    }
    //for (i = 0; i < velicinarijeke; i++)
    //{
    //    printf("%c", unos[i]);
    //}
    while (k < velicinarijeke)
    {
        kolicina = optimalnovrijeme(unos, velicinarijeke);
        if (kolicina > max)
        {
            max = kolicina;
            trenutak = k;
        }
        for (i = 0; i < velicinarijeke - 1; i++)
        {
            unos[i]= unos[i+1];
        }
        unos[velicinarijeke - 1] = '.';
        k++;
    }
    printf("Optimalno je baciti udicu nakon %ds, sto donosi %dkg ribe.\n", trenutak * 10, max);
    return 0;
}