#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

int main()
{
    int matrica1[MAX][MAX] = { 0 };
    int matrica2[MAX][MAX] = { 0 };
    int m1 = 0;
    int n1 = 0;
    int m2 = 0;
    int n2 = 0;
    char x1 = '0';
    char x2 = '0';
    int i = 0, j = 0, k = 0;
    int sjeb = 0;
    scanf("%d %c%d", &m1, &x1, &n1);
    if (m1 < 2 || m1 > 9 || n1 < 2 || n1 > 9)
    {
        sjeb++;
    }    if (sjeb != 0)
    {
        printf("Unesena je nedozvoljena dimenzija prve matrice!\n");
        scanf("%d %c%d", &m1, &x1, &n1);
    }
    sjeb = 0;
    scanf("%d %c%d", &m2, &x2, &n2);
    if (m2 < 2 || m2 > 9 || n2 < 2 || n2 > 9)
    {
        sjeb++;
    }
    if (sjeb != 0)
    {
        printf("Unesena je nedozvoljena dimenzija druge matrice!\n");
        scanf("%d %c%d", &m2, &x2, &n2);
    }
    sjeb = 0;
    if (n1 != m2)
    {
        printf("Matrice nisu ulancane!\n");
        scanf("%d %c%d", &m2, &x2, &n2);
    }
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            scanf("%d", &matrica1[i][j]);
        }
    }
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            scanf("%d", &matrica2[i][j]);
        }
    }
    if (m1 != m2 && n1 != n2)
    {
        printf("Matrice nisu istih dimenzija, ne mogu se zbrojiti!\n");
        printf("Matrice nisu istih dimenzija, ne mogu se oduzimati!\n");
    }
    else if (m1 == m2 && n1 == n2)
    {
        printf("Suma matrica:\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                printf(" %d", matrica1[i][j] + matrica2[i][j]);
            }
            printf("\n");
        }
        printf("Razlika matrica:\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                printf(" %d", matrica1[i][j] - matrica2[i][j]);
            }
            printf("\n");
        }
    }
    printf("Transponirana prva matrica:\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            printf(" %d", matrica1[j][i]);
        }
        printf("\n");
    }
    printf("Transponirana druga matrica:\n");
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < m2; j++)
        {
            printf(" %d", matrica2[j][i]);
        }
        printf("\n");
    }
    printf("Umnozak matrica:\n");
    i = 0;
    j = 0;
    while (k < m1)
    {

        while (i < n2)
        {
            sjeb = 0;
            for (j = 0; j < m2; j++)
            {
                sjeb += matrica1[k][j] * matrica2[j][i];
            }
            printf(" %d", sjeb);
            i++;
        }
        printf("\n");
        k++;
        i = 0;
    }
    //printf("%d %d\n", m1, n1);
    //printf("%d %d\n", m2, n2);
    return 0;
}