#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

void ispispobjednika(char* gubitnici[1000], char* igraci[1000], int i)
{
	int j;
	for (j = 1; j <= i; j++)
	{
		if (gubitnici[j] == 0)
		{
			char* s = igraci[j];
			while (*s) {
				*s = toupper((unsigned char)*s);
				s++;
			}
			printf("Pobjednik je: %s\n", igraci[j]);
		}
	}
	return;
}

void ispis2slova(char zadnja2slova[2], int j)
{
	char* s = zadnja2slova;
	while (*s) {
		*s = toupper((unsigned char)*s);
		s++;
	}
	printf("%d. zadani skup slova je %s.\n", j, zadnja2slova);
	return;
}

void ispisigraca(int i, char* igraci[100])
{
	int j = 0;
	printf("Igru igraju:\n");
	for (j = 1; j <= i; j++)
	{
		printf("%d#%s\n", j, igraci[j]);
	}
	printf("\n");
	return;
}

int main()
{
	int i=0, p=0, j=0;
	char unos[30 + 1] = { 0 };
	char test[30 + 1] = { 0 };
	char* igraci[1000] = { 0 };
	char zadnja2slova[2+1] = { 0 };
	char prva2slova[2+1] = { 0 };
	int gubitnici[1000] = { 0 };
	int rednibroj = 0;
	while (1)
	{
		//scanf("%s", unos);
		scanf("%[^\n]%*c", unos);
		//printf("|%s|\n", unos);
		if ((strcmp(unos, "KRAJ") == 0))
		{
			if (i > 1)
			{
				break;
			}
			else
			{
				printf("U igri moraju sudjelovati minimalno 2 igraca. Unesite jos igraca.\n");
				continue;
			}
		}
		else
		{
			i++;
			igraci[i] = (char*)calloc((strlen(unos)+2), sizeof(char));
			strcpy(igraci[i], unos);
		}
	}
	ispisigraca(i, igraci);
	strcpy(zadnja2slova, igraci[i] + (strlen(igraci[i]) - 2));
	j = 1;
	ispis2slova(zadnja2slova, j);
	while (p < i)
	{
		scanf("%[^\n]%*c", unos);
		//printf("rijec: %s\n", unos);
		strcpy(test, unos + 2);
		//printf("|%s|\n", test);
		strncpy(prva2slova, unos, 2);
		//printf("prva 2 slova: %s\n", prva2slova);
		if (strcmp(test, "Ne znam") == 0)
		{
			p++;
			if (p < i)
			{
				rednibroj = (int)*prva2slova - 48;
				//printf("igrac koji je popusio %d\n", rednibroj);
				gubitnici[rednibroj] = 1;
			}
		}
		else
		{
		strcpy(zadnja2slova, unos + (strlen(unos) - 2));
		j++;
		ispis2slova(zadnja2slova, j);
		}
	}
	ispispobjednika(gubitnici, igraci, i);
	return 0;
}