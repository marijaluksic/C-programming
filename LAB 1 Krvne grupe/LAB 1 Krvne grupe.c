#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char mama;
    char prva;
    char tata;
    char druga;
    scanf(" %c %c %c %c", &mama, &prva, &tata, &druga);
    //printf("%c%c%c%c", mama, prva, tata, druga);
    if ((mama == 'A' && tata == 'A' && prva == 'X' && druga == 'X') || (prva == 'A' && druga == 'A' && mama == 'X' && tata == 'X') || (prva == 'A' && tata == 'A' && mama == 'X' && druga == 'X') || (mama == 'A' && druga == 'A' && tata == 'X' && prva == 'X'))
    {
        printf("A\n");
        printf("0\n");
    }
    else if ((mama == 'B' && tata == 'B' && prva == 'X' && druga == 'X') || (prva == 'B' && druga == 'B' && mama == 'X' && tata == 'X') || (prva == 'B' && tata == 'B' && mama == 'X' && druga == 'X') || (mama == 'B' && druga == 'B' && tata == 'X' && prva == 'X'))
    {
        printf("B\n");
        printf("0\n");
    }
    else if (mama == 'A' && prva == 'B' && tata == 'A' && druga == 'B')
    {
        printf("A\n");
        printf("B\n");
        printf("AB\n");
    }
    else if ((mama == '0' && tata == '0' && prva == 'X' && druga == 'X') || (prva == '0' && druga == '0' && mama == 'X' && tata == 'X') || (prva == '0' && tata == '0' && mama == 'X' && druga == 'X') || (mama == '0' && druga == '0' && tata == 'X' && prva == 'X'))
    {
        printf("0\n");
    }
    else if ((mama == 'A' && prva == 'B' && tata != '0' && druga != '0') || (mama != '0' && prva != '0' && tata == 'A' && druga == 'B'))
    {
        printf("A\n");
        printf("B\n");
        printf("AB\n");
    }
    else if ((mama == 'A' && prva == 'B' && (tata == '0' || druga == '0')) || ((mama == '0' || prva == '0') && tata == 'A' && druga == 'B'))
    {
        printf("A\n");
        printf("B\n");
    }
    return 0;
}