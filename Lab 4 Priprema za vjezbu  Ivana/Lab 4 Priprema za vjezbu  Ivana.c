#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

void ispismatrice(char** more, int redak, int stupac, int brojpregleda)
{
	int i, j;
	for (i = 0; i < redak; i++)
	{
		for (j = 0; j < stupac; j++)
		{
			printf("%c", more[i][j]);
		}
		printf("\n");
	}
	printf("Ukupno pregledano: %d lokacija.\n", brojpregleda);
	return;
}
int situacija2(int redak, int stupac, int** poljezbrojeva, char** more, int red)
{
	int i, j, maxzbroj = 0, k = 0, l = 0, indexredak = 0, indexstupac = 0, uu = 0, ll = 0, rr = 0, dd = 0, pregledanihlokacija = 0;
	k = redak * stupac;
	if (k >= 27)
	{
		k = 3;
	}
	else if (k < 27 && k >= 18)
	{
		k = 2;
	}
	else if (k < 18 && k >= 9)
	{
		k = 1;
	}
	while (l < k+red)
	{
		for (i = redak - 1; i >= 0; i--)
		{
			for (j = stupac - 1; j >= 0; j--)
			{
				if (poljezbrojeva[i][j] > maxzbroj)
				{
					maxzbroj = poljezbrojeva[i][j];
					indexredak = i;
					indexstupac = j;
				}
			}
		}
		//printf("MAXZBROJ = %d\n", maxzbroj);
		if ((k+red)-l <=3)
		{
			pregledanihlokacija += maxzbroj;
			poljezbrojeva[indexredak][indexstupac] = 0;
			uu = 0;
			ll = 0;
			rr = 0;
			dd = 0;
			if (indexredak - 1 >= 0)
			{
				uu++;
				if (indexredak - 2 >= 0)
				{
					uu++;
				}
			}
			if (indexredak + 1 <= redak - 1)
			{
				dd++;
				if (indexredak + 2 <= redak - 1)
				{
					dd++;
				}
			}
			if (indexstupac - 1 >= 0)
			{
				ll++;
				if (indexstupac - 2 >= 0)
				{
					ll++;
				}
			}
			if (indexstupac + 1 <= stupac - 1)
			{
				rr++;
				if (indexstupac + 2 <= stupac - 1)
				{
					rr++;
				}
			}
			for (i = (indexredak - uu); i <= (indexredak + dd); i++)
			{
				for (j = (indexstupac - ll); j <= (indexstupac + rr); j++)
				{
					poljezbrojeva[i][j] = 0;
				}
			}
			more[indexredak][indexstupac] = 'D';
		}
		maxzbroj = 0;
		l++;
		//printf("%d[%d][ %d]\n", poljezbrojeva[indexredak][indexstupac], indexredak + 1, indexstupac + 1);
	}
	return pregledanihlokacija;
}
int situacija1(int redak, int stupac, int** poljezbrojeva, char** more, int red)
{
	int i, j, brojac = 0, maxzbroj = 0, k = 0, l = 0, indexredak = 0, indexstupac = 0, uu = 0, ll = 0, rr = 0, dd = 0, pregledanihlokacija = 0;
	k = redak * stupac;
	if (k >= 27)
	{
		k = 3;
	}
	else if (k < 27 && k >= 18)
	{
		k = 2;
	}
	else if (k < 18 && k >= 9)
	{
		k = 1;
	}
	while (l < k + red)
	{
		for (i = 0; i < redak; i++)
		{
			for (j = 0; j < stupac; j++)
			{
				if (poljezbrojeva[i][j] > maxzbroj)
				{
					maxzbroj = poljezbrojeva[i][j];
					indexredak = i;
					indexstupac = j;
				}
			}
		}
		if ((k+red)-l <= 3)
		{
			pregledanihlokacija += maxzbroj;
			poljezbrojeva[indexredak][indexstupac] = 0;
			uu = 0;
			ll = 0;
			rr = 0;
			dd = 0;
			if (indexredak - 1 >= 0)
			{
				uu++;
				if (indexredak - 2 >= 0)
				{
					uu++;
					//printf("indexredak - 2 >= 0\n");
				}
			}
			if (indexredak + 1 <= redak - 1)
			{
				dd++;
				if (indexredak + 2 <= redak - 1)
				{
					dd++;
				}
			}
			if (indexstupac - 1 >= 0)
			{
				ll++;
				if (indexstupac - 2 >= 0)
				{
					ll++;
				}
			}
			if (indexstupac + 1 <= stupac - 1)
			{
				rr++;
				if (indexstupac + 2 <= stupac - 1)
				{
					rr++;
				}
			}
			for (i = (indexredak - uu); i <= (indexredak + dd); i++)
			{
				for (j = (indexstupac - ll); j <= (indexstupac + rr); j++)
				{
					poljezbrojeva[i][j] = 0;
				}
			}
			more[indexredak][indexstupac] = 'D';
		}
		maxzbroj = 0;
		l++;
		//printf("%d[%d][ %d]\n", poljezbrojeva[indexredak][indexstupac], indexredak + 1, indexstupac + 1);
	}
	return pregledanihlokacija;
}

int test2(int redak, int stupac, int** testpolje2, int red)
{
	int i, j, test = 0, maxzbroj = 0, k = 0, l = 0, indexredak = 0, indexstupac = 0, uu = 0, ll = 0, rr = 0, dd = 0, pregledanihlokacija = 0;
	int probnopolje[MAX][MAX] = { {0}, {0} };
	for (i = 0; i < redak; i++)
	{
		for (j = 0; j <stupac; j++)
		{
			probnopolje[i][j] = testpolje2[i][j];
		}
	}
	k = redak * stupac;
	if (k >= 27)
	{
		k = 3;
	}
	else if (k < 27 && k >= 18)
	{
		k = 2;
	}
	else if (k < 18 && k >= 9)
	{
		k = 1;
	}
	printf("k+red= %d l= %d\n", k + red, l);
	while (l < k+red)
	{
		for (i = redak - 1; i >= 0; i--)
		{
			for (j = stupac - 1; j >= 0; j--)
			{
				if (probnopolje[i][j] > test)
				{
					test = probnopolje[i][j];
					if ((k + red - l) <= 3)
					{
						maxzbroj = probnopolje[i][j];
						indexredak = i;
						indexstupac = j;
					}
				}
			}
		}
		
		//printf("MAXZBROJ = %d\n", maxzbroj);
	
		if ((k+red - l )<= 3)
		{

			printf("MAXZBROJ = %d\n", maxzbroj);
			pregledanihlokacija += maxzbroj;
			probnopolje[indexredak][indexstupac] = 0;
			if (l < k + red)
			{

				uu = 0;
				ll = 0;
				rr = 0;
				dd = 0;
				if (indexredak - 1 >= 0)
				{
					uu++;
					if (indexredak - 2 >= 0)
					{
						uu++;
					}
				}
				if (indexredak + 1 <= redak - 1)
				{
					dd++;
					if (indexredak + 2 <= redak - 1)
					{
						dd++;
					}
				}
				if (indexstupac - 1 >= 0)
				{
					ll++;
					if (indexstupac - 2 >= 0)
					{
						ll++;
					}
				}
				if (indexstupac + 1 <= stupac - 1)
				{
					rr++;
					if (indexstupac + 2 <= stupac - 1)
					{
						rr++;
					}
				}
				for (i = (indexredak - uu); i <= (indexredak + dd); i++)
				{
					for (j = (indexstupac - ll); j <= (indexstupac + rr); j++)
					{
						probnopolje[i][j] = 0;
					}
				}
			}
		}
		test = 0;
		l++;
		//printf("%d[%d][ %d]\n", poljezbrojeva[indexredak][indexstupac], indexredak + 1, indexstupac + 1);
	}
	return pregledanihlokacija;
}

int test1(int redak, int stupac, int** testpolje1, int red)
{
	int i, j, maxzbroj = 0, k = 0, l = 0, indexredak = 0, indexstupac = 0, uu = 0, ll = 0, rr = 0, dd = 0, pregledanihlokacija = 0;
	int probnopolje[MAX][MAX] = { {0}, {0} };
	for (i = 0; i < redak; i++)
	{
		for (j = 0; j < stupac; j++)
		{
			probnopolje[i][j] = testpolje1[i][j];
		}
	}
	k = redak * stupac;
	if (k >= 27)
	{
		k = 3;
	}
	else if (k < 27 && k >= 18)
	{
		k = 2;
	}
	else if (k < 18 && k >= 9)
	{
		k = 1;
	}
	while (l < k+red)
	{
		for (i = 0; i < redak; i++)
		{
			for (j = 0; j < stupac; j++)
			{
				if (probnopolje[i][j] > maxzbroj)
				{
					maxzbroj = probnopolje[i][j];
					indexredak = i;
					indexstupac = j;
				}
			}
		}
		if ((k + red) - l <= 3)
		{
			pregledanihlokacija += maxzbroj;
			//printf("MAXZBROJ = %d\n", maxzbroj);
			
			if (l < k+red)
			{
				probnopolje[indexredak][indexstupac] = 0;
				uu = 0;
				ll = 0;
				rr = 0;
				dd = 0;
				if (indexredak - 1 >= 0)
				{
					uu++;
					if (indexredak - 2 >= 0)
					{
						uu++;
						//printf("indexredak - 2 >= 0\n");
					}
				}
				if (indexredak + 1 <= redak - 1)
				{
					dd++;
					if (indexredak + 2 <= redak - 1)
					{
						dd++;
					}
				}
				if (indexstupac - 1 >= 0)
				{
					ll++;
					if (indexstupac - 2 >= 0)
					{
						ll++;
					}
				}
				if (indexstupac + 1 <= stupac - 1)
				{
					rr++;
					if (indexstupac + 2 <= stupac - 1)
					{
						rr++;
					}
				}
				for (i = (indexredak - uu); i <= (indexredak + dd); i++)
				{
					for (j = (indexstupac - ll); j <= (indexstupac + rr); j++)
					{
						probnopolje[i][j] = 0;
					}
				}
			}
		}
		maxzbroj = 0;
		l++;
		//printf("%d[%d][ %d]\n", poljezbrojeva[indexredak][indexstupac], indexredak + 1, indexstupac + 1);
	}
	return pregledanihlokacija;
}

void trazenjebrpregleda(char** more, int redak, int stupac, int** poljezbrojeva, int** testpolje1, int** testpolje2)
{
	int i, j, brojac = 0;
	for (i = 0; i < redak; i++)
	{
		for (j = 0; j < stupac; j++)
		{
			brojac = 0;
			if (i > 0 && more[i - 1][j] == 'x')
			{
				brojac++;
			}
			if ((i > 0) && (j < (stupac - 1)) && (more[i - 1][j + 1] == 'x'))
			{
				brojac++;
			}
			if (j < stupac - 1 && more[i][j + 1] == 'x')
			{
				brojac++;
			}
			if (j < stupac - 1 && i < redak - 1 && more[i + 1][j + 1] == 'x')
			{
				brojac++;
			}
			if (i < redak - 1 && more[i + 1][j] == 'x')
			{
				brojac++;
			}
			if (j > 0 && i < redak - 1 && more[i + 1][j - 1] == 'x')
			{
				brojac++;
			}
			if (j > 0 && more[i][j - 1] == 'x')
			{
				brojac++;
			}
			if (i > 0 && j > 0 && more[i - 1][j - 1] == 'x')
			{
				brojac++;
			}
			if (more[i][j] == 'x')
			{
				brojac++;
			}
			poljezbrojeva[i][j] = brojac;
			testpolje1[i][j] = brojac;
			testpolje2[i][j] = brojac;
		}
	}
	/*printf("\n");
	for (i = 0; i < redak; i++)
	{
		for (j = 0; j < stupac; j++)
		{
			if (poljezbrojeva[i][j] != 0)
			{
				printf(" %d", poljezbrojeva[i][j]);
			}
			else
			{
				printf(" -");
			}
		}
		printf("\n");
	}*/
	return;
}

void brisanjexica(char** more, int redak, int stupac, int lokacija[2], char smjer)
{
	int y, x, brx, bry, v, h, pomak, brismjer;
	for (y = 0; y < redak; y++)
	{
		for (x = 0; x < stupac; x++)
		{
			if (more[y][x] == 'Z')
			{
				more[y][x] = 'O';

				switch (smjer)
				{
				case 'U':
					brx = x;
					bry = y - 1;
					pomak = -1;
					break;
				case 'D':
					brx = x;
					bry = y + 1;
					pomak = 1;
					break;
				case 'L':
					brx = x - 1;
					bry = y;
					pomak = -1;
					break;
				case 'R':
					brx = x + 1;
					bry = y;
					pomak = 1;
					break;
				}

				if (smjer == 'U' || smjer == 'D')
				{
					if (x < lokacija[1])
					{
						brismjer = -1;
					}
					else if (x > lokacija[1])
					{
						brismjer = 1;
					}
					else
					{
						brismjer = 0;
					}
					for (v = bry; (v >= 0 && v < redak); v += pomak)
					{
						if (brismjer)
						{
							for (h = brx; abs(h - brx) <= abs(v - y) / 2; h += brismjer)
							{
								if (h >= 0 && h < stupac)
								{
									if (more[v][h] == 'x')
									{
										more[v][h] = '.';
									}
								}
							}
						}
						else
						{
							for (h = brx - abs(v - y) / 2; h <= brx + abs(v - y) / 2; h++)
							{
								if (h >= 0 && h < stupac)
								{
									if (more[v][h] == 'x')
									{
										more[v][h] = '.';
									}
								}
							}
						}
					}
				}
				else if (smjer == 'L' || smjer == 'R')
				{
					if (y < lokacija[0])
					{
						brismjer = -1;
					}
					else if (y > lokacija[0])
					{
						brismjer = 1;
					}
					else
					{
						brismjer = 0;
					}
					for (h = brx; (h >= 0 && h < stupac); h += pomak)
					{
						if (brismjer)
						{
							for (v = bry; abs(v - bry) <= abs(h - x) / 2; v += brismjer)
							{
								if (v >= 0 && v < redak)
								{
									if (more[v][h] == 'x')
									{
										more[v][h] = '.';
									}
								}
							}
						}
						else
						{
							for (v = bry - abs(h - x) / 2; v <= bry + abs(h - x) / 2; v++)
							{
								if (v >= 0 && v < redak)
								{
									if (more[v][h] == 'x')
									{
										more[v][h] = '.';
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}

void pisanjexica(char** more, int redak, int stupac, int lokacija[2], char smjer)
{
	int i=0, j=0, k = 0, l = 0, x = lokacija[1], y = lokacija[0], brx, bry, pomak, h, v;

	switch (smjer)
	{
	case 'U':
		brx = x;
		bry = y - 1;
		pomak = -1;
		break;
	case 'D':
		brx = x;
		bry = y + 1;
		pomak = 1;
		break;
	case 'L':
		brx = x - 1;
		bry = y;
		pomak = -1;
		break;
	case 'R':
		brx = x + 1;
		bry = y;
		pomak = 1;
		break;
	}

	if (smjer == 'U' || smjer == 'D')
	{
		for (v = bry; (v >= 0 && v < redak); v += pomak)
		{
			for (h = brx - abs(v - y) / 2; h <= brx + abs(v - y) / 2; h++)
			{
				if (h >= 0 && h < stupac)
				{
					if (more[v][h] == '.')
					{
						more[v][h] = 'x';
					}
					else if (more[v][h] == 'O')
					{
						more[v][h] = 'Z';
					}
				}
			}
		}
	}
	else if (smjer == 'L' || smjer == 'R')
	{
		for (h = brx; (h >= 0 && h < stupac); h += pomak)
		{
			for (v = bry - abs(h - x) / 2; v <= bry + abs(h - x) / 2; v++)
			{
				if (v >= 0 && v < redak)
				{
					if (more[v][h] == '.')
					{
						more[v][h] = 'x';
					}
					else if (more[v][h] == 'O')
					{
						more[v][h] = 'Z';
					}
				}
			}
		}
	}
	return;
}

void upisimatricu(char** more, int n, int m, int* lokacija)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf(" %c", &more[i][j]);
			if (more[i][j] == 'P')
			{
				lokacija[0] = i;
				lokacija[1] = j;
			}
		}
	}
	return;
}


int main()
{
	int redak, stupac, i, lokacija[2] = { 0 }, brojpregleda = 0, testic1 = 0, testic2 = 0;
	char smjer;
	int** poljezbrojeva = NULL;
	int** testpolje1 = NULL;
	int** testpolje2 = NULL;
	char** more = NULL;

	int maxtestic1 = 0, maxtestic2 = 0, l = 0, k = 0, indexmaxtestic1 = 0, indexmaxtestic2 = 0;

	scanf("%d %d %c", &redak, &stupac, &smjer);
	more = (char**)calloc(redak, sizeof(char*));
	for (i = 0; i < redak; i++)
	{
		more[i] = (char*)calloc(stupac, sizeof(char));
	}
	poljezbrojeva = (int**)calloc(redak, sizeof(int*));
	for (i = 0; i < redak; i++)
	{
		poljezbrojeva[i] = (int*)calloc(stupac, sizeof(int));
	}
	testpolje1 = (int**)calloc(redak, sizeof(int*));
	for (i = 0; i < redak; i++)
	{
		testpolje1[i] = (int*)calloc(stupac, sizeof(int));
	}
	testpolje2 = (int**)calloc(redak, sizeof(int*));
	for (i = 0; i < redak; i++)
	{
		testpolje2[i] = (int*)calloc(stupac, sizeof(int));
	}
	upisimatricu(more, redak, stupac, &lokacija);
	//printf("%d %d\n", lokacija[0], lokacija[1]);
	pisanjexica(more, redak, stupac, lokacija, smjer);
	brisanjexica(more, redak, stupac, lokacija, smjer);
	trazenjebrpregleda(more, redak, stupac, poljezbrojeva, testpolje1, testpolje2);


	while (k<100)
	{
		testic1 = test1(redak, stupac, testpolje1, k);
		
		if (testic1 > maxtestic1)
		{
			maxtestic1 = testic1;
			indexmaxtestic1 = k;
		}
		k++;
	}

	while (l<100)
	{
		testic2 = test2(redak, stupac, testpolje1, l);

		if (testic2 > maxtestic2)
		{
			maxtestic2 = testic2;
			indexmaxtestic2 = l;
		}
		printf("l = %d\n", l);
		l++;
	}

	if (maxtestic1 >= maxtestic2)
	{
		printf("\MAXTESTIC1_ %d  MAXTESTIC2 %d\n", maxtestic1, maxtestic2);
		brojpregleda = situacija1(redak, stupac, poljezbrojeva, more, indexmaxtestic1);
		printf("situacija 1\n");
	}
	else if (maxtestic1 < maxtestic2)
	{
		brojpregleda = situacija2(redak, stupac, poljezbrojeva, more, indexmaxtestic2);
		printf("situacija 2\n");
	}

	ispismatrice(more, redak, stupac, brojpregleda);
	for (i = 0; i < redak; i++)
	{
		free(more[i]);
	}
	free(more);
	for (i = 0; i < redak; i++)
	{
		free(poljezbrojeva[i]);
	}
	free(poljezbrojeva);
	for (i = 0; i < redak; i++)
	{
		free(testpolje1[i]);
	}
	free(testpolje1);
	for (i = 0; i < redak; i++)
	{
		free(testpolje2[i]);
	}
	free(testpolje2);
	return 0;
}