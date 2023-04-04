#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char a, b, c, d, e;
    int rjesenje = 0;
    scanf(" %c %c %c %c %c", &a, &b, &c, &d, &e);
    if ((a == '0' || a == '1') && (b == '0' || b == '1') && (c == '0' || c == '1') && (d == '0' || d == '1') && (e == '0' || e == '1'))
    {
        if (a == '0')
        {
            if (b == '1')
            {
                rjesenje += 8;
            }
            if (c == '1')
            {
                rjesenje += 4;
            }
            if (d == '1')
            {
                rjesenje += 2;
            }
            if (e == '1')
            {
                rjesenje += 1;
            }
            printf("%d\n", rjesenje);
        }
        else
        {
            if (b == '1')
            {
                rjesenje += 8;
            }
            if (c == '1')
            {
                rjesenje += 4;
            }
            if (d == '1')
            {
                rjesenje += 2;
            }
            if (e == '1')
            {
                rjesenje += 1;
            }
            printf("%d\n", (rjesenje - 16));
        }
    }
    else
    {
        printf("Pogresan unos!\n");
    }
    return 0;
}