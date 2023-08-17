#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#define maxsize 30
int main(void){
	key_t key = 2022;
	int shmid;
	int *B,*s;
	if((shmid = shmget(key, maxsize, IPC_CREAT | 0666)) < 0)
		perror("shmget");
	if((B = shmat(shmid, NULL, 0)) == (int*) -1)
		perror("shmat");
	s = B;
	*s = 1;
	
	while(*B != 0 )
		wait(NULL);
	return 0;
}
