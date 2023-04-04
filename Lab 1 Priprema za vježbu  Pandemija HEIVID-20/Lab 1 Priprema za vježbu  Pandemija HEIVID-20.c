#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    char a, b, c;
    int suma = 0;
    int br1 = 0;
    int br2 = 0;
    int br3 = 0;
    scanf(" %c %c %c", &a, &b, &c);
    //printf("%c%c%c", a, b, c);
    if (a == '0' && b == '0' && c == '0')
    {
        printf("Neispravan unos!");
    }
    else if ((a >= '0' && a <= '3') && (b >= '0' && b <= '3') && (c >= '0' && c <= '3'))
    {
        if ((a == b || a == c) && a != '0')
        {
            printf("Neispravan unos!");
        }
        else
        {
            switch (a)
            {
            case '1':
                suma += 1;
                br1++;
                break;
            case '2':
                suma += 2;
                br2++;
                break;
            case '3':
                suma += 3;
                br3++;
                break;
            }
            switch (b)
            {
            case '1':
                suma += 1;
                br1++;
                break;
            case '2':
                suma += 2;
                br2++;
                break;
            case '3':
                suma += 3;
                br3++;
                break;
            }
            switch (c)
            {
            case '1':
                suma += 1;
                br1++;
                break;
            case '2':
                suma += 2;
                br2++;
                break;
            case '3':
                suma += 3;
                br3++;
                break;
            }
            //printf("suma je %d", suma);
            if (br1 <= 1 && br2 <= 1 && br3 <= 1)
            {
                switch (suma)
                {
                case 1:
                    printf("Maksimalno 5!");
                    break;
                case 2:
                    printf("Maksimalno 10!");
                    break;
                case 3:
                    printf("Neispravan unos!");
                    break;
                case 4:
                    printf("Maksimalno 15!");
                    break;
                case 5:
                    printf("Okupljanje zabranjeno!");
                    break;
                case 6:
                    printf("Neispravan unos!");
                    break;
                }
            }
            else
            {
                printf("Neispravan unos!");
            }
        }
    }
    else
    {
        printf("Neispravan unos!");
    }
    return 0;
}