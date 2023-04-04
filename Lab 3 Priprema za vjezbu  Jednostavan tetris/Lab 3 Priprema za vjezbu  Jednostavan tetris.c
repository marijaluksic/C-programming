#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int matrica[3][3] = { 0 };
	int katrica[3][3] = { 0 };
	int brojac = 0;
	int i, j, b = 0;
	int c = 0;
	int unos[3] = { 0 };
	int redak = 0;
	int brojacredak[3] = { 2, 2, 2 };
	while (brojacredak[0] >= 0 && brojacredak[1] >= 0 && brojacredak[2] >= 0)
	{
		for (b = 0; b < 3; b++)
		{
			scanf("%d", &unos[b]);
			while (unos[b] < 0 || unos[b] > 3)
			{
				printf("Ponovi unos!\n");
				scanf("%d", &unos[b]);
			}
			matrica[brojacredak[b]][b] = unos[b];
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				//printf("%d", matrica[i][j]);
				katrica[i][j] = matrica[i][j];
			}
			//printf("\n");
		}
		c = 0;
		while (c < 3)
		{
			for (i = 0; i < 3; i++)
			{
				if (katrica[i][c] == katrica[i + 1][c] && i < 2)
				{
					if (katrica[i][c] == katrica[i + 2][c] && i < 1)
					{
						matrica[i + 2][c] = 0;
					}
					matrica[i + 1][c] = 0;
					matrica[i][c] = 0;
				}
				if (katrica[c][i] == katrica[c][i + 1] && i < 2)
				{
					if (katrica[c][i] == katrica[c][i + 2] && i < 1)
					{
						matrica[c][i + 2] = 0;
					}
					matrica[c][i + 1] = 0;
					matrica[c][i] = 0;
				}
			}
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (matrica[i][j] != 0 && matrica[i+1][j] == 0 && i < 2)
					{
						matrica[i+1][j] = matrica[i][j];
						katrica[i + 1][j] = katrica[i][j];
						matrica[i][j] = 0;
						katrica[i][j] = 0;
						c--;
					}
				}
			}
			c++;
		}
		c = 0;
		while (c == 0)
		{
			for (i = 0; i < 3; i++)
			{
				if (matrica[i][0] != 0 && c == 0)
				{
					brojacredak[0] = i-1;
					c++;
				}
			}
			if (c == 0)
			{
				brojacredak[0] = 2;
				c++;
			}
		}
		c = 0;
		while (c == 0)
		{
			for (i = 0; i < 3; i++)
			{
				if (matrica[i][1] != 0 && c == 0)
				{
					brojacredak[1] = i-1;
					c++;
				}
			}
			if (c == 0)
			{
				brojacredak[1] = 2;
				c++;
			}
		}
		c = 0;
		while (c == 0)
		{
			for (i = 0; i < 3; i++)
			{
				if (matrica[i][2] != 0 && c == 0)
				{
					brojacredak[2] = i-1;
					c++;
				}
			}
			if (c == 0)
			{
				brojacredak[2] = 2;
				c++;
			}
		}
		//printf("brojacredak [0] = %d	brojacredak [1] = %d	brojacredak [2] = %d\n", brojacredak[0], brojacredak[1], brojacredak[2]);
		brojac++;
		printf("Nakon %d. kruga:\n", brojac);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d", matrica[i][j]);
				katrica[i][j] = matrica[i][j];
			}
			printf("\n");
		}
	}
	printf("Prekid igre.\n");
	return 0;
}