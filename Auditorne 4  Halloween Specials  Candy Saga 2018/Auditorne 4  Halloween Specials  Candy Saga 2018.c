#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main()
{
    int ukupanbrojkuca;
    int brojkuca;
    int nizkuca[MAX] = { 0 };
    int i = 0;
    int maxkuca = 0;
    int indexmaxkuca = 0;
    int j = 0;
    int slatkisi = 0;
    scanf("%d %d", &ukupanbrojkuca, &brojkuca);
    for (i = 0; i < ukupanbrojkuca; i++)
    {
        scanf("%d", &nizkuca[i]);
    }
    while (j < brojkuca)
    {
        for (i = 0; i < ukupanbrojkuca; i++)
        {
            if (nizkuca[i] >= maxkuca)
            {
                maxkuca = nizkuca[i];
                indexmaxkuca = i;
            }
        }
        for (i = indexmaxkuca; i < ukupanbrojkuca; i++)
        {
            nizkuca[i] = nizkuca[i + 1];
        }
        ukupanbrojkuca--;
        slatkisi += maxkuca;
        maxkuca = 0;
        j++;
    }
    printf("%d\n", slatkisi);
    return 0;
}