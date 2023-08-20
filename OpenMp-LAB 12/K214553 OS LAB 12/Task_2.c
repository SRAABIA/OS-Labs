#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	int Arr[10000];
	int max_value=0;
	int ind=0;
	for(int i=0;i<10000;i++)
	{
		Arr[i]=rand()%100;
	}
	#pragma omp parallel for
	for(int i=0;i<10000;i++)
	{
		if(Arr[i]>max_value)
		{
			max_value=Arr[i];
			ind=i;
		}
	}
	printf("\nThe MAX value Is:%d And Index Of Max Value Is:%d\n\n",max_value,ind);
}
