#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 1000
int main()
{
	long long sekunde = 0;
	long long nizrazlicitihsati[MAX] = { 0 };
	int brojacrazlicitihsati = 0;
	float kolicina = 0;
	float sati = 0;
	int prethodnisat = 0;
	float nizsekunda[MAX] = { 0 };
	float nizsekundabrojac[MAX] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	float ukupnakolicina[MAX] = { 0 };
	float maxkolicina = 0;
	long long tempsat = 0;
	float tempkolicina = 0;
	while (1)
	{
		scanf("%lld %f", &sekunde, &kolicina);
		if (sekunde > 98888)
		{
			break;
		}
		else if (sekunde != 0)
		{
			sati = (float)sekunde / 3600;
			if (sati >= (int)sati)
			{
				sati++;
			}
			sekunde = (int)sati;
		}
		else if (sekunde == 0)
		{
			sekunde = 1;
		}
		if (sekunde > 24)
		{
			break;
		}
		//printf("\n");
		//printf("SAT: %d\n", sekunde);
		if (sekunde != prethodnisat)
		{
			prethodnisat = sekunde;
			nizrazlicitihsati[brojacrazlicitihsati] = sekunde;
			//printf("NADEN NOVI SAT: %lld\n", nizrazlicitihsati[brojacrazlicitihsati]);
			brojacrazlicitihsati++;
		}
		nizsekunda[sekunde] += kolicina;
		nizsekundabrojac[sekunde]++;
		//printf("\n");
	}
	//printf("\n");
	//printf("\n");
	//printf("BROJ RAZLICITIH SATI: %d\n", brojacrazlicitihsati);
	//printf("\n");
	for (i = 0; i < brojacrazlicitihsati; i++)
	{
		if (nizsekunda[nizrazlicitihsati[i]] != 0 || nizsekundabrojac[nizrazlicitihsati[i]] != 0)
		{
			ukupnakolicina[nizrazlicitihsati[i]] = round(nizsekunda[nizrazlicitihsati[i]] / nizsekundabrojac[nizrazlicitihsati[i]]);
			//printf("%f = %f / %f\n", ukupnakolicina[nizrazlicitihsati[i]], nizsekunda[nizrazlicitihsati[i]], nizsekundabrojac[nizrazlicitihsati[i]]);
			if (ukupnakolicina[nizrazlicitihsati[i]] > maxkolicina)
			{
				maxkolicina = ukupnakolicina[nizrazlicitihsati[i]];
			}
		}
	}
	//for (i = 0; i < brojacrazlicitihsati; i++)
	//{
	//	printf("%lld %f\n", nizrazlicitihsati[i], ukupnakolicina[nizrazlicitihsati[i]]);
	//}
	//printf("\n");
	for (i = 0; i < brojacrazlicitihsati-1; i++)
	{
		for(j = 0; j < brojacrazlicitihsati-i-1; j++)
		{
			if (nizrazlicitihsati[j] > nizrazlicitihsati[j + 1])
			{
				tempsat = nizrazlicitihsati[j];
				nizrazlicitihsati[j] = nizrazlicitihsati[j+1];
				nizrazlicitihsati[j+1] = tempsat;
				//tempkolicina = ukupnakolicina[nizrazlicitihsati[j]];
				//ukupnakolicina[nizrazlicitihsati[j]] = ukupnakolicina[nizrazlicitihsati[j+1]];
				//ukupnakolicina[nizrazlicitihsati[j + 1]] = tempkolicina;
			}
		}
	}
	for (i = 0; i < maxkolicina + 1; i++)
	{
		if (nizrazlicitihsati[i] != i+1)
		{
			nizrazlicitihsati[i] = i+1;
		}
	}
	//printf("MAXKOLICINA %f\n", maxkolicina+1);
	//for (i = 0; i < brojacrazlicitihsati; i++)
	//{
	//	printf("%lld %f\n", nizrazlicitihsati[i], ukupnakolicina[nizrazlicitihsati[i]]);
	//}
	//printf("\n");
	for (i = maxkolicina + 1; i > 0; i--)
	{
		if (i > 9)
		{
			printf("%d ", i);
		}
		else
		{
			printf(" %d ", i);
		}
		for (j = 0; j <= maxkolicina+1+brojacrazlicitihsati; j++)
		{
			if (i <= ukupnakolicina[nizrazlicitihsati[j]])
			{
				printf("x");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

