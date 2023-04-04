#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    long long d, m, g, h, min, s;
    long long k;
    long long sekunde = 0;
    long long minute = 0;
    long long sati = 0;
    long long dani = 0;
    long long prijestupna = 0;
    scanf("%lld %lld %lld %lld %lld %lld", &d, &m, &g, &h, &min, &s);
    while ((g < 1900) || (g > 2015))
    {
        scanf("%lld %lld %lld %lld %lld %lld", &d, &m, &g, &h, &min, &s);
    }
    //printf("%d %d %d %d %d %d\n", d, m, g, h, min, s);
    if (d== 1 && m==1 && h == 0 && min == 0 && s == 0)
    {
        d++;
    }
    scanf("%lld", &k);
    //printf("%lld\n", k);
    prijestupna = g % 4;
    if (prijestupna == 0)
    {
        switch (m)
        {
        case 2:
            dani += 31;
            //printf("dani = %d\n", dani);
            break;
        case 3:
            dani += 60;
            //printf("dani = %d\n", dani);
            break;
        case 4:
            dani += 91;
            //printf("dani = %d\n", dani);
            break;
        case 5:
            dani += 121;
            //printf("dani = %d\n", dani);
            break;
        case 6:
            dani += 152;
            //printf("dani = %d\n", dani);
            break;
        case 7:
            dani += 182;
            //printf("dani = %d\n", dani);
            break;
        case 8:
            dani += 213;
            //printf("dani = %d\n", dani);
            break;
        case 9:
            dani += 244;
            //printf("dani = %d\n", dani);
            break;
        case 10:
            dani += 274;
            //printf("dani = %d\n", dani);
            break;
        case 11:
            dani += 305;
            //printf("dani = %d\n", dani);
            break;
        case 12:
            dani += 335;
            //printf("dani = %d\n", dani);
            break;
        }
    }
    else if (prijestupna != 0)
    {
        switch (m)
        {
        case 2:
            d += 31;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 3:
            d += 59;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 4:
            d += 90;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 5:
            d += 120;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 6:
            d += 151;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 7:
            d += 181;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 8:
            d += 212;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 9:
            d += 243;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 10:
            d += 273;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 11:
            d += 304;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        case 12:
            d += 334;
            //printf("PRIJESTUPNA - dani = %d\n", dani);
            break;
        }
    }
    sekunde = k + s + min * 60 + h * 60 * 60 + d * 24 * 60 * 60;
    //printf("SEKUNDE: %lld\n", sekunde);
    while (sekunde > 31535999)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            sekunde -= 31622400;
            //printf("PRIJESTUPNA!!!  PREOSTALE SEKUNDE: %lld     GODINA: %lld\n", sekunde, g);
            g++;
        }
        else
        {
            sekunde -= 31536000;
            //printf("PREOSTALE SEKUNDE: %lld     GODINA: %lld\n", sekunde, g);
            g++;
        }
    }
    //printf("PREOSTALE SEKUNDE: %lld     GODINA: %lld\n", sekunde, g);
    while (sekunde > 86399)
    {
        sekunde -= 86400;
        dani++;
        //printf("PREOSTALE SEKUNDE: %lld     DANI: %lld\n", sekunde, dani);
    }
    while (sekunde > 3599)
    {
        sekunde -= 3600;
        sati++;
        //printf("PREOSTALE SEKUNDE: %lld     SATI: %lld\n", sekunde, sati);
    }
    while (sekunde > 59)
    {
        sekunde -= 60;
        minute++;
        //printf("PREOSTALE SEKUNDE: %lld     MINUTE: %lld\n", sekunde, minute);
    }
    //printf("dani = %d\n", dani);

    if (dani > 334)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("12.mj. prijestupna\n");
            dani -= 335;
            m = 12;
        }
        else
        {
            // printf("12.mj. obicna\n");
            dani -= 334;
            m = 12;
        }
    }
    else if (dani > 304)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("11.mj. prijestupna\n");
            dani -= 305;
            m = 11;
        }
        else
        {
            //printf("11.mj. obicna\n");
            dani -= 304;
            m = 11;
        }
    }
    else if (dani > 273)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("10.mj. prijestupna\n");
            dani -= 274;
            m = 10;
        }
        else
        {
            //printf("10.mj. obicna\n");
            dani -= 273;
            m = 10;
        }
    }
    else if (dani > 243)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("9.mj. prijestupna\n");
            dani -= 244;
            m = 9;
        }
        else
        {
            //printf("9.mj. obicna\n");
            dani -= 243;
            m = 9;
        }
    }
    else if (dani > 212)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("8.mj. prijestupna\n");
            dani -= 213;
            m = 8;
        }
        else
        {
            // printf("8.mj. obicna\n");
            dani -= 212;
            m = 8;
        }
    }
    else if (dani > 181)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("7.mj. prijestupna\n");
            dani -= 182;
            m = 7;
        }
        else
        {
            // printf("7.mj. obicna\n");
            dani -= 181;
            m = 7;
        }
    }
    else if (dani > 151)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("6.mj. prijestupna\n");
            dani -= 152;
            m = 6;
        }
        else
        {
            // printf("6.mj. obicna\n");
            dani -= 151;
            // printf("%lld\n", d);
            m = 6;
        }
    }
    else if (dani > 120)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("5.mj. prijestupna\n");
            dani -= 121;
            m = 5;
        }
        else
        {
            //printf("5.mj. obicna\n");
            dani -= 120;
            m = 5;
        }
    }
    else if (dani > 90)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            // printf("4.mj. prijestupna\n");
            dani -= 91;
            m = 4;
        }
        else
        {
            // printf("4.mj. obicna\n");
            dani -= 90;
            m = 4;
        }
    }
    else if (dani > 59)
    {
        prijestupna = g % 4;
        if (prijestupna == 0)
        {
            //printf("3.mj. prijestupna\n");
            dani -= 60;
            m = 3;
        }
        else
        {
            //printf("3.mj. obicna\n");
            dani -= 59;
            m = 3;
        }
    }
    else if (dani > 31)
    {
        //printf("2.mj.\n");
        dani -= 31;
        m = 2;
    }
    else if (dani <= 31)
    {
        //printf("1.mj.\n");
        m = 1;
    }
    printf("%lld.%lld.%lld. %02lld:%02lld:%02lld\n", dani, m, g, sati, minute, sekunde);
    return 0;
}