#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char slovo;
    int broj;
    scanf(" %c %d", &slovo, &broj);
    if ((slovo >= 65) && (slovo <= 90))
    {
        slovo += broj + 32;
        printf("%c", slovo);
    }
    else
    {
        slovo += broj - 32;
        printf("%c", slovo);
    }
    return 0;
}