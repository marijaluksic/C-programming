#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
char** trim(char mat[6][6], int* rezN, int* rezM)
{
    int i, j, brojac = -1, imin = 7, imax = -1, jmin = 7, jmax = -1, k = 0, l = 0;
    char n[6] = { 0 }, m[6] = { 0 };
    char** polje = NULL;
    for (i = 0; i < *rezN; i++)
    {
        brojac = -1;
        for (j = 0; j < *rezM; j++)
        {
            if (mat[i][j] != '.')
            {
                brojac++;
            }
        }
        if (brojac >= 0)
        {

            if (i < imin)
            {
                imin = i;
            }
            if (i > imax)
            {
                imax = i;
            }
        }
    }
    imax += 1;
    for (i = 0; i < *rezN; i++)
    {
        brojac = -1;
        for (j = 0; j < *rezM; j++)
        {
            if (mat[j][i] != '.')
            {
                brojac++;
            }
        }
        if (brojac >= 0)
        {
            if (i < jmin)
            {
                jmin = i;
            }
            if (i > jmax)
            {
                jmax = i;
            }
        }
    }
    jmax += 1;
    polje = (char**)calloc(imax - imin, sizeof(char*));
    for (i = 0; i < imax - imin; i++)
    {
        polje[i] = (char*)calloc(jmax - jmin, sizeof(char));
    }
    for (i = imin; i < imax; i++)
    {
        for (j = jmin; j < jmax; j++)
        {
            polje[k][l] = mat[i][j];
            l++;
        }
        k++;
        l = 0;
    }
    *rezN = imax - imin;
    *rezM = jmax - jmin;
    return polje;
}
char** rotate90(char** predmet, int n, int m)
{
    int i, j, k=0;
    char** predmetic;
    predmetic = (char**)calloc(m, sizeof(char*));
    for (i = 0; i < m; i++)
    {
        predmetic[i] = (char*)calloc(n, sizeof(char));
    }
    for (i = 0; i < n; i++)
    {
        for (j = m-1; j >=0; j--)
        {
            if (predmet[i][j] == '-')
            {
                predmet[i][j] = '|' ;
            }
            else if (predmet[i][j] == '|')
            {
                predmet[i][j] = '-';
            }
            predmetic[k][i] = predmet[i][j];
            k++;
        }
        k = 0;
    }
    //for (i = 0; i < m; i++)
    //{
    //    for (j = 0; j < n; j++)
    //    {
    //        printf("%c",predmetic[i][j]);
    //    }
    //    printf("\n");
    //}
    return predmetic;
}
int main()
{
    int n, m, i, j, k, pazise, x, y;
    char unos[MAX][MAX] = { {0}, {0} }, cegasepazi[6][6] = { {0}, {0} };
    char** polje;
    char** predmet;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %c", &unos[i][j]);
        }
    }
    scanf("%d", &pazise);
    for (k = 0; k < pazise; k++)
    {
        x = 6;
        y = 6;
        for (i = 0; i < x; i++)
        {
            for (j = 0; j < y; j++)
            {
                scanf(" %c", &cegasepazi[i][j]);
            }
        }
        printf("\n");
        polje= trim(cegasepazi, &x, &y);
        /*for (i = 0; i < x; i++)
        {
            for (j = 0; j < y; j++)
            {
                printf("%c", polje[i][j]);
            }
            printf("\n");
        }*/
        predmet = rotate90(polje, x, y);
        for (i = 0; i < y; i++)
        {
            for (j = 0; j < x; j++)
            {
                printf("%c", predmet[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}