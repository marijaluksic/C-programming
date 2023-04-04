#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include<string.h>

char* najduljiPodniz(char** polje, int i)
{
	int j = 0, p=0, brojac1=0, brojac2 = 0, brojac3=0, brojac4 = 0, k=0, x=0;
	int minduljina = 1000;
	int najkraci = 0;
	int max1 = 0, max2 = 0;
	char* ispis;
	char* noviniz;
	ispis = (char*)malloc(sizeof(char)*1000);
	noviniz = (char*)malloc(sizeof(char)*1000);
	for (j = 0; j < i; j++)
	{
		if (strlen(polje[j]) < minduljina)
		{
			minduljina = strlen(polje[j]);
			najkraci = j;
		}
	}
	p = strlen(polje[najkraci]);
	printf("%d\n", p);
	noviniz = strstr(polje[0], polje[1]);
	printf("%s\n", noviniz, noviniz - polje[0]);
	
	while (k<p)
	{
		for (j = 0; j < i; j++)
		{
			if (j!=najkraci)
			{
				if (x == 0)
				{
					printf("%s %s  %d\n", polje[j] + max1, polje[najkraci]+k, max1);
					brojac1 = strcspn(polje[j] + max1, polje[najkraci]+k);
					brojac3 = strspn(polje[j] + brojac1, polje[najkraci]+k);
					printf("OD %d DO %d\n", brojac1, brojac3+brojac1);
					x++;
				}
				else
				{
					printf("%s %s  %d\n", polje[j] + max2, polje[najkraci] + k, max2);
					brojac2 = strcspn(polje[j] + max2, polje[najkraci] + k);
					brojac4 = strspn(polje[j] + brojac1, polje[najkraci]+k);
					printf("OD %d DO %d\n", brojac2, brojac2 + brojac4);
					x++;
				}
				//if (noviniz != NULL);
				//{
				//		/*ispis = (char*)realloc(ispis, sizeof(char)* (strlen(noviniz)+1));
				//		strcpy(ispis, noviniz);*/
				//	printf("%s %d", noviniz, noviniz - polje[najkraci]);
				//}
			}
			printf("\n");
		}
		printf("KRUG GOTOV\n");
		max1 += brojac1;
		max2 += brojac2;
		brojac1 = 0;
		brojac2 = 0;
		x = 0;
		k++;
	}
	//printf("%d %s", najkraci, polje[najkraci]);
	ispis = (char*)realloc(ispis, sizeof(char) * strlen(polje[najkraci]));
	strcpy(ispis, polje[najkraci]);
	return ispis;
}

int main()
{
	int i=1, j=0;
	char** polje;
	char unos[1000] = { 0 };
	char delimiters[] = "!#";
	char* result=NULL;
	char* noviniz=NULL;
	polje = (char**)malloc(sizeof(char*));
	scanf("%[A-Za-z0-9#!]%*c", unos);
	//printf("%s", unos+2);
	result= strtok(unos, delimiters);
	polje[0] = (char*)malloc(sizeof(char) * (strlen(result) + 1));
	strcpy(polje[0], result);
	while (result!=NULL)
	{
		//polje[i] = strtok(NULL, delimiters);
		result = strtok(NULL, delimiters);
		if(result !=NULL)
		{
			polje = realloc(polje, sizeof(char*) * (i + 1));
			polje[i] = (char*)malloc(sizeof(char) * strlen(result));
			strcpy(polje[i], result);
			i++;
		}
	}
	printf("\n\n%s\n", najduljiPodniz(polje, i));
	//printf("NOVI NIZ %s\n", noviniz);
	/*for (j = 0; j < i; j++)
	{
		
			printf("|%s|\n", polje[j]);
		
	}*/
	return 0;
}