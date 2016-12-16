// ConsoleApplication117.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


struct Cinema
{
	char film[100];
	char genre[100];
	char length[100];
};


int comp(const void *i, const void *j)
{
	int k;
	for (k = 0; k < 100; k++)
	{
		if ((*(Cinema*)i).film[k] < ((*(Cinema*)j).film[k]))
			return -1;
		else if ((*(Cinema*)i).film[k] > ((*(Cinema*)j).film[k]))
			return 1;
	}
	for (k = 0; k < 100; k++)
	{
		if ((*(Cinema*)i).genre[k] < ((*(Cinema*)j).genre[k]))
			return -1;
		else if ((*(Cinema*)i).genre[k] > ((*(Cinema*)j).genre[k]))
			return 1;
	}
	for (k = 0; k < 100; k++)
	{
		if ((*(Cinema*)i).length[k] >((*(Cinema*)j).length[k]))
			return -1;
		else if ((*(Cinema*)i).length[k] < ((*(Cinema*)j).length[k]))
			return 1;
	}
}


int main()
{
	FILE *fp = fopen("input.txt", "r");
	int n=0, m, i, j = 0;
	char chet[1000];
	while (!feof(fp))
	{
		fscanf(fp, "%*[^\n]%*c", &chet);
		n++;
	}
	struct Cinema *A;
	A = (struct Cinema*)malloc(n*sizeof(Cinema));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 100; j++)
		{
			fscanf(fp, "%c", &A[i].film[j]);
			if (A[i].film[j] == ';')
			{
				break;
			}
		}
		fscanf(fp, "%s", A[i].genre);
		fscanf(fp, "%s", A[i].length);
	}
	fclose(fp);
	qsort(A, n, sizeof(Cinema), comp);
	for (i = 0; i < n; i++)
	{
		for (m = 0; m < 100; m++)
		{
			printf("%c", A[i].film[m]);
			if (A[i].film[m] == ';')
			{
				break;
			}
		}
		printf(" ");
		printf("%s %s ", A[i].genre, A[i].length);
	}
	return 0;
}

