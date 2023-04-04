#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int matrica[3][3] = { 0 };
    int brojac = 0;
    int i, j, unos;
    int redak = 0;
    int brojacredak[3] = { 3, 3, 3 };
    while (1)
    {
        scanf("%d", &unos);
        while (unos < 1 || unos > 3)
        {
            printf("Ponovi unos!\n");
            scanf("%d", &unos);
        }
        switch (unos)
        {
        case 1:
            brojacredak[0]--;
            redak = brojacredak[0];
            matrica[redak][0] = 1;
            break;
        case 2:
            brojacredak[1]--;
            redak = brojacredak[1];
            matrica[redak][1] = 1;
            break;
        case 3:
            brojacredak[2]--;
            redak = brojacredak[2];
            matrica[redak][2] = 1;
            break;
        }
        brojac++;
        printf("Nakon %d. kruga:\n", brojac);
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d", matrica[i][j]);
            }
            printf("\n");
        }
        if (brojacredak[0] <= 0 || brojacredak[1] <= 0 || brojacredak[2] <= 0)
        {
            break;
        }
    }
    printf("Prekid igre.\n");
    return 0;
}