#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 15
int main()
{
    int redak = 0;
    int stupac = 0;
    int i, j;
    int polje[MAX][MAX] = { 0 };
    float vrijeme[MAX][MAX] = { 0.0 };
    int pobjeda[2] = { 0 };
    int izgubio[2] = { 0 };
    int nerjeseno = 0;
    scanf("%d %d", &redak, &stupac);
    for (i = 0; i < redak; i++)
    {
        for (j = 0; j < stupac; j++)
        {
            scanf("%d", &polje[i][j]);
        }

    }
    i = 0;
    while (i < stupac)
    {
        if (polje[0][i] == polje[2][i])
        {
            nerjeseno++;
            printf("nerjeseno (ista pocetna visina)\n");
        }
        else
        {

            if (polje[0][i] < polje[2][i])
            {
                vrijeme[0][i] = (float)polje[1][i] * 1.5;
                vrijeme[1][i] = (float)polje[1][i] * 0.5;
            }
            if (polje[0][i] > polje[2][i])
            {
                vrijeme[0][i] = (float)polje[1][i] * 0.5;
                vrijeme[1][i] = (float)polje[1][i] * 1.5;
            }
            printf("VRIJEME SJEVERNI: %f    VRIJEME JUZNI: %f\n", vrijeme[0][i], vrijeme[1][i]);
            if (vrijeme[0][i] < vrijeme[1][i])
            {
                pobjeda[0]++;
                izgubio[1]++;
                printf("pobjedio sjeverni\n");
            }
            if (vrijeme[0][i] > vrijeme[1][i])
            {
                pobjeda[1]++;
                izgubio[0]++;
                printf("pobjedio juzni\n");
            }
            if (vrijeme[0][i] == vrijeme[1][i])
            {
                nerjeseno++;
                printf("nerjeseno\n");
            }
        }
        i++;
    }
    if (pobjeda[0] >= pobjeda[1])
    {
        printf("S: %d-%d-%d\n", pobjeda[0], nerjeseno, izgubio[0]);
    }
    if (pobjeda[1] >= pobjeda[0])
    {
        printf("J: %d-%d-%d\n", pobjeda[1], nerjeseno, izgubio[1]);
    }    
    return 0;
}