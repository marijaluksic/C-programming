#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, c;
    char b;
    scanf("%d%c", &a, &b);
    if (b == 'K')
    {
        printf("%d\n", a * a);
    }
    else
    {
        scanf("%d", &c);
        if (b == '+')
        {
            printf("%d\n", a + c);
        }
        else if (b == '-')
        {
            printf("%d\n", a - c);
        }
        else if (b == '*')
        {
            printf("%d\n", a * c);
        }
        else if (b == '/')
        {
            printf("%d\n", a / c);
        }
        else if (b == '+')
        {
            printf("%d\n", a + c);
        }
    }
    return 0;
}