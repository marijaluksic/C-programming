#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int brojrazreda;
    int i = 0;
    int j = 0;
    int ocjena = 0;
    int ocjene[5] = { 0, 0, 0, 0, 0 };
    float sumaocjena = 0;
    float prosjek = 0;
    float sumaljudi = 0;
    scanf("%d", &brojrazreda);
    for (j = 0; j < brojrazreda; j++)
    {
        for (i = 0; i < 5; i++) 
        {
            scanf("%d", &ocjena);
            ocjene[i] += ocjena;
            sumaocjena += ocjena * (i + 1);
            sumaljudi += ocjena;
        }
    }
    prosjek = round(sumaocjena / sumaljudi);
    printf("Za %d razred/razreda\n", brojrazreda);
    printf("\n");
    printf("bilo je:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", ocjene[i]);
        switch (i) 
        {
        case 0:
            printf("nedovoljan, ");
            break;
        case 1:
            printf("dovoljan, ");
            break; 
        case 2:
            printf("dobar, ");
            break; 
        case 3:
            printf("vrlo dobar i ");
            break; 
        case 4:
            printf("odlican\n");
            break;
        }
    }
    printf("\n");
    printf("prosjecna ocjena je:\n");
    switch ((int)prosjek)
    {
    case 1:
        printf("nedovoljan\n");
        break;
    case 2:
        printf("dovoljan\n");
        break;
    case 3:
        printf("dobar\n");
        break;
    case 4:
        printf("vrlo dobar\n");
        break;
    case 5:
        printf("odlican\n");
        break;
    }
    return 0;
}