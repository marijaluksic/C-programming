#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void ispisi(char** ploca, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c", ploca[i][j]);
        }
        printf("\n");
    }
    return;
}

void upisi(char** ploca, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i < 2)
            {
                ploca[i][j] = 'C';
            }
            else if (i >= n - 2)
            {
                ploca[i][j] = 'B';
            }
            else
            {
                if (j+i == 0 || (j+i) % 2 == 0)
                {
                    ploca[i][j] = 'O';
                }
                else
                {
                    ploca[i][j] = 'X';
                }
            }
        }
    }
    return;
}

int main()
{
    int n, m, i;
    char **ploca;
    scanf("%d %d", &n, &m);
    ploca = (char**)calloc(n, sizeof(char*));
    for (i = 0; i < n; i++)
    {
        ploca[i] = (char*)calloc(m, sizeof(char));
    }
    upisi(ploca, n, m);
    ispisi(ploca, n, m);
    for (i = 0; i < n; i++)
    {
        free(ploca[i]);
    }
    free(ploca);
    return 0;
}