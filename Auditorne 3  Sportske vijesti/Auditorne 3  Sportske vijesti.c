#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    char unos;
    int golovid = 0;
    int golovig = 0;
    int udarcid = 0;
    int udarcig = 0;
    int okvird = 0;
    int okvirg = 0;
    int kornerid = 0;
    int kornerig = 0;
    int faulovid = 0;
    int faulovig = 0;
    int zkartond = 0;
    int zkartong = 0;
    int ckartond = 0;
    int ckartong = 0;
    do
    {
        scanf(" %c", &unos);
        if (unos == 'g')
        {
            golovid++;
        }
        else if (unos == 'G')
        {
            golovig++;
        }
        else if (unos == 'u')
        {
            udarcid++;
        }
        else if (unos == 'U')
        {
            udarcig++;
        }
        else if (unos == 'o')
        {
            okvird++;
        }
        else if (unos == 'O')
        {
            okvirg++;
        }
        else if (unos == 'k')
        {
            kornerid++;
        }
        else if (unos == 'K')
        {
            kornerig++;
        }
        else if (unos == 'f')
        {
            faulovid++;
        }
        else if (unos == 'F')
        {
            faulovig++;
        }
        else if (unos == 'z')
        {
            zkartond++;
        }
        else if (unos == 'Z')
        {
            zkartong++;
        }
        else if (unos == 'c')
        {
            ckartond++;
        }
        else if (unos == 'C')
        {
            ckartong++;
        }
        else if (unos != '*')
        {
            printf("Znak nije ispravan!\n");
        }
    } while ((unos!='*') && (ckartond < 5) && (ckartong < 5));
    printf("Utakmica je zavrsila!\n");
    printf("Statistike utakmice:\n");
    printf("\n");
    printf("\n");
    printf("Domaca ekipa:\n");
    printf("Broj golova: %d\n", golovid);
    printf("Udarci prema golu: %d\n", udarcid + golovid + okvird);
    printf("Udarci u okvir: %d\n", okvird + golovid);
    printf("Korneri: %d\n", kornerid);
    printf("Faulovi: %d\n", faulovid + zkartond + ckartond);
    printf("Zuti kartoni: %d\n", zkartond);
    printf("Crveni kartoni: %d\n", ckartond);
    printf("\n");
    printf("\n");
    printf("Gostujuca ekipa:\n");
    printf("Broj golova: %d\n", golovig);
    printf("Udarci prema golu: %d\n", udarcig + golovig + okvirg);
    printf("Udarci u okvir: %d\n", okvirg + golovig);
    printf("Korneri: %d\n", kornerig);
    printf("Faulovi: %d\n", faulovig + zkartong + ckartong);
    printf("Zuti kartoni: %d\n", zkartong);
    printf("Crveni kartoni: %d\n", ckartong);
    return 0;
}