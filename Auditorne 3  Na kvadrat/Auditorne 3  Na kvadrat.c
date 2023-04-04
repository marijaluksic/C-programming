#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n;
    int i = 2;
    int provjera = 0;
    int brojac = 0;
    int djelitelj = 0;
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        //printf("broj: %d\n", i);
        djelitelj = i * i;
        //printf("djelitelj: %d\n", djelitelj);
        provjera = n % djelitelj;
        if (provjera == 0)
        {
            brojac++;
        }
    }
    printf("%d\n", brojac);
    return 0;
}