#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 150

int main()
{
    int n, broj, i, niz[MAX] = { 0 }, max = 0, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &broj);
        while (broj < 0 || broj>150)
        {
            scanf("%d", &broj);
        }
        niz[broj]++;
        if (broj > max)
        {
            max = broj;
        }
    }
    for (i = 0; i <= max; i++)                                     
    {
        printf("%d: ", i);
        for (j = 0; j < niz[i]*100/n; j++)
        {
            printf("x");
        }
        printf("\n");
    }
    return 0;
}