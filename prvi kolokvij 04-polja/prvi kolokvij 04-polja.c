#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main()
{
    int n, i, niz[MAX] = { 0 }, min, j = 0, index = 0, poredak[MAX] = { 0 };
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        niz[i] = rand() % MAX + 1;
    }
    printf("ORIGINALNI NIZ:\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d", niz[i]);
    }
    printf("\n");
    printf("PROMIJENJENI NIZ:\n");
    while (j < n)
    {
        min = 1000000;
        index = 0;
        for (i = 0; i < n-j; i++)
        {
            if (niz[i] < min)
            {
                min = niz[i];
                index = i;
            }
        }
        poredak[j] = min;
        for (i = index; i < n-1-j; i++)
        {
            niz[i] = niz[i + 1];
        }
        j++;
    }
    for (i = 0; i < n; i++)
    {
        printf(" %d", poredak[i]);
    }
    printf("\n");
    return 0;
}