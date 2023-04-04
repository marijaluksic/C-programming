#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main()
{
    int minvisina, maxvisina, mintezina, maxtezina, mingodina, maxgodina, brojpartnera;
    int partneri = 0;
    int visine[MAX] = { 0 };
    int tezine[MAX] = { 0 };
    int godine[MAX] = { 0 };
    int i = 0;
    scanf("%d %d", &minvisina, &maxvisina);
    while (maxvisina - minvisina > 35 || maxvisina <= 50 || minvisina <= 50 || maxvisina>250 || minvisina>250)
    {
        printf("Nepravilni unos visine!\n");
        scanf("%d %d", &minvisina, &maxvisina);
    }
    scanf("%d %d", &mintezina, &maxtezina);
    while (maxtezina - mintezina <= 5 || maxtezina < 50 || mintezina < 50 || maxtezina > 100 || mintezina>100)
    {
        printf("Nepravilni unos tezine!\n");
        scanf("%d %d", &mintezina, &maxtezina);
    }
    scanf("%d %d", &mingodina, &maxgodina);
    while (maxgodina - mingodina != 5 || maxgodina <= 15 || mingodina <= 15 || maxgodina >= 100 || mingodina >= 100)
    {
        printf("Nepravilni unos godina!\n");
        scanf("%d %d", &mingodina, &maxgodina);
    }
    scanf("%d", &brojpartnera);
    while (brojpartnera <= 3 || brojpartnera > 20)
    {
        printf("Nepravilni unos broja partnera!\n");
        scanf("%d", &brojpartnera);
    }
    for (i = 0; i < brojpartnera; i++)
    {
        scanf("%d %d %d", &visine[i], &tezine[i], &godine[i]);
        if (visine[i] <= maxvisina && visine[i] >= minvisina)
        {
            if (tezine[i] <= maxtezina && tezine[i] >= mintezina)
            {
                if (godine[i] <= maxgodina && godine[i] >= mingodina)
                {
                    partneri++;
                }
            }
        }
    }
    if (partneri <= 1)
    {
        printf("Prolazi kriterije: %d osoba.", partneri);
    }
    else
    {
        printf("Prolazi kriterije: %d osobe.", partneri);
    }
    return 0;
}