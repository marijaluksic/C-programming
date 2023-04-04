#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

int main()
{
    char polje[MAX][MAX];
    int brredaka = 0;
    int brstupaca = 0;
    int xkoordinatax = 0;
    int okoordinatax = 0;
    int xkoordinatay = 0;
    int okoordinatay = 0;
    int max = 1;
    int brojacpobjedex[MAX] = { 0 };
    int brojacpobjedeo[MAX] = { 0 };
    char pobjednik = 0;
    char x;
    int kolikodopobjede = 0;
    char koprvi;
    int i, j, k = 0;
    scanf("%d %c%d", &brredaka, &x, &brstupaca);
    while (brredaka > 10 || brredaka < 3 || brstupaca>10 || brstupaca < 3)
    {
        printf("Nedozvoljena dimenzija polja!\n");
        scanf("%d %c%d", &brredaka, &x, &brstupaca);
    }
    scanf("%d", &kolikodopobjede);
    scanf(" %c", &koprvi);
    for (i = 0; i < brredaka; i++)
    {
        for (j = 0; j < brstupaca; j++)
        {
            polje[i][j] = '-';
            printf(" %c", polje[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    while (k < kolikodopobjede)
    {
        if (koprvi == 'X')
        {
            scanf("%d %d", &xkoordinatax, &xkoordinatay);
            scanf("%d %d", &okoordinatax, &okoordinatay);
            polje[xkoordinatax - 1][xkoordinatay - 1] = 'X';
            polje[okoordinatax - 1][okoordinatay - 1] = 'O';
            brojacpobjedex[xkoordinatay - 1]++;
            brojacpobjedeo[okoordinatay - 1]++;
            if (brojacpobjedex[xkoordinatay - 1] > max)
            {
                max = brojacpobjedex[xkoordinatay - 1];
                pobjednik = 'X';
            }
            if (brojacpobjedeo[okoordinatay - 1] > max)
            {
                max = brojacpobjedeo[okoordinatay - 1];
                pobjednik = 'O';
            }
        }
        if (koprvi == 'O')
        {
            scanf("%d %d", &okoordinatax, &okoordinatay);
            scanf("%d %d", &xkoordinatax, &xkoordinatay);
            polje[okoordinatax - 1][okoordinatay - 1] = 'O';
            polje[xkoordinatax - 1][xkoordinatay - 1] = 'X';
            brojacpobjedex[xkoordinatay - 1]++;
            brojacpobjedeo[okoordinatay - 1]++;
            if (brojacpobjedex[xkoordinatay - 1] > max)
            {
                max = brojacpobjedex[xkoordinatay - 1];
                pobjednik = 'X';
            }
            if (brojacpobjedeo[okoordinatay - 1] > max)
            {
                max = brojacpobjedeo[okoordinatay - 1];
                pobjednik = 'O';
            }
        }
        for (i = 0; i < brredaka; i++)
        {
            for (j = 0; j < brstupaca; j++)
            {
                printf(" %c", polje[i][j]);
            }
            printf("\n");
        }
        k++;
        printf("\n");
    }
    if (max == 1)
    {
        pobjednik = koprvi;
    }
    printf("Pobjednik je igrac %c!\n", pobjednik);
    return 0;
}