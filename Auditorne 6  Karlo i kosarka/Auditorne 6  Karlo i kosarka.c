#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 150

void provjeriRedoslijed(int* pa, int* pb)
{
    int tempa;
    if (*pb < *pa)
    {
        tempa = *pa;
        *pa = *pb;
        *pb = tempa;
    }
}

long long racunanjeProstih(long long a, long long b)
{
    long long i, j, k;
    long long brojProstihbr = 0;
    long long test = 0;
    for (i = a; i <= b; i++)
    {
        k = 0;
        for (j = 1; j <= i; j++)
        {
            test = i % j;
            if (test == 0)
            {
                k++;
            }
        }
        if (k == 2)
        {
            brojProstihbr++;
        }
    }
    //printf("BROJ PROSTIH BROJEVA: %lld\n", brojProstihbr);
    return brojProstihbr;
}

long long racunanjeDjeljivs7ili9(long long a, long long b)
{
    long long i = a, j = b;
    long long brojdjeljivihbr = 0;
    long long test1 = 0, test2 = 0;
    //printf("%lld\n", a);
    while (i <= j)
    {
        //printf("%lld\n", i);
        test1 = i % 7;
        test2 = i % 9;
        if (test1 == 0 || test2==0 || (test1 == 0 && test2 == 0))
        {
            brojdjeljivihbr++;
        }
        i++;
    }
    //printf("BROJ DJELJIVIH S 7/9: %lld\n", brojdjeljivihbr);
    return brojdjeljivihbr;
}

void finalniSMS(long long sms[MAX], int brojutakmica)
{
    int i, k = 0, j, l = 0;
    j = brojutakmica;
    long long min = 1000001;
    //printf("sms[0] = %lld\n", sms[0]);
    while (k < brojutakmica)
    {
        min= 1000001;
        for (i = 0; i < j; i++)
        {
            //printf("%lld\n", sms[i]);
            if (sms[i] <= min)
            {
                min = sms[i];
                l = i;
                //printf("%lld [%d] MINIMALAN\n", min, l);
            }
        }
        for (i = l; i < j - 1; i++)
        {
            sms[i] = sms[i + 1];
            //printf("%lld [%d] MINIMALAN\n", min, l);
        }
        //printf("%lld [%d] MINIMALAN\n", min, l);
        if (k == 0)
        {
            printf("%lld", min);
        }
        else if (k != 0)
        {
            printf(", %lld", min);
        }
        j--;
        k++;
    }
    return;
}

int main()
{
    int brojutakmica, i;
    long long  a, b, tempa = 0, brojProstih = 0, brojdjeljivs7ili9 = 0, sms[MAX] = { 0 };
    scanf("%d", &brojutakmica);
    for (i = 0; i < brojutakmica; i++)
    {
        scanf("%lld %lld", &a, &b);
        // 1.) funkcija koja poreda a i b po velicini -> a < b
        provjeriRedoslijed(&a, &b);
        // 2.) funkcija koja izracuna broj prostih brojeva u intervalu [a,b]
        brojProstih = racunanjeProstih(a, b);
        // 3.) funkcija koja izracuna broj brojeva u intervalu [a,b] koji je djeljiv sa 7 ili s 9
        brojdjeljivs7ili9 = racunanjeDjeljivs7ili9(a, b);
        // 4.) funckija koja zbraja rezultate funkcija 2.) i 3.)
        sms[i] = brojProstih + brojdjeljivs7ili9;
        //printf("%lld\n", sms[i]);
        // 5.) funkcija koja rezultate funkcije 4.) poreda od najmanjeg do najveceg
    }
    finalniSMS(sms, brojutakmica);
    //printf("%d", sms[0]);
    //for (i = 1; i < brojutakmica; i++)
    //{
    //    printf(", %d", sms[i]);
    //}
    //printf("\n");
    return 0;
}