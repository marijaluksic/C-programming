#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

float racunanjekoeficijenta(char** tlocrt, int n, int m, int minimalnapovrsina)
{
    float koeficijent = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %c", &tlocrt[i][j]);
        }
    }
    return koeficijent;
}

int main()
{
    int n, m, minimalnapovrsina, i, j;
    char **tlocrt;
    float ispis = 0;
    scanf("%d %d %d", &n, &m, &minimalnapovrsina);
    tlocrt = (char**)calloc(n, sizeof(char*));
    for (i = 0; i < n; i++)
    {
        tlocrt[i] = (char*)calloc(m, sizeof(char));
    }
    ispis = racunanjekoeficijenta(tlocrt, n, m, minimalnapovrsina);
    printf("%.2f\n", ispis);
    for (i = 0; i < n; i++)
    {
        free(tlocrt[i]);
    }
    free(tlocrt);
    return 0;
}