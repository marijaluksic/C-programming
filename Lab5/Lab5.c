#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

char** nadjiRijeci(char** tekst, int n, char c)
{
	int i = 0, j=0;
	char** noviniz;
	noviniz = (char**)malloc(sizeof(char*));
	//for (i = 0; i < n; i++)
	//{
		if (strchr(tekst[n], c) != NULL)
		{
			noviniz = (char**)realloc(noviniz, sizeof(char*) * (j + 2));
			noviniz[j] = (char*)malloc(sizeof(char*) * 1000);
			strcpy(noviniz[j], tekst[n]);
			//printf("%s\n", noviniz[j]);
		}
		else
		{
			noviniz = NULL;
		}
	//}
	return noviniz;
}
int main()
{
	int i = 0, j=0, brojslova=0, k=0;
	char** tekst;
	char unos[256] = { 0 };
	char c;
	tekst= (char**)malloc(sizeof(char*));
	while (1)
	{
		tekst =(char**)realloc(tekst, sizeof(char*) * (i+2));
		scanf("%s ", unos);
		if (strcmp(unos, "KRAJ") == 0)
		{
			break;
		}
		else
		{
			tekst[i] = (char*)malloc(sizeof(char) * 100000);
			strcpy(tekst[i], unos);
			i++;
		}
	}
	scanf("%d", &brojslova);
	for (k = 0; k < brojslova; k++)
	{
		scanf(" %c", &c);
		printf("Rijeci koje sadrze slovo %c:\n", c);
		for (j = 0; j < i; j++)
		{
			if (nadjiRijeci(tekst, j, c) != NULL)
			{

				printf("%s\n", tekst[j]);
			}
		}
	}
	/*printf("%d\n", i);
	for (j = 0; j < i; j++)
	{

		printf("|%s|\n", tekst[j]);

	}*/
	return 0;
}