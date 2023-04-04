#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ispisi(char** polje, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c", polje[i][j]);
        }
        printf("\n");
    }
    return;
}

void upisi(char** polje, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == 0 || i % 2 == 0)
            {
                if (j == 0 || j % 2 == 0)
                {
                    polje[i][j] = 'O';
                }
                else
                {
                    if (i < 2)
                    {
                        polje[i][j] = 'C';
                    }
                    else if (i >= n - 2)
                    {
                        polje[i][j] = 'B';
                    }
                    else
                    {
                        polje[i][j] = 'X';
                    }
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    if (i < 2)
                    {
                        polje[i][j] = 'C';
                    }
                    else if (i >= n - 2)
                    {
                        polje[i][j] = 'B';
                    }
                    else
                    {
                        polje[i][j] = 'X';
                    }
                }
                else
                {
                    polje[i][j] = 'O';
                }
            }
        }
    }
    return;
}

int main()
{
    int i, n, m;
    char** polje;
    scanf("%d %d", &n, &m);
    polje = (char**)calloc(n, sizeof(char*));
    for (i = 0; i < n; i++)
    {
        polje[i] = (char*)calloc(m, sizeof(char));
    }
    upisi(polje, n, m);
    ispisi(polje, n, m);
    for (i = 0; i < n; i++)
    {
        free(polje[i]);
    }
    free(polje);
    return 0;
}