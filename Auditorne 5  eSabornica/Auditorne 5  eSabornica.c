#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 600
int main()
{
    int m, n, s, i, j, k;
    int bio[MAX] = { 0 };
    char stolac[MAX][MAX] = { 0 };
    char koltriga[MAX] = { 0 };
    char ukoriti[MAX][MAX] = { 0 };
    int brojzastupnika = 0;
    scanf("%d %d", &m, &n);
    scanf("%d", &s);
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < (m * n) * 2 - 1; j++)
        {
            scanf(" %c", &stolac[i][j]);
            if (stolac[i][j] != ',')
            {
                if (stolac[i][j] == '1' && bio[j] == 0)
                {
                    if (j == 0)
                    {
                        brojzastupnika = 0;
                    }
                    else 
                    {
                        brojzastupnika = j / 2;
                    }
                    koltriga[brojzastupnika] = '0';
                    bio[j]++;;
                }
                if (stolac[i][j] == '0' && bio[j] == 0)
                {
                    if (j == 0)
                    {
                        brojzastupnika = 0;
                    }
                    else
                    {
                        brojzastupnika = j / 2;
                    }
                    koltriga[brojzastupnika] = '-';
                }
            }
        }
    }
    j = 0;
    k = 0;
    for (i = 0; i < (m * n); i++)
    {
        if (j < m)
        {
            if (k < n)
            {
                ukoriti[j][k] = koltriga[i];
                k++;
                if (k == n)
                {
                    j++;
                    k = 0;
                }
            }
        }
    }
    for (i=0; i<m;i++)
    {
        for(j = 0; j < n; j++)
        {
            printf(" %c", ukoriti[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (ukoriti[i][j] == '-')
            {
                printf("Ukoriti (%d, %d).\n", i + 1, j + 1);
            }
        }
    }
    return 0;
}
