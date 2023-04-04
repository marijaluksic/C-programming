#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n;
    int i = 0;
    int brojacvrhova = 0;
    double prethodnivrh = 0;
    double prethodnavisina = 0;
    double maxvisina = 0;
    double koeficijent = 0;
    double x;
    double v;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x, &v);
        maxvisina = prethodnavisina + ((x - prethodnivrh) * koeficijent);
        //printf("VISINA: %lf     MAXVISINA: %lf\n", v, maxvisina);
        if (v >= maxvisina)
        {
            //printf("USAO U PETLJU -> %lf >= %lf\n", v, maxvisina);
            koeficijent = v / x;
            brojacvrhova++;
            prethodnivrh = x;
            prethodnavisina = v;
            //printf("KOEFICIJENT: %lf / %lf = %lf\n", v, x, koeficijent);
        }
        /* else
       {
           printf("PLANINA SE NE VIDI -> %lf < %lf\n", v, maxvisina);
       }
       printf("\n");*/
    }
    printf("%d\n", brojacvrhova);
    return 0;
}