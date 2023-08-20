#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define SIZE 10
int main(){

	int A[SIZE];

	int temp;
	for(int j=0;j<SIZE;j++){
		A[j] = rand()%100;
	}

	printf("\nUNSORTED ARRAY:\n\n");
	
	for(int j=0;j<SIZE;j++)
	{
		printf("%d ",A[j]);
	}

	#pragma omp  parallel default(shared)

	#pragma omp parallel for
	for(int i=0;i<SIZE-1;i++)
	{
		for(int j=0;j<SIZE - i - 1;j++)
		{
			if(A[j]>A[j+1]){
				temp= A[j];
				A[j] = A[j+1];
				A[j+1] = temp;

			}
		}
	}


	printf("\n\nSORTED ARRAY:\n\n");
	
	for(int j=0;j<SIZE;j++){
		printf("%d ",A[j]);
	}
	printf("\n");
}