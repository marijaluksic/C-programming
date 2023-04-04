#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n;
    int i = 0;
    int j = 0;
    float prodaja, kupnja;
    //BANKA PRODAJE EURE (dakle kada banka prodaje, Munja ce svojim KUNAMA kupovat €)
    float minprodaja = 10;
    //BANKA KUPUJE EURE (dakle kada banka kupuje, Munja ce prodavat svoje € za KUNE)
    float maxkupnja = 0;
    float maxvrijednost = 0;
    float novcanik = 100;
    int brpromjena = 0;
    int valuta = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &prodaja, &kupnja);
        //printf("\nSTANJE NOVCANIKA NA POCETKU %d. DANA %f\n", i+1, novcanik);
        j = 0;
        valuta = brpromjena % 2;
        if (prodaja < minprodaja)
        {
            minprodaja = prodaja;
            //printf("%f\n", novcanik);
            //novcanik = (int)novcanik;
            //printf("%f\n", novcanik);
            //novcanik = novcanik / 100;
            //printf("%f\n", novcanik);
            if (valuta == 0)
            {
                novcanik = novcanik / minprodaja;
                brpromjena++;
                j++;
                //printf("!!!KUPIO EURE\n");
            }
        }
        if (kupnja > maxkupnja)
        {
            maxkupnja = kupnja;
            //novcanik = (int)novcanik;
            //novcanik = novcanik / 100;
            if ((j == 0) && (valuta != 0))
            {
                novcanik = novcanik * maxkupnja;
                brpromjena++;
                //printf("!!!PRODAO EURE\n");
            } 
        }
        //printf("MINKUPNJA: %f\n MAXPRODAJA: %f\n BROJ PROMJENA: %d\n NOVCANIK: %f\n", minkupnja, maxprodaja, brpromjena, novcanik);
        //printf("kraj %d. kruga\n", i+1);
    }
    valuta = brpromjena % 2;
    //printf("VALUTA: %d\n", valuta);
    if (valuta != 0)
    {
        printf("Nakon %d promjena, ostaje mu %.2f EUR.\n", brpromjena, novcanik);
        //printf("MINKUPNJA: %f\n MAXPRODAJA: %f\n", minkupnja, maxprodaja);
    }
    else
    {
        printf("Nakon %d promjena, ostaje mu %.2f kn.\n", brpromjena, novcanik);
        //printf("MINKUPNJA: %f\n MAXPRODAJA: %f\n", minkupnja, maxprodaja);
    }
}