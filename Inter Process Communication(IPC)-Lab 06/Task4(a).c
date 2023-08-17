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
	int shmid,n;
	int *A,*s;
	if((shmid = shmget(key, maxsize, IPC_CREAT | 0666)) < 0)
		perror("shmget");
	if((A = shmat(shmid, NULL, 0)) == (int*) -1)
		perror("shmat");
	s = A;
	printf("\nEnter limit for Fibonnaci: ");
	scanf("%d",&n);
	if(n<1 && n>100){
		printf("Error! Number range: 1-100");
		return 0;
	}
	*s = 0;
	s++;
	*s = n;
	while(*A != n )
		wait(NULL);
	return 0;
}
