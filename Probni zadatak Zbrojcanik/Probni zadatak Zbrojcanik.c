#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
    float x, y, rezultat;
    int n;
    scanf("%f %f", &x, &y);
    rezultat = x + y;
    if (ceil(rezultat) == rezultat)
    {
        n = rezultat;
        printf("%d", n);
    }
    else
        printf("%.1f", rezultat);
    return 0;
}