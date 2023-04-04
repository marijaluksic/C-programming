#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int main()
{
    char podrum[MAX][MAX] = { '0' };
    int brojocitanja = 0;
    int k, l, m, x= 0 , y = 0, s = 0, i = 0, j = 0, z = 0;
    int redak = 0;
    int stupac = 0;
    int maxredak = 0;
    int maxstupac = 0;
    scanf("%d", &brojocitanja);
    for (k= 0; k < brojocitanja; k++)
    {
        scanf("%d %d %d %d %d %d", &x, &y, &s, &i, &j, &z);
        redak = y + j + 1;
        stupac = x + i + 1;
        if (redak >= maxredak)
        {
            maxredak = redak;
        }
        if (stupac >= maxstupac)
        {
            maxstupac = stupac;
        }
        for (l = (y - 1 - s); l < (y+j); l++)
        {
            for (m = (x - 1 - z); m < (x + i); m++)
            {
                //printf("[%d] [%d]\n", l, m);
                podrum[l][m] = '.';
                //printf("%c", podrum[l][m]);
            }
            //printf("\n");
        }
    }
    for (k = 0; k < maxredak; k++)
    {
        for (l = 0; l < maxstupac; l++)
        {
            if (podrum[k][l] != '.')
            {
                podrum[k][l] = '#';
            }
            printf("%c", podrum[k][l]);
        }
        printf("\n");
    }
    return 0;
}