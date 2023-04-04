#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50
int main()
{
    char polje[MAX][MAX] = { 0 };
    int redak = 0;
    int stupac = 0;
    int i, j, k = 0;
    int brojzamjena = 0;
    char prije = 0;
    char poslije =  0;
    scanf("%d %d", &redak, &stupac);
    for (i = 0; i < redak; i++)
    {
        for (j = 0; j < stupac; j++)
        {
            scanf(" %c", &polje[i][j]);
        }
    }
    scanf("%d", &brojzamjena);
    while (k < brojzamjena)
    {
        scanf(" %c %c", &prije, &poslije);
        for (i = 0; i < redak; i++)
        {
            for (j = 0; j < stupac; j++)
            {
                if (prije == polje[i][j])
                {
                    polje[i][j] = poslije;
                }
            }
        }
        k++;
    }
    for (i = 0; i < redak; i++)
    {
        for (j = 0; j < stupac; j++)
        {
            printf("%c", polje[i][j]);
        }
        printf("\n");
    }
    return 0;
}