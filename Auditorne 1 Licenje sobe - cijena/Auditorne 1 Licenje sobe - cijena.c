#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    float visina, sirina, duljina, vrata;
    scanf("%f %f %f %f", &visina, &sirina, &duljina, &vrata);
    if (visina <= 0 || sirina <= 0 || duljina <= 0 || vrata <= 0)
    {
        printf("Dimenzija mora biti pozitivna!");
    }
    else if (sirina <= vrata)
    {
        printf("Vrata moraju stati u prostoriju!");
    }
    else
    {
        float nevrata;
        nevrata = vrata * (0.75 * visina);
        float nepod;
        nepod = sirina * duljina;
        float neprozori;
        neprozori = (0.1 * visina) * (0.1 * sirina);
        float prostorija, rezultat;
        prostorija = 2 * (visina * sirina + sirina * duljina + visina * duljina);
        rezultat = prostorija - nepod - nevrata - (neprozori * 2);
        float cijena;
        cijena = rezultat * 10.4;
        int lipe;
        //KAKO DOBITI ISPISIVANJE SAMO DECIMALA NEKOG FLOAT BROJA
        lipe = (cijena - (int)cijena) * 100;
        printf("Konacna cijena je: %.f kuna i %d lipa.", cijena, lipe);
    }
    return 0;
}