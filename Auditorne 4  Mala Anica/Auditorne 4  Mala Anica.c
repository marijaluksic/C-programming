#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 100
int main()
{
    int i = 0;
    int maxmnozenik;
    int mnozenik[MAX] = { 0 };
    int mnozitelj;
    int prvihnormalnih;
    int zadnjiobrnuti;
    scanf("%d %d", &maxmnozenik, &mnozitelj);
    scanf("%d %d", &prvihnormalnih, &zadnjiobrnuti);
    maxmnozenik = ceil(maxmnozenik / 2);
    zadnjiobrnuti = maxmnozenik - zadnjiobrnuti;
    for (i = 1; i <= maxmnozenik; i ++)
    {
        mnozenik[i - 1] = i * 2 * mnozitelj;
    }
    for (i = 0; i < prvihnormalnih; i++)
    {
        printf("%d\n", mnozenik[i]);
    }
    for (i = zadnjiobrnuti-1; i >= prvihnormalnih; i--)
    {
        printf("%d\n", mnozenik[i]);
    }
    for (i = zadnjiobrnuti; i < maxmnozenik; i++)
    {
        printf("%d\n", mnozenik[i]);
    }
    return 0;
}