#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char unos[9][9] = { 0 };
    int testgreskaredak[9] = { 0 };
    int testgreskastupac[9] = { 0 };
    int greskaredak = 0;
    int greskastupac = 0;
    int greskakvadrat = 0;
    int i, j;
    int provjera[9][9] = { 0 };
    int stop = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf(" %c", &unos[i][j]);
        }
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (unos[i][j] == '1' && stop == 0)
            {
                provjera[i][0]++;
                if (provjera[i][0] == 1)
                {
                    testgreskaredak[0] = i + 1;
                    testgreskastupac[0] = j + 1;
                }
                if (provjera[i][0] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[0];
                    greskastupac = testgreskastupac[0];
                }
            }
            if (unos[i][j] == '2' && stop == 0)
            {
                provjera[i][1]++;
                if (provjera[i][1] == 1)
                {
                    testgreskaredak[1] = i + 1;
                    testgreskastupac[1] = j + 1;
                }
                if (provjera[i][1] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[1];
                    greskastupac = testgreskastupac[1];
                }
            }
            if (unos[i][j] == '3' && stop == 0)
            {
                provjera[i][2]++;
                if (provjera[i][2] == 1)
                {
                    testgreskaredak[2] = i + 1;
                    testgreskastupac[2] = j + 1;
                }
                if (provjera[i][2] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[2];
                    greskastupac = testgreskastupac[2];
                }
            }
            if (unos[i][j] == '4' && stop == 0)
            {
                provjera[i][3]++;
                if (provjera[i][3] == 1)
                {
                    testgreskaredak[3] = i + 1;
                    testgreskastupac[3] = j + 1;
                }
                if (provjera[i][3] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[3];
                    greskastupac = testgreskastupac[3];
                }
            }
            if (unos[i][j] == '5' && stop == 0)
            {
                provjera[i][4]++;
                if (provjera[i][4] == 1)
                {
                    testgreskaredak[4] = i + 1;
                    testgreskastupac[4] = j + 1;
                }
                if (provjera[i][4] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[4];
                    greskastupac = testgreskastupac[4];
                }
            }
            if (unos[i][j] == '6' && stop == 0)
            {
                provjera[i][5]++;
                if (provjera[i][5] == 1)
                {
                    testgreskaredak[5] = i + 1;
                    testgreskastupac[5] = j + 1;
                }
                if (provjera[i][5] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[5];
                    greskastupac = testgreskastupac[5];
                }
            }
            if (unos[i][j] == '7' && stop == 0)
            {
                provjera[i][6]++;
                if (provjera[i][6] == 1)
                {
                    testgreskaredak[6] = i + 1;
                    testgreskastupac[6] = j + 1;
                }
                if (provjera[i][6] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[6];
                    greskastupac = testgreskastupac[6];
                }
            }
            if (unos[i][j] == '8' && stop == 0)
            {
                provjera[i][7]++;
                if (provjera[i][7] == 1)
                {
                    testgreskaredak[7] = i + 1;
                    testgreskastupac[7] = j + 1;
                }
                if (provjera[i][7] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[7];
                    greskastupac = testgreskastupac[7];
                }
            }
            if (unos[i][j] == '9' && stop == 0)
            {
                provjera[i][8]++;
                if (provjera[i][8] == 1)
                {
                    testgreskaredak[8] = i + 1;
                    testgreskastupac[8] = j + 1;
                }
                if (provjera[i][8] == 2)
                {
                    stop++;
                    greskaredak = testgreskaredak[8];
                    greskastupac = testgreskastupac[8];
                }
            }
        }

    }
    if (greskaredak > 0 && greskaredak <= 3)
    {
        if (greskastupac <= 3)
        {
            greskakvadrat = 1;
        }
        else if (greskastupac > 3 && greskastupac < 7)
        {
            greskakvadrat = 2;
        }
        else if (greskastupac > 6)
        {
            greskakvadrat = 3;
        }
    }
    if (greskaredak > 3 && greskaredak < 7)
    {
        if (greskastupac <= 3)
        {
            greskakvadrat = 4;
        }
        else if (greskastupac > 3 && greskastupac < 7)
        {
            greskakvadrat = 5;
        }
        else if (greskastupac > 6)
        {
            greskakvadrat = 6;
        }
    }
    if (greskaredak >= 7)
    {
        if (greskastupac <= 3)
        {
            greskakvadrat = 7;
        }
        else if (greskastupac > 3 && greskastupac < 7)
        {
            greskakvadrat = 8;
        }
        else if (greskastupac > 6)
        {
            greskakvadrat = 9;
        }
    }
    if (greskakvadrat == 0)
    {
        printf("Ispravno!\n");
    }
    else 
    {
        printf("Neispravno!\n");
        printf("Greska u: %d. redak, %d. stupac, %d. kvadrat.\n", greskaredak, greskastupac, greskakvadrat);
    }
    return 0;
}