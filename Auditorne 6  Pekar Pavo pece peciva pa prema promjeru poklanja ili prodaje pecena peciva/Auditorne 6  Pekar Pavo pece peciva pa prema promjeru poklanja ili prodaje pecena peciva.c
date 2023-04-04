#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 100

float hambi(float ruupa, float oopseg)
{
    int stane;
    //printf("%f>= %f\n", (ruupa * 3.141593), oopseg);
    if (ruupa * 3.141593 >= oopseg)
    {
         stane = 0;
    }
    else
    {
        stane = 1;
    }
    return stane;
}

float slapica(float ruupa, float oopseg)
{
    int stane;
    double dvojka = 2;
    //printf("%f>= %f\n", ruupa * 3.141593, oopseg/2);
    if ((int)ruupa * 3 > (int)oopseg/2)
    {
        stane = 0;
    }
    else
    {
        stane = 1;
    }
    return stane;
}

float trokut(float ruupa, float oopseg)
{
    int stane;
    double dvojka = 2;
    //printf("%f >= %f\n", ruupa * 3.141593, oopseg);
    if (ruupa * 3.141593 >= oopseg)
    {
        stane = 0;
    }
    else
    {
        stane = 1;
    }
    return stane;
}

int main()
{
    int ispeceni, i;
    float opseg = 0;
    float rupa = 0;
    float masa = 0;
    char vrstapeciva = 0;
    float propalo = 0.0;
    int prodano[3] = { 0 };
    float racun = 0;
    scanf("%d", &ispeceni);
    while (ispeceni < 2 || ispeceni>99)
    {
        printf("Nepravilan unos!\n");
        scanf("%d", &ispeceni);
    }
    scanf("%f", &rupa);
    while (rupa < 5 || rupa>50)
    {
        printf("Nepravilan unos!\n");
        scanf("%f", &rupa);
    }
    for (i = 0; i < ispeceni; i++)
    {
        scanf(" %c%f%f", &vrstapeciva, &opseg, &masa);
        //printf("%c %f %f\n", vrstapeciva, opseg, masa);
        if (vrstapeciva == 'H')
        {
            //printf("HAMBI\n");
            racun = hambi(rupa, opseg) * (masa/1000);
            if (racun == 0)
            {
                prodano[0]++;
                //printf("prodan hambi! %d hambija\n", prodano[0]);
            }
            else 
            {
                propalo += racun;
                //printf("racun: %.2f     ukupno: %.2f\n", racun, propalo);
            }
        }
        if (vrstapeciva == 'S')
        {
            //printf("SLAPICA\n");
            racun = slapica(rupa, opseg) * (masa/1000);
            if (racun == 0)
            {
                prodano[1]++;
                //printf("prodana slapica! %d slapica\n", prodano[1]);
            }
            else
            {
                propalo += racun;
                //printf("racun: %.2f     ukupno: %.2f\n", racun, propalo);
            }
        }
        if (vrstapeciva == 'T')
        {
            //printf("TROKUT\n");
            racun = trokut(rupa, opseg) * (masa/1000);
            if (racun == 0)
            {
                prodano[2]++;
                //printf("prodan trokut! %d trokuta\n", prodano[2]);
            }
            else
            {
                propalo += racun;
                //printf("racun: %.2f     ukupno: %.2f\n", racun, propalo);
            }
        }
    }
    printf("Poklonit ce %.2f kg peciva.\n", propalo);
    printf("U automatu ce biti %d hambi peciva, %d slapica i %d sir-trokuta.\n", prodano[0], prodano[1], prodano[2]);
    //for (i = 0; i < ispeceni; i++)
    //{
    //    printf("%c %d %d\n", vrstapeciva[i], opseg[i], masa[i]);
    //}
    return 0;
}