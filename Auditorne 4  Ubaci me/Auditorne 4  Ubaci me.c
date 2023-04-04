#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main()
{
    int n;
    int nizN[MAX];
    int x;
    int ai;
    int bi;
    int i = 0;
    int j = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nizN[i]);
    }
    scanf("%d", &x);
    for (j = 0; j < x; j++)
    {
        scanf("%d %d", &ai, &bi);//- "ai" JE VRIJEDNOST KOJU UBACUJEMO NA "bi" MJESTO U 
        //                              NIZU
        //- POMAKNUTI SVE ELEMENTE NIZA ZA JEDNO MJESTO U DESNO SAMO OD REDNOG BROJA
        //      GDJE TREBAMO UBACITI NOVI ELEMENT
        //      - MICEMO U DESNO NA NACIN DA KRENEMO VRTITI PETLJU OD KRAJA PREMA POCETKU;
        //      ODNOSNO OD "n-1" DO "bi-1" GDJE CEMO UBACITI VRIJEDNOST "ai"
        //      - OVAKO VRIJEDNOSTI NIZA MICEMO ZA 1 MJESTO U DESNO: nizN[i+1] = niz [i]
        //- ZADNJI ELEMENT IMA INDEX: "n-1"; ODNOSNO, VRIJEDNOST "ai" TREBAMO UBACITI NA 
        //      MJESTO U NIZU INDEXA "bi-1"
        for (i = n - 1; i >= bi - 1 && i >= 0; i--) //- "&& i >= 0" SMO DODALI SAMO KAKO
        {                 // BI SE DODATNO OSIGURALI OD NEGATIVNIH VRIJEDNOSTI BROJACA "i"
            nizN[i + 1] = nizN[i];      
                                    //"PETLJA ZA POMICANJE NIZA ZA 1 MJESTO U DESNO"
        }
        // NAKON STO SMO POMAKNULI CIJELI NIZ ZA 1 MJESTO U DESNO, UBACUJEMO VRIJEDNOST
        // "ai" NA ZELEJNO MJESTO U NIZU "bi" - ODNOSNO "bi - 1"
        nizN[bi - 1] = ai;
        //- NAKON SVAKOG UBACIVANJA VELICINU NIZA POVECATI ZA 1 MJESTO
        n++; // JER SMO DEFINIRALI BROJAC "i" SA "i = n - 1"
        // I S OVIME SMO IZMIJENILI NIZ KOJEG JOS TREBA ISPISATI
        for (i = 0; i < n; i++)
        {                           // "n" JE IZMJENJEN, ODNOSNO, NIZ JE PROSIREN TE
            printf("%d ", nizN[i]);  // TE GA BEZ BRIGE ISPISUJEMO KAO STO SMO GA
        }                           // INICIJALNO I UCITALI
        printf("\n");
    }
    return 0;
}