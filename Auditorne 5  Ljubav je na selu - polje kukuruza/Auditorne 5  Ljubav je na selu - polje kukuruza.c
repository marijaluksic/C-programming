#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    char polje[3][20];
    int razlikakukuruza = 3;
    int kukuruz[3] = { 0 };
    int vrijeme[3] = { 0 };
    int i, j;
    float pozicija[3] = { 0 };
    float max = 0;
    int min = 20;
    float red = 0;
    int minvrijeme = 100;
    int indexvrijeme = 0;
    int maxkukuruz = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 20; j++)
        {
            scanf(" %c", &polje[i][j]);
            if (polje[i][j] == 'I')
            {
                kukuruz[i]+= 1;
                vrijeme[i] += 5;
            }
            if (polje[i][j] == '.')
            {
                vrijeme[i] += 1;
            }
            if (polje[i][j] == ',')
            {
                vrijeme[i] += 2;
            }
        }
        if (vrijeme[i] < minvrijeme)
        {
            minvrijeme = vrijeme[i];
            indexvrijeme = i+1;
        }
        if (kukuruz[i] > maxkukuruz)
        {
            maxkukuruz = kukuruz[i];
        }
        if (kukuruz[i] < min)
        {
            min = kukuruz[i];
        }
        pozicija[i] = (float)kukuruz[i]/(float)vrijeme[i];
        if (pozicija[i] > max)
        {
            max = pozicija[i];
            red = i + 1;
        }
    }
    if (maxkukuruz - min < 4 && maxkukuruz - min != 0)
    {
        red = indexvrijeme;
    }
    printf("Pozicioniraj se u %.f. red!\n", red);
    return 0;
}