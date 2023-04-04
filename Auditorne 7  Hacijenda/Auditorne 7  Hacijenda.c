#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int provjera(int zbroj[2][3])
{
    int ima = 0, i;
    for (i = 0; i < 3; i++)
    {
        if (zbroj[0][i] == zbroj[1][i])
        {
            ima++;
        }
    }
    if (ima == 3)
    {
        ima = 1;
    }
    else if (ima < 3)
    {
        ima = 0;
    }
    return ima;
}

int main()
{
    int n, m, i, j, k = 0, zbroj[2][3] = { {0}, {0} }, brojvodpodjela = 0, podjela = 0, indexvod[MAX] = { 0 }, brojokompodjela = 0, indexokom[MAX] = { 0 };
    char unos[MAX][MAX] = { {0}, {0} };
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %c", &unos[i][j]);
        }
    }
    while (k < n-1)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (k >= i)
                {
                    if (unos[i][j] == 'M')
                    {
                        zbroj[0][0]++;
                    }
                    if (unos[i][j] == 'P')
                    {
                        zbroj[0][1]++;
                    }
                    if (unos[i][j] == 'G')
                    {
                        zbroj[0][2]++;
                    }
                }
                else
                {
                    if (unos[i][j] == 'M')
                    {
                        zbroj[1][0]++;
                    }
                    if (unos[i][j] == 'P')
                    {
                        zbroj[1][1]++;
                    }
                    if (unos[i][j] == 'G')
                    {
                        zbroj[1][2]++;
                    }
                }
            }
        }
        podjela = provjera(zbroj);
        if (podjela == 1)
        {
            indexvod[brojvodpodjela] = k+1;
            brojvodpodjela++;
        }
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
                zbroj[i][j] = 0;
            }
        }
        k++;
    }
    k = 0;
    while (k < m - 1)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (k >= i)
                {
                    if (unos[j][i] == 'M')
                    {
                        zbroj[0][0]++;
                    }
                    if (unos[j][i] == 'P')
                    {
                        zbroj[0][1]++;
                    }
                    if (unos[j][i] == 'G')
                    {
                        zbroj[0][2]++;
                    }
                }
                else
                {
                    if (unos[j][i] == 'M')
                    {
                        zbroj[1][0]++;
                    }
                    if (unos[j][i] == 'P')
                    {
                        zbroj[1][1]++;
                    }
                    if (unos[j][i] == 'G')
                    {
                        zbroj[1][2]++;
                    }
                }
            }
        }
        podjela = provjera(zbroj);
        if (podjela == 1)
        {
            indexokom[brojokompodjela] = k + 1;
            brojokompodjela++;
        }
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
                zbroj[i][j] = 0;
            }
        }
        k++;
    }
    if (brojvodpodjela + brojokompodjela == 0)
    {
        printf("Nemoguce podijeliti 50-50.\n");
    }
    else
    {
        printf("Broj mogucih podjela: %d\n", brojvodpodjela + brojokompodjela);
        for (i = 0; i < brojvodpodjela + brojokompodjela; i++)
        {
            printf("%d. ", i + 1);
            if (i < brojvodpodjela && brojvodpodjela != 0)
            {
                printf("Vodoravno, izmedju retka br. %d i br. %d\n", indexvod[i], indexvod[i] + 1);
            }
            else
            {
                printf("Okomito, izmedju stupca br. %d i br. %d\n", indexokom[i-brojvodpodjela], indexokom[i-brojvodpodjela] + 1);
            }
        }

    }
    return 0;
}
//da se imanje ipak podijeli 50-50.
//Alejandro i Rico Suave dobili jednak broj maslenika (M), pasnjaka (P) i gradevina (G). Imanje se moze podijeliti samo pravocrtno, 
//okomito ili vodoravno. Potrebno je napraviti funkciju koja za neku predlozenu podjelu vraca informaciju je li podjela korektna ili nije 
//(funkciji je potrebno proslijediti matricu), a u main programu isprobati sve moguce podjele te ispisati, kao konacni rezultat na koliko je 
//nacina moguce podijeliti imanje i gdje je sve moguce povuci granicu. Imanje nece biti vece od 100m u sirinu niti duzinu. Ukoliko je imanje 
//nemoguce ispravno podijeliti, potrebno je ispisati "Nemoguce podijeliti 50-50.".