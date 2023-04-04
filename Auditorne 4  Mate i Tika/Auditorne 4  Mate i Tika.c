#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main()
{
    char unos = 0;
    int zapis[MAX] = { 0 };
    int i = 0;
    int l = 0;
    int operator = 0;
    int broj = 0;
    int zagrada = 0;
    int ispravnost = 0;
    int zadnjazatvorena[MAX] = { 0 };
    int zadnjaotvorena = 0;
    int brojacotvorenih = 0;
    int brojaczatvorenih = 0;
    int a = 0;
    while (1)
    {
        scanf(" %c", &unos);
        if (unos == '.')
        {
            break;
        }
        else if (unos >= '0' && unos <= '9')
        {
            broj++;
        }
        else if (unos == '*' || unos == '/' || unos == '-' || unos == '+')
        {
            operator++;
        }
        else if (unos == '(')
        {
            zapis[i] = 6;
            i++;
            zagrada++;
        }
        else if (unos == '{')
        {
            zapis[i] = 5;
            i++;
            zagrada++;
        }
        else if (unos == '[')
        {
            zapis[i] = 4;
            i++;
            zagrada++;
        }
        else if (unos == ')')
        {
            zapis[i] = 3;
            i++;
            zagrada--;
        }
        else if (unos == '}')
        {
            zapis[i] = 2;
            i++;
            zagrada--;
        }
        else if (unos == ']')
        {
            zapis[i] = 1;
            i++;
            zagrada--;
        }
        else
        {
            ispravnost++;
            //printf("KRIVI UNOS %c\n", unos);
        }
    }
    if (operator + 1 != broj || zagrada != 0)
    {
        ispravnost++;
        //printf("operator + 1 != broj || zagrada != 0\n");
    }
    if (zagrada == 0) 
    {
        for (l = i-1; l >= 0; l--)
        {
            if (zapis[l] < 4 && zapis[l] > 0)
            {
                zadnjazatvorena[brojaczatvorenih] = zapis[l];
                brojaczatvorenih++;
            }
            //printf("BROJAC ZATVORENIH: %d\n", brojaczatvorenih);
            if (zapis[l] > 3)
            {
                zadnjaotvorena = zapis[l - brojacotvorenih];
                //printf("ZADNJA ZATVORENA %d      ZADNJA OTVORENA %d     BROJAC OTVORENIH %d\n", zadnjazatvorena[brojaczatvorenih - 1], zadnjaotvorena - 3, brojacotvorenih);
                if (zadnjaotvorena != zadnjazatvorena[brojaczatvorenih - 1] + 3)
                {
                    ispravnost++;
                }
                brojaczatvorenih--;
                brojacotvorenih++;
            }
            brojacotvorenih = 0;
            //printf("%d \n", zapis[l]);
        }
    }
    //printf("\n");
    //printf("ISPRAVNOST %d\n", ispravnost);
    //printf("\n");
    if (ispravnost != 0)
    {
        printf("NEISPRAVNO\n");
    }
    else
    {
        printf("ISPRAVNO\n");
    }
    return 0;
}