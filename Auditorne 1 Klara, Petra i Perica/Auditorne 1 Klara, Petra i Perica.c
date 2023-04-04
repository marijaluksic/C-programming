#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g, h, i, j = 0;
    scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
    a = a + 64;
    b = b + 64;
    c = c + 64;
    d = d + 64;
    e = e + 64;
    f = f + 64;
    g = g + 64;
    h = h + 64;
    i = i + 64;
    if (j == 0)
    {
        printf("%c %c %c %c %c %c %c %c %c\n", a, b, c, d, e, f, g, h, i);
        printf("KRAJ PORUKE!\n");
        return 0;
    }
    else
    {
        j = j + 64;
        printf("%c %c %c %c %c %c %c %c %c %c\n", a, b, c, d, e, f, g, h, i, j);
    }
    return 0;
}