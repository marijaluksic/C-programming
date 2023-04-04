#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char glas;
    int kandidatT = 0;
    int kandidatB = 0;
    int minuta = 1;
    int vrijeme = 0;
    int brojacpauza = 0;
    int pauza = 1;
    int provjeradjeljivostiB5 = 0;
    int provjeradjeljivostiB7 = 0;
    int provjeradjeljivostiB13 = 0;
    int provjeradjeljivostT5 = 0;
    int provjeradjeljivostT7 = 0;
    int provjeradjeljivostT13 = 0;
    int vrijemepauze = 0;
    int prethodnapauza = 0;
    do
    {
        scanf(" %c", &glas);
        if (vrijeme - vrijemepauze >= 10)
        {
            minuta = 2;
            prethodnapauza = brojacpauza;
            //printf("MINUTA = 2\n");
        }
        if (glas == 'x')
        {
            break;
        }

        if (glas == 'T')
        {
            kandidatT++;
            vrijeme += minuta;

        }
        else if (glas == 'B')
        {
            kandidatB++;
            vrijeme += minuta;
        }
        provjeradjeljivostiB5 = kandidatB % 5;
        provjeradjeljivostT5 = kandidatT % 5;
        provjeradjeljivostiB7 = kandidatB % 7;
        provjeradjeljivostT7 = kandidatT % 7;
        provjeradjeljivostiB13 = kandidatB % 13;
        provjeradjeljivostT13 = kandidatT % 13;
        if ((provjeradjeljivostiB5 == 0 || provjeradjeljivostiB7 == 0 || provjeradjeljivostiB13 == 0 || kandidatB==0) && (provjeradjeljivostT5 == 0 || provjeradjeljivostT7 == 0 || provjeradjeljivostT13 == 0 || kandidatT == 0))
        {
            vrijeme += pauza;
            pauza++;
            brojacpauza++;
            vrijemepauze = vrijeme;
            minuta = 1;
        }
        //printf("VRIJEME: %d KANDIDAT T: %d KANDIDAT B: %d UKUPNO GLASOVA: %d\n", vrijeme, kandidatT, kandidatB, kandidatB + kandidatT);
        //printf("PAUZA: %d BROJAC PAUZA %d\n", pauza, brojacpauza);

    } while (glas != 'x');
    if (kandidatB > kandidatT)
    {
        printf("Pobjednik: B\n");
        printf("Broj glasova %d naspram %d.\n", kandidatB, kandidatT);
        printf("Brojanje je trajalo %dmin.\n", vrijeme);
    }
    else if (kandidatT > kandidatB)
    {
        printf("Pobjednik: T\n");
        printf("Broj glasova %d naspram %d.\n", kandidatT, kandidatB);
        printf("Brojanje je trajalo %dmin.\n", vrijeme);
    }
    return 0;
}