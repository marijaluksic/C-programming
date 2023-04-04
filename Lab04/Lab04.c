#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int test(char** tetris, int redak, int stupac)
{
	int i, j;
	int lokacija1=0, lokacija2=0, lokacija3=0, lokacija4=0;
	int prazno1 = 0, prazno2 = 0, prazno3 = 0, prazno4 = 0;
	int brojac = 0, brojactockica=0, brojachash=0;
	int pocetnadubina = 0, krajnjadubina=0;
	int rezultat = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < stupac; j++)
		{
			if (tetris[i][j] != '.' && brojac == 0)
			{
				lokacija1 = j;
				tetris[i][j] = '.';
				brojac++;
			}
			if (tetris[i][j] != '.' && brojac == 1)
			{
				lokacija2 = j;
				tetris[i][j] = '.';
				brojac++;
			}
			if (tetris[i][j] != '.' && brojac == 2)
			{
				lokacija3 = j;
				tetris[i][j] = '.';
				brojac++;
			}
			if (tetris[i][j] != '.' && brojac == 3)
			{
				lokacija4 = j;
				tetris[i][j] = '.';
				brojac++;
			}
		}
	}
	brojac = 0;
	for (i = redak - 1; i >= 2; i--)
	{
		brojactockica = 0;
		brojachash = 0;
		for (j = lokacija1 - 1; j <= lokacija4 + 1; j++)
		{
			if (tetris[i][lokacija3] == '.' && tetris[i][lokacija4]=='.')
			{
				brojactockica++;
			}
			if (tetris[i-1][lokacija1] == '.' && tetris[i-1][lokacija2]=='.')
			{
				brojachash++;
			}
		}
		if (brojactockica > 0 && brojachash > 0)
		{
			rezultat = 1;
			tetris[i][lokacija3] = '#';
			tetris[i][lokacija4] = '#';
			tetris[i-1][lokacija1] = '#';
			tetris[i-1][lokacija2] = '#';
			break;
		}
		//if (brojac == 0 && brojactockica == 0)
		//{
		//	pocetnadubina = i;
		//	brojac++;
		//}
		//if (brojac != 0 && brojachash < 2)
		//{
		//	krajnjadubina = i;
		//}
	}
	brojactockica = 0;
	brojac = 0;
	for (i = redak-1; i >=2; i--)
	{
		brojactockica = 0;
		brojachash = 0;
		for (j = lokacija1 - 1; j <= lokacija4 + 1; j++)
		{
			if (tetris[i][j] == '.')
			{
				brojactockica++;
			}
			if (brojac!=0 && tetris[i][j] == '#')
			{
				brojachash++;
			}
		}
		if (brojactockica > 0)
		{
			brojac++;
		}
		if (brojac != 0 && brojachash > 2)
		{

			rezultat = 0;
		}
	}
	/*for (i = 0; i < redak; i++)
	{
		for (j = 0; j < stupac; j++)
		{
			if (tetris[pocetnadubina][lokacija3] == '.')
			{
				tetris[pocetnadubina][lokacija3] = '#';
				if (tetris[pocetnadubina][lokacija4] == '.')
				{
					tetris[pocetnadubina][lokacija4] = '#';
					if (tetris[krajnjadubina + 1][lokacija1] == '.')
					{
						tetris[krajnjadubina + 1][lokacija1] = '#';
						if (tetris[krajnjadubina + 1][lokacija2] == '.')
						{
							tetris[krajnjadubina + 1][lokacija2] = '#';
							rezultat = 1;
						}
						else if (tetris[krajnjadubina + 1][lokacija1] == '#')
						{
							tetris[krajnjadubina][lokacija3] = '#';
							tetris[krajnjadubina][lokacija4] = '#';
							tetris[krajnjadubina - 1][lokacija1] = '#';
							tetris[krajnjadubina - 1][lokacija2] = '#';
						}
					}
					else if (tetris[krajnjadubina + 1][lokacija1] == '#')
					{
						tetris[krajnjadubina][lokacija3] = '#';
						tetris[krajnjadubina][lokacija4] = '#';
						tetris[krajnjadubina - 1][lokacija1] = '#';
						tetris[krajnjadubina - 1][lokacija2] = '#';
					}
				}
				else if (tetris[pocetnadubina][lokacija4] == '#')
				{
					tetris[krajnjadubina][lokacija3] = '#';
					tetris[krajnjadubina][lokacija4] = '#';
					tetris[krajnjadubina - 1][lokacija1] = '#';
					tetris[krajnjadubina - 1][lokacija2] = '#';
				}
			}
			else if (tetris[pocetnadubina][lokacija3] == '#')
			{
				tetris[krajnjadubina][lokacija3] = '#';
				tetris[krajnjadubina][lokacija4] = '#';
				tetris[krajnjadubina - 1][lokacija1] = '#';
				tetris[krajnjadubina - 1][lokacija2] = '#';
			}
		}
	}*/
	return rezultat;
}

void ispismatrice(char** tetris, int redak, int stupac, int uspjesnost)
{
	int i, j;
	printf("\n");
	for (i = 0; i < redak; i++)
	{
		for (j = 0; j < stupac; j++)
		{
			printf("%c", tetris[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	if (uspjesnost == 1)
	{
		printf("Uspjesno spustanje!\n");
	}
	else if (uspjesnost == 0)
	{
		printf("Neuspjesno spustanje!\n");
	}
	return;
}

int main()
{
	char** tetris;
	int redak, stupac, i, j, uspjesnost=0;
	scanf("%d %d", &redak, &stupac);
	tetris = (char**)calloc(redak, sizeof(char*));
	for (i = 0; i < redak; i++)
	{
		tetris[i] = (char*)calloc(stupac, sizeof(char));
	}
	for (i = 0; i < redak; i++)
	{
		for (j = 0; j < stupac; j++)
		{
			scanf(" %c", &tetris[i][j]);
		}
	}
	uspjesnost = test(tetris, redak, stupac);
	ispismatrice(tetris, redak, stupac, uspjesnost);
	for (i = 0; i < redak; i++)
	{
		free(tetris[i]);
	}
	free(tetris);
	return 0;
}