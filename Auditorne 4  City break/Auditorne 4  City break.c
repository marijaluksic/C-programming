#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000
int main()
{
    int kolikokg;
    int kolikostvari;
    int tezina[MAX] = { 0 };
    int vrijednost[MAX] = { 0 };
    int i = 0;
    int maxvrijednost = 0;
    int kilaza = 0;
    int tempkilaza = 0;
    int indexmaxvrijednost = 0;
    int j = 0;
    int ukupno = 0;
    int ukupnavrijednost = 0;
    scanf("%d %d", &kolikokg, &kolikostvari);
    for (i = 0; i < kolikostvari; i++)
    {
        scanf("%d %d", &tezina[i], &vrijednost[i]);
    }
    while (j < kolikostvari)
    {
        for (i = 0; i < kolikostvari; i++)
        {
            tempkilaza = tezina[i] + ukupno;
            if (vrijednost[i] >= maxvrijednost && tempkilaza <= kolikokg)
            {
                maxvrijednost = vrijednost[i];
                indexmaxvrijednost = i;
                kilaza = tezina[i];
            }
        }
        ukupno += kilaza;
        ukupnavrijednost += maxvrijednost;
        for (i = indexmaxvrijednost; i < kolikostvari; i++)
        {
            vrijednost[i] = vrijednost[i + 1];
            tezina[i] = tezina[i + 1];
        }
        kolikostvari--;
        maxvrijednost = 0;
    }
    printf("%d\n", ukupnavrijednost);
    return 0;
}