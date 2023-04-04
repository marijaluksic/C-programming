#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 150

void provjeraRedoslijeda(int*, int*);
int sumaZnamenki(int, int);
int sumaDjelitelja(int, int);
int provjercica(int, int);

void finalniRedoslijed(int papir[MAX], int brojutakmica)
{
    //printf("USAO U ZADNJU PETLJU\n");
    int i, k = 0, j, l = 0, max = 0;
    j = brojutakmica;
    //printf("k= %d brojutakmica = %d papir = %lld\n", k, brojutakmica, papir[0]);
    while (k < brojutakmica)
    {
        max = 0;
        for (i = 0; i < j; i++)
        {
            if (papir[i] >= max)
            {
                max = papir[i];
                l = i;
            }
        }
        //printf("NAJVECI BROJ: %lld\n", max);
        for (i = l; i < j - 1; i++)
        {
            papir[i] = papir[i + 1];
        }
        if (k == 0)
        {
            printf("%d", max);
        }
        else if (k != 0)
        {
            printf(", %d", max);
        }
        j--;
        k++;
    }
    return;
}

int main()
{
    int brojutakmica, i, a, b, zbrojznamenki = 0, zbrojdjelitelja = 0, papir[MAX] = { 0 };
    scanf("%d", &brojutakmica);
    for (i = 0; i < brojutakmica; i++)
    {
        scanf("%d %d", &a, &b);
        provjeraRedoslijeda(&a, &b);
        zbrojznamenki = sumaZnamenki(a, b);
        zbrojdjelitelja = sumaDjelitelja(a, b);
        papir[i] = provjercica(zbrojznamenki, zbrojdjelitelja);
    }
    //printf("brojutakmica u main funkciji %d\n", brojutakmica);
    finalniRedoslijed(papir, brojutakmica);
    return 0;
}

void provjeraRedoslijeda(int* pa, int* pb)
{
    int tempa;
    if (*pb < *pa)
    {
        tempa = *pa;
        *pa = *pb;
        *pb = tempa;
    }
}

int sumaZnamenki(int a, int b)
{
    int i, zbroj = 0, tempbroj;
    for (i = a; i <= b; i++)
    {
        tempbroj = i;
        if (tempbroj > 999999)
        {
            zbroj += tempbroj / 1000000;
            tempbroj = tempbroj % 1000000;
        }
        if (tempbroj > 99999)
        {
            zbroj += tempbroj / 100000;
            tempbroj = tempbroj % 100000;
        }
        if (tempbroj > 9999)
        {
            zbroj += tempbroj / 10000;
            tempbroj = tempbroj % 10000;
        }
        if (tempbroj > 999)
        {
            zbroj += tempbroj / 1000;
            tempbroj = tempbroj % 1000;
        }
        if (tempbroj > 99)
        {
            zbroj += tempbroj / 100;
            tempbroj = tempbroj % 100;
        }
        if (tempbroj > 9)
        {
            zbroj += tempbroj / 10;
            tempbroj = tempbroj % 10;
        }
        if (tempbroj < 10)
        {
            zbroj += tempbroj;
        }
    }
    //printf("ZBROJ SVIH ZNAMENKI %lld\n", zbroj);
    return zbroj;
}

int sumaDjelitelja(int a, int b)
{
    int i, zbrojcek = 0, tempbroj;
    while (a <= b)
    {
        for (i = 2; i < a; i++)
        {
            tempbroj = a % i;
            if (tempbroj == 0)
            {
                zbrojcek++;
                //printf("%lld je djelitelj %lld\n", i, a);
            }
        }
        //printf("%lld suma djelitelja\n", zbrojcek);
        a++;
    }
    return zbrojcek;
}

int provjercica(int zbrojznamenki, int zbrojdjelitelja)
{
    int rezultat = 0;
    if (zbrojdjelitelja == 0)
    {
        rezultat = 0;
    }
    else
    {
        rezultat = zbrojznamenki % zbrojdjelitelja;
    }
    //printf("%lld % OPERACIJA\n", rezultat);
    return rezultat;
}