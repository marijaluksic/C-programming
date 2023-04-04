#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 3, m = 4, i, j, mat[3][4] = { 0 }, max = 0, indexmaxi = 0, indexmaxj = 0, min = 20, indexmini = 0, indexminj = 0, zbrojstupac = 0, zbrojredak=0, maxzbrojstupac = 0, maxzbrojredak = 0, indexmaxzbrojstupac = 0, indexmaxzbrojredak = 0, minzbrojstupac = 500, minzbrojredak = 500, indexminzbrojstupac = 0, indexminzbrojredak = 0, element=0, brojacmanjih=0, brojacvecih=0, brojdjeljivih=0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            mat[i][j] = rand()% 20 + 1;
        }
    }
    printf("MATRICA:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    printf("GLAVNA DIJAGONALA:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (j == i)
            {
                printf(" %d", mat[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("SPOREDNA DIJAGONALA:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (j == m-1-i)
            {
                printf(" %d", mat[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("NAJVECI BROJ I NJEGOVA LOKACIJA:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mat[i][j] > max)
            {
                max = mat[i][j];
                indexmaxi = i;
                indexmaxj = j;
            }
        }
    }
    printf("%d[%d][%d]\n", max, indexmaxi, indexmaxj);
    printf("\n");
    printf("NAJMANJI BROJ I NJEGOVA LOKACIJA:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mat[i][j] < min)
            {
                min = mat[i][j];
                indexmini = i;
                indexminj = j;
            }
        }
    }
    printf("%d[%d][%d]\n", min, indexmini, indexminj);
    printf("\n");
    printf("REDAK U KOJEM JE NAJMANJI BROJ:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == indexmini)
            {
                printf(" %d", mat[indexmini][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("REDAK U KOJEM JE NAJVECI BROJ:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == indexmaxi)
            {
                printf(" %d", mat[indexmaxi][j]);;
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("STUPAC U KOJEM JE NAJMANJI BROJ:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (j == indexminj)
            {
                printf(" %d", mat[i][indexminj]);;
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("STUPAC U KOJEM JE NAJVECI BROJ:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (j == indexmaxj)
            {
                printf(" %d", mat[i][indexmaxj]);;
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("STUPAC SA NAJVECIM ZBROJEM:\n");
    j = 0;
    while (j < m)
    {
        zbrojstupac = 0;
        for (i = 0; i < n; i++)
        {
            zbrojstupac+= mat[i][j];
        }
        if (zbrojstupac > maxzbrojstupac)
        {
            maxzbrojstupac = zbrojstupac;
            indexmaxzbrojstupac = j;
        }
        if (zbrojstupac < minzbrojstupac)
        {
            minzbrojstupac = zbrojstupac;
            indexminzbrojstupac = j;
        }
        j++;
    }
    for (i = 0; i < n; i++)
    {
        printf(" %d\n", mat[i][indexmaxzbrojstupac]);
    }
    printf("\n");
    printf("STUPAC SA NAJMANJIM ZBROJEM:\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d\n", mat[i][indexminzbrojstupac]);
    }
    printf("\n");
    printf("REDAK SA NAJVECIM ZBROJEM:\n");
    i = 0;
    while (i < n)
    {
        zbrojredak = 0;
        for (j = 0; j < n; j++)
        {
            zbrojredak += mat[i][j];
        }
        if (zbrojredak > maxzbrojredak)
        {
            maxzbrojredak = zbrojredak;
            indexmaxzbrojredak = i;
        }
        if (zbrojredak < minzbrojredak)
        {
            minzbrojredak = zbrojredak;
            indexminzbrojredak = i;
        }
        i++;
    }
    for (j = 0; j < m; j++)
    {
        printf(" %d", mat[indexmaxzbrojredak][j]);
    }
    printf("\n");
    printf("REDAK SA NAJMANJIM ZBROJEM:\n");
    for (j = 0; j < m; j++)
    {
        printf(" %d", mat[indexminzbrojredak][j]);
    }
    printf("\n");
    printf("Unesite element:\n");
    scanf("%d", &element);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mat[i][j] == element)
            {
                printf("%d[%d][%d]\n", mat[i][j], i, j);
            }
            if (mat[i][j] < element)
            {
                brojacmanjih++;
            }
            if (mat[i][j] > element)
            {
                brojacvecih++;
            }
            if (mat[i][j] % element == 0)
            {
                brojdjeljivih++;
            }
        }
    }
    printf("\n");
    printf("BROJ MANJIH ELEMENATA OD NJEGA U MATRICI: %d\n", brojacmanjih);
    printf("BROJ VECIH ELEMENATA OD NJEGA U MATRICI: %d\n", brojacvecih);
    printf("BROJ ELEMENATA U MATRICI S KOJIMA JE ON DJELJIV: %d\n", brojdjeljivih);
    return 0;
}