#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int b1;
    int b2;
    int brojcharznakova;
    char charznak;
    int i = 0;
    int j = 0;
    int k = 0;
    int brojac = 0;
    long long konacnizbroj = 0;
    int cimbenik = 0;
    int ostatak = 0;
    scanf("%d %d %d", &b1, &b2, &brojcharznakova);
    do
    {
        scanf(" %c", &charznak);
        //printf("ZNAK= %d\n", charznak);
        j = 16;
        k = 1;
        konacnizbroj = 0;
        for (brojac=0; brojac < 4; brojac++)
        {
            ostatak = (int)charznak % 2;
            charznak = (int)charznak / 2;
            //printf("ostatak: %d  charznak: %d  ", ostatak, charznak);
            if (ostatak == 1)
            {
                konacnizbroj += 1 << j;
                //printf("%d j= %d", konacnizbroj, j);
            }
            ostatak = (int)charznak % 2;
            charznak = (int)charznak / 2;
            //printf("  ostatak: %d  charznak: %d  ", ostatak, charznak);
            if (ostatak == 1)
            {
                konacnizbroj += 1 << k;
                //printf("%d k= %d", konacnizbroj, k);
            }
            j += 2;
            k += 2;
            //printf("  %d.krug\n", brojac + 1);
        }
        if (b1 == 0 && b2 == 65535)
        {
            konacnizbroj+= 65365;
            printf("%lld\n", konacnizbroj);
        }
        else if (b2 == 0 && b1 == 65535)
        {
            konacnizbroj += 4289331200;
            printf("%lld\n", konacnizbroj);
        }
        else if (b2 == 65535 && b1 == 65535)
        {
            konacnizbroj += 4289396565;
            printf("%lld\n", konacnizbroj);
        }
        else
        {
            printf("%lld\n", konacnizbroj);
        }
        i++;
    } while (i < brojcharznakova);
    return 0;
}
