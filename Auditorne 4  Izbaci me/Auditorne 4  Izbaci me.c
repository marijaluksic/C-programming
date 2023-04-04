#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main()
{
    int i = 0;
    int j = 0;
    int n, k;
    int nizmax[MAX]; //- IMAMO 2 NIZA JER TREBAMO ISPITATI 2 SVOJSTVA (NAJVECE BROJEVE
    int nizmin[MAX];//  I NAJMANJE BROJEVE KOJE TREBAMO IZBACITI IZ NIZA) 
    int najveci = nizmax[0]; //- INICILAZIRAMO GA NA 1. BROJ U NIZU A NE NA NULU ZA SLUCAJ
    int indexnajveci = 0;    // DA BROJ U NIZU IMA NEGATIVNU VRIJEDNOST
    int najmanji = nizmin[0];
    int indexnajmanji = 0;
    scanf("%d %d", &n, &k); 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nizmax[i]); //- RADIMO DUPLIKAT NIZA
        nizmin[i] = nizmax[i];
    }
    for (j = 0; j < k; j++)
    {
        najveci = nizmax[0];
        for (i = 0; i < n; i++) //- VRTIMO PETLJU I ISPITUJEMO KOJI BROJ JE NAJVECI
        {
            if (nizmax[i] >= najveci)
            {
                najveci = nizmax[i];
                indexnajveci = i;
            }
        }
        for (i = indexnajveci; i < n - 1; i++) //- ZAPOCINJEMO SA BROJEM KOJEG TREBAMO IZBACITI,
        { //- KADA SMANJUJEMO NIZ, IDEMO OD POCETKA PREMA KRAJU, ODNOSNO S LIJEVA NA DESNO
            nizmax[i] = nizmax[i + 1]; // - IDEMO OD POCETKA DO "n - 1" JER SMANJUJEMO NIZ
        }                               //- POMICEMO CIJELI NIZ ZA JEDNO MJESTO U DESNO
        n--; //- KADA IZBACIMO BROJ IZ NIZA, SMANJUJEMO DULJINU NIZA ZA 1
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", nizmax[i]); //- ISPISUJEMO NOVI SKRACENI NIZ
    }
    printf("\n");
    n += k;
    for (j = 0; j < k; j++)
    {
        najmanji = nizmin[0];
        for (i = 0; i < n; i++) //- VRTIMO PETLJU I ISPITUJEMO KOJI BROJ JE NAJMANJI
        {
            if (nizmin[i] <= najmanji)
            {
                najmanji = nizmin[i];
                indexnajmanji = i;
            }
        }
        for (i = indexnajmanji; i < n - 1; i++)
        {
            nizmin[i] = nizmin[i + 1];
        }
        n--;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", nizmin[i]); //- ISPISUJEMO NOVI SKRACENI NIZ
    }
    printf("\n");
    return 0;
}