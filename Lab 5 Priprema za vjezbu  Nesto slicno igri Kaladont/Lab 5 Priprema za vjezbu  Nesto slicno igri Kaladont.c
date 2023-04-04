#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

void ispispobjednika(char* gubitnici[10], char* igraci[10], int i)
{
	int j;
	printf("\n");
	for (j = 1; j <= i; j++)
	{
		//printf("%d", gubitnici[j]);
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

//int testponavljanja1(char* nizunosa[30], char* igraci[10], int i, int j, char* ponavljanjetest)
//{
//	int k = 0;
//	char testunosa[30] = { 0 };
//	int brojacponavljanja = 0;
//	int ponavljaci[10] = { 0 };
//	int rednibroj = 0;
//	char prva2slova[2 + 1] = { 0 };
//	int brojacispisa = 0;
//	strcpy(testunosa, ponavljanjetest + 2);
//	//printf("prvi unos: %s\n", testunosa);
//	for (k = 1; k <= j; k++)
//	{
//		if (strcmp(testunosa, nizunosa[k] + 2) == 0 && strcmp(testunosa, "Ne znam"))
//		{
//			//printf("PONAVLJANJE\n");
//			//printf("prvi unos: %s\n", testunosa);
//			brojacponavljanja++;
//			strncpy(prva2slova, nizunosa[k], 2);
//			rednibroj = (int)*prva2slova - 48;
//			ponavljaci[rednibroj] = 1;
//		}
//		else
//		{
//			strcpy(testunosa, nizunosa[k] + 2);
//		}
//	}
//	printf("Igraci ");
//	for (k = 1; k <= i; k++)
//	{
//		if (ponavljaci[k] == 1 && brojacispisa == 0)
//		{
//			printf("%s", igraci[k]);
//			brojacispisa++;
//		}
//		else if (ponavljaci[k] == 1 && brojacispisa != 0)
//		{
//			printf(" && %s", igraci[k]);
//		}
//	}
//	printf(" poslali su istu rijec. Unesite nove rijeci.\n");
//	return brojacponavljanja;
//}
//
//int testponavljanja(char* nizunosa[30], char* igraci[10], int i, int j)
//{
//	int k = 0;
//	char testunosa[30] = { 0 };
//	int brojacponavljanja = 0;
//	int ponavljaci[10] = { 0 };
//	int rednibroj = 0;
//	char prva2slova[2 + 1] = { 0 };
//	int brojacispisa = 0;
//	strcpy(testunosa, nizunosa[1] + 2);
//	//printf("prvi unos: %s\n", testunosa);
//	for (k = 1; k <= j; k++)
//	{
//		if (strcmp(testunosa, nizunosa[k] + 2) == 0 && strcmp(testunosa, "Ne znam"))
//		{
//			//printf("PONAVLJANJE\n");
//			//printf("prvi unos: %s\n", testunosa);
//			brojacponavljanja++;
//			if (brojacponavljanja > 1)
//			{
//				strncpy(prva2slova, nizunosa[k - 1], 2);
//				rednibroj = (int)*prva2slova - 48;
//				ponavljaci[rednibroj] = 1;
//				strncpy(prva2slova, nizunosa[k], 2);
//				rednibroj = (int)*prva2slova - 48;
//				ponavljaci[rednibroj] = 1;
//			}
//		}
//		else
//		{
//			strcpy(testunosa, nizunosa[k] + 2);
//		}
//	}
//	if (brojacponavljanja > 1)
//	{
//		printf("Igraci ");
//		for (k = 1; k <= i; k++)
//		{
//			if (ponavljaci[k] == 1 && brojacispisa == 0)
//			{
//				printf("%s", igraci[k]);
//				brojacispisa++;
//			}
//			else if (ponavljaci[k] == 1 && brojacispisa != 0)
//			{
//				printf(" && %s", igraci[k]);
//			}
//		}
//		printf(" poslali su istu rijec. Unesite nove rijeci.\n");
//	}
//	else
//	{
//		brojacponavljanja = 0;
//	}
//	return brojacponavljanja;
//}

void ispis2slova(char zadnja2slova[2 + 1], int j)
{
	char* s = zadnja2slova;
	//char* t = zadnja2slova;
	while (*s) {
		*s = toupper((unsigned char)*s);
		s++;
	}
	printf("Za %d. krug zadan je skup slova %s.\n", j, zadnja2slova);

	/*while (*t) {
		*t = tolower((unsigned char)*t);
		t++;
	}*/
	//printf("Za %d. krug UMANJENI skup slova %s.\n", j, zadnja2slova);
	return;
}

int testpocetka(int i, char* igraci[10], char zadnja2slova[2 + 1])
{
	int p = i;
	strcpy(zadnja2slova, igraci[p] + (strlen(igraci[p]) - 2));
	while (((*zadnja2slova + 1) <= 57 && (*zadnja2slova + 1) >= 48) || ((*zadnja2slova) <= 57 && (*zadnja2slova) >= 48))
	{
		p--;
		strcpy(zadnja2slova, igraci[p] + (strlen(igraci[p]) - 2));
	}
	return p;
}

void ispisigraca(int i, char* igraci[10])
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
	int i = 0, p = 0, j = 0, k = 0, pocetak = 0, brojacneznam = 0;
	char unos[256] = { 0 };
	char test[256] = { 0 };
	char prethodniunos[256] = { 0 };
	char** igraci;
	igraci = (char**)malloc(sizeof(char*) * 2);
	char** nizunosa;
	nizunosa = (char**)malloc(sizeof(char*)*2);
	char zadnja2slova[2 + 1] = { 0 };
	char prva2slova[2 + 1] = { 0 };
	int* gubitnici;
	int rednibroj = 0;

	int brojunosa = 0;
	int kolikounosa = 0;
	int brojkrugova = 1;
	int kolikomanje = 0;

	char testunosa[256] = { 0 };
	int brojacponavljanja = 0;
	int* ponavljaci;
	int brojacispisa = 0;

	int y = 0, x = 0;
	int extraunosiodponavljanja = 0;
	char ponavljanjetest[256] = { 0 };
	char test1[256] = { 0 };
	char test2[256] = { 0 };
	char test3[2 + 1] = { 0 };
	char test4[2 + 1] = { 0 };
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
			igraci[i] = (char*)malloc((sizeof(char) * 256));
			strcpy(igraci[i], unos);
			igraci = (char**)realloc(igraci, sizeof(char*) * (i + 2));
		}
	}
	gubitnici = (int*)calloc(i+1, sizeof(int));
	ponavljaci = (int*)calloc(i+1, sizeof(int));
	ispisigraca(i, igraci);
	pocetak = testpocetka(i, igraci, zadnja2slova);
	strcpy(zadnja2slova, igraci[pocetak] + (strlen(igraci[pocetak]) - 2));
	j = 1;
	kolikounosa = i;
	ispis2slova(zadnja2slova, j);
	j = 0;
	while (p < i)
	{
		scanf("%[^\n]%*c", unos);
		//printf("rijec: %s\n", unos);
		strcpy(test, unos + 2);
		//printf("|%s|\n", test);
		strncpy(prva2slova, unos, 2);
		//printf("prva 2 slova: %s\n", prva2slova);
		brojunosa++;
		j++;
		nizunosa[j] = (char*)malloc(sizeof(char) * 256);
		nizunosa = (char**)realloc(nizunosa, sizeof(char*) * (j+2));
		strcpy(nizunosa[j], unos);
		if (strcmp(test, "Ne znam") == 0)
		{
			kolikomanje++;
			p++;
			brojacneznam++;
			if (brojacneznam + 1 == i)
			{
				strncpy(prva2slova, prethodniunos, 2);
				rednibroj = (int)*prva2slova - 48;
				gubitnici[rednibroj] = 0;
				//printf("igrac koji je uspija %d\n", rednibroj);
				for (k = 1; k <= i; k++)
				{
					if (k != rednibroj)
					{
						gubitnici[k] = 1;
					}
				}
			}
			else
			{
				if (p < i)
				{
					rednibroj = (int)*prva2slova - 48;
					//printf("igrac koji je popusio %d\n", rednibroj);
					gubitnici[rednibroj] = 1;
				}
			}
		}
		else
		{
			brojacneznam = 0;
			strcpy(prethodniunos, unos);
		}
		if (brojunosa == kolikounosa && brojacneznam != kolikounosa - 1 && brojacneznam != kolikounosa)
		{
			brojkrugova++;

			/*for (x = 1; x <= j; x++)
			{
				printf("%s\n", nizunosa[x]);
			}
			printf("\n");*/

			if (strcmp(strcpy(test1, nizunosa[1] + 2), strcpy(test2, ponavljanjetest + 2)) == 0 && strcmp(strncpy(test3, nizunosa[1], 2), strncpy(test4, ponavljanjetest, 2)) != 0 && y == 1)
			{
				k = 0;
				brojacponavljanja = 0;
				brojacispisa = 0;
				strcpy(testunosa, ponavljanjetest + 2);
				
				//printf("prvi unos: %s\n", testunosa);
				for (k = 1; k <= j; k++)
				{
					if (strcmp(testunosa, nizunosa[k] + 2) == 0 && strcmp(testunosa, "Ne znam")!=0)
					{
						//printf("PONAVLJANJE\n");
						//printf("prvi unos: %s\n", testunosa);
						brojacponavljanja++;
						strncpy(prva2slova, nizunosa[k], 2);
						rednibroj = (int)*prva2slova - 48;
						ponavljaci[rednibroj] = 1;
					}
					else
					{
						strcpy(testunosa, nizunosa[k] + 2);
					}
				}
				printf("Igraci ");
				for (k = 1; k <= i; k++)
				{
					if (ponavljaci[k] == 1 && brojacispisa == 0)
					{
						printf("%s", igraci[k]);
						brojacispisa++;
					}
					else if (ponavljaci[k] == 1 && brojacispisa != 0)
					{
						printf(" && %s", igraci[k]);
					}
				}
				printf(" poslali su istu rijec. Unesite nove rijeci.\n");
				extraunosiodponavljanja = brojacponavljanja;
				for (k = 0; k < i+1; k++)
				{
					ponavljaci[k] = 0;
				}
			}
			else
			{
				brojacponavljanja = 0;
				brojacispisa = 0;
				
				strcpy(testunosa, nizunosa[1] + 2);
				//printf("prvi unos: %s\n", testunosa);
				for (k = 1; k <= j; k++)
				{
					if (strcmp(testunosa, nizunosa[k] + 2) == 0 && strcmp(testunosa, "Ne znam")!=0)
					{
						//printf("PONAVLJANJE\n");
						//printf("prvi unos: %s\n", testunosa);
						brojacponavljanja++;
						if (brojacponavljanja > 1)
						{
							strncpy(prva2slova, nizunosa[k - 1], 2);
							rednibroj = (int)*prva2slova - 48;
							ponavljaci[rednibroj] = 1;
							//printf("%s", prva2slova);
							strncpy(prva2slova, nizunosa[k], 2);
							rednibroj = (int)*prva2slova - 48;
							ponavljaci[rednibroj] = 1;
							//printf("%s", prva2slova);
						}
					}
					else
					{
						strcpy(testunosa, nizunosa[k] + 2);
					}
				}
				if (brojacponavljanja > 1)
				{
					printf("Igraci ");
					for (k = 1; k <= i; k++)
					{
						if (ponavljaci[k] == 1 && brojacispisa != 0)
						{
							printf(" && %s", igraci[k]);
						}
						else if (ponavljaci[k] == 1 && brojacispisa == 0)
						{
							printf("%s", igraci[k]);
							brojacispisa++;
						}
					}
					printf(" poslali su istu rijec. Unesite nove rijeci.\n");
				}
				else
				{
					brojacponavljanja = 0;
				}
				extraunosiodponavljanja = brojacponavljanja;
				for (k = 0; k < i+1; k++)
				{
					ponavljaci[k] = 0;
				}
			}
			if (extraunosiodponavljanja == 0)
			{
				//printf("PRETHODNI UNOS: %s\n", prethodniunos);
				strcpy(zadnja2slova, prethodniunos + (strlen(prethodniunos) - 2));
				ispis2slova(zadnja2slova, brojkrugova);
				kolikounosa -= kolikomanje;
				kolikomanje = 0;
				brojunosa = 0;
				y = 0;
			}
			else
			{
				brojunosa -= extraunosiodponavljanja;
				brojkrugova--;
				y++;
				strcpy(ponavljanjetest, nizunosa[1]);
			}
			j = 0;
		}
	}
	ispispobjednika(gubitnici, igraci, i);
	return 0;
}