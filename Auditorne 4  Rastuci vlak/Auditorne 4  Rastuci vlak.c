#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000

int main()
{
    int brojvagona;
    int i, j = 0, k = 0;
    int rastucivagon[MAX] = { 0 };
    int padajucivagon[MAX] = { 0 };
    int rastucivlakbrojac = 0;
    int padajucivlakbrojac = 0;
    int maxrastuci[MAX] = { 0 };
    int maxpadajuci[MAX] = { 0 };
    int maxvagon = 0;
    scanf("%d ", &brojvagona);
    for (i = 0; i < brojvagona; i++)
    {
        scanf("%d", &rastucivagon[i]);
    }
    i = 0;
    for (i = (brojvagona-1); i >= 0; i--)
    {
        padajucivagon[i] = rastucivagon[j];
        j++;
    } 
   /* printf("RASTUCI VLAK:   ");
    for (i = 0; i < brojvagona; i++)
    {
        printf("%d ", rastucivagon[i]);
    }
    printf("\n");
    printf("PADAJUCI VLAK:   ");
    for (i = 0; i < brojvagona; i++)
    {
        printf("%d ", padajucivagon[i]);
    }
    printf("\n");*/
    for (i = 0; i < brojvagona; i++)
    {
        if (rastucivagon[i] >= maxvagon)
        {
            maxvagon = rastucivagon[i];
            maxrastuci[rastucivlakbrojac] = rastucivagon[i];
            rastucivlakbrojac++;
        }
        //printf("MAX VAGON %d\n", maxvagon);
    }
    maxvagon = 0;
    for (i = 0; i < brojvagona; i++)
    {
        if (padajucivagon[i] >= maxvagon)
        {
            maxvagon = padajucivagon[i];
            maxpadajuci[padajucivlakbrojac] = padajucivagon[i];
            padajucivlakbrojac++;
        }
        //printf("MAX VAGON %d\n", maxvagon);
    }
    //printf("RASTUCI VLAK NAKON IZMJENE:   ");
    if (padajucivlakbrojac == rastucivlakbrojac)
    {
        if (rastucivagon[0] > padajucivagon[padajucivlakbrojac-1])
        {
            printf("Ostaje %d vagona: ", rastucivlakbrojac);
            for (i = 0; i < rastucivlakbrojac; i++)
            {
                printf("%d ", rastucivagon[i]);
            }
            //printf("RASTUCI VLAK padajucivlakbrojac == rastucivlakbrojac\n");
        }
        else if (padajucivagon[padajucivlakbrojac-1] > rastucivagon[0])
        {
            printf("Ostaje %d vagona: ", padajucivlakbrojac);
            for (i = (padajucivlakbrojac-1); i >= 0 ; i--)
            {
                printf("%d ", padajucivagon[i]);
            }
            //printf("PADAJUCI VLAK padajucivlakbrojac == rastucivlakbrojac\n");
        }
    }
    else if (rastucivlakbrojac > padajucivlakbrojac)
    {
        printf("Ostaje %d vagona: ", rastucivlakbrojac);
        for (i = 0; i < rastucivlakbrojac; i++)
        {
            printf("%d ", maxrastuci[i]);
        }
        //printf("RASTUCI VLAK\n");
    }
    else if (rastucivlakbrojac < padajucivlakbrojac)
    {
        printf("Ostaje %d vagona: ", padajucivlakbrojac);
        for (i = (padajucivlakbrojac - 1); i >= 0; i--)
        {
            printf("%d ", maxpadajuci[i]);
        }
        //printf("PADAJUCI VLAK\n");
    }
    printf("\n");
    return 0;
}