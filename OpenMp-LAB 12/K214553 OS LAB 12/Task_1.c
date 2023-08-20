#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	int matrix1[5][5];
	int matrix2[5][5];
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)	
		{
			matrix1[i][j]=rand()%100;
			matrix2[i][j]=rand()%100;
		}
	}
	int sum[5][5];
	#pragma omp parallel for default(shared)
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			sum[i][j]=matrix1[i][j]+matrix2[i][j];
		}
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf(" %d  ",sum[i][j]);
		}
		printf("\n");
	}
}
