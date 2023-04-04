#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main()
{
    int brojcarapa;
    int kolikocarapa;
    int pocetnacarapa;
    int i = 0;
    int nizcarapa[MAX] = { 0 };
    int zbrojznamenki = 0;
    int brojdjelitelja = 0;
    int znamenka = 0;
    int j = 0;
    int konacanbroj = 0;
    int konacanniz[MAX] = { 0 };
    int prva = 0;
    int druga = 0;
    scanf("%d", &brojcarapa);
    while (brojcarapa <= 5 || brojcarapa > 100)
    {
        printf("Neispravni unos parametra N.\n");
        scanf("%d", &brojcarapa);
    }
    scanf("%d", &kolikocarapa);
    while (kolikocarapa < 2 || kolikocarapa > brojcarapa)
    {
        printf("Neispravni unos parametra K.\n");
        scanf("%d", &kolikocarapa);
    }
    scanf("%d", &pocetnacarapa);
    //printf("MOGUCI NIZ: ");
    //for (i = 0; i < brojcarapa; i++)
    //{
    //    nizcarapa[i] = i+1;
    //    printf("%d ", nizcarapa[i]);
    //}
    //printf("\n");
    for (i = pocetnacarapa; i <= brojcarapa; i++)
    {
        if (i > 3)
        {
            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    brojdjelitelja++;
                }
            }
        }
        //printf("%d ZBROJ ZNAMENKI: %d      BROJ DJELITELJA: %d\n", i, zbrojznamenki, brojdjelitelja);
        if (zbrojznamenki + brojdjelitelja <= i && konacanbroj<kolikocarapa)
        {
            //printf("USAO U PETLJU\n");
            //printf("%d <= %d\n", zbrojznamenki + brojdjelitelja, i);
            if (i < 10)
            {
                zbrojznamenki += i;
            }
            else
            {
                prva = i / 10;
                //printf("PRVA ZNAMENKA: %d\n", prva);
                druga = i % 10;
                //printf("DRUGA ZNAMENKA: %d\n", druga);
                zbrojznamenki += prva + druga;
            }
            konacanniz[konacanbroj] = i;
            konacanbroj++;
        }
        //else
        //{
        //    printf("%d >= %d\n", zbrojznamenki + brojdjelitelja, i);
        //}
        brojdjelitelja = 0;
    }
    if (konacanbroj > 1)
    {
        printf("Uzet ce carape broj %d", konacanniz[0]);
        for (i = 1; i < konacanbroj; i++)
        {
            printf(", %d", konacanniz[i]);
        }
    }
    else
    {
        printf("Uzet ce carape broj %d", konacanniz[0]);
    }
    printf(".\n");
    return 0;
}