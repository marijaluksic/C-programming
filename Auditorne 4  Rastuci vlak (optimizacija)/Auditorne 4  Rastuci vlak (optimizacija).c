#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000

int main()
{
    int brojvagona;
    int rastucivagon[MAX] = { 0 };
    int padajucivagon[MAX] = { 0 };
    int brojpadajucih = 0;
    int brojrastucih = 0;
    int i;
    int j = 0;
    int k = 0;
    int maxvagon = 0;
    int pocetakrastucih = 0;
    int pocetakpadajucih = 0;

    scanf("%d ", &brojvagona);
    for (i = 0; i < brojvagona; i++)
    {
        scanf("%d", &rastucivagon[i]);
    }
    i = 0;
    for (i = (brojvagona - 1); i >= 0; i--)
    {
        padajucivagon[i] = rastucivagon[j];
        j++;
    }
    j = 0;
    while (k<brojvagona)
    {
        for (i = k; i < brojvagona; i++)
        {
            if (rastucivagon[i] > maxvagon)
            {
                maxvagon = rastucivagon[i];
                j++;
            }
        }
        if (j > brojrastucih)
        {
            brojrastucih = j;
            pocetakrastucih = k;
        }
        j = 0;
        maxvagon = 0;
        k++;
    }
    k = 0;
    while (k < brojvagona)
    {
        for (i = k; i < brojvagona; i++)
        {
            if (padajucivagon[i] > maxvagon)
            {
                maxvagon = padajucivagon[i];
                j++;
            }
        }
        if (j > brojpadajucih)
        {
            brojpadajucih = j;
            pocetakpadajucih = k;
        }
        j = 0;
        maxvagon = 0;
        k++;
    }
    if (brojpadajucih == brojrastucih)
    {
        if (rastucivagon[pocetakrastucih] > padajucivagon[brojvagona - pocetakpadajucih-1])
        {
            printf("Ostaje %d vagona: ", brojrastucih);
            for (i = pocetakrastucih; i < brojvagona; i++)
            {
                if (rastucivagon[i] > maxvagon)
                {
                    maxvagon = rastucivagon[i];
                    printf("%d ", rastucivagon[i]);
                }
            }
            printf("\n");
        }
        else if (padajucivagon[brojvagona - pocetakpadajucih-1] >= rastucivagon[pocetakrastucih])
        {
            printf("Ostaje %d vagona: ", brojpadajucih);
            for (i = (brojvagona - pocetakpadajucih-1); i >= 0; i--)
            {
                if (padajucivagon[i] > maxvagon)
                {
                    maxvagon = padajucivagon[i];
                    printf("%d ", padajucivagon[i]);
                }
            }
            printf("\n");
        }
    }
    else if (brojrastucih > brojpadajucih)
    {
        printf("Ostaje %d vagona: ", brojrastucih);
        for (i = pocetakrastucih; i < brojvagona; i++)
        {
            if (rastucivagon[i] > maxvagon)
            {
                maxvagon = rastucivagon[i];
                printf("%d ", rastucivagon[i]);
            }
        }
        printf("\n");
    }
    else if (brojrastucih < brojpadajucih)
    {
        printf("Ostaje %d vagona: ", brojpadajucih);
        for (i = (brojvagona - pocetakpadajucih - 1); i >= 0; i--)
        {
            if (padajucivagon[i] > maxvagon)
            {
                maxvagon = padajucivagon[i];
                printf("%d ", padajucivagon[i]);
            }
        }
        printf("\n");
    }
    return 0;
}