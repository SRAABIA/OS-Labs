#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#define maxsize 30
int main(void){
	key_t key = 2023;
	key_t key2 = 2022;
	int shmid, shmid2;
	int *A,*B;
	int *s1;
	int n = 0 , sum = 0;
	if((shmid = shmget(key, maxsize, IPC_CREAT | 0666)) < 0)
		perror("shmget");
	if((A = shmat(shmid, NULL, 0)) == (int*) -1)
		perror("shmat");
	if((shmid2 = shmget(key2, maxsize, IPC_CREAT | 0666)) < 0)
		perror("shmget");
	if((B = shmat(shmid2, NULL, 0)) == (int*) -1)
		perror("shmat");	
	s1 = A;
	s1++;
	n = *s1;
	printf(" %d %d ",*A,*B);
	while(sum<n){
		sum = *A + *B;
		printf(" %d ",sum);
		*A = *B;
		*B = sum;
	}
	printf("\n");
	*A = n;
	*B = 0;
	return 0;
}
