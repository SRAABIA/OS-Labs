#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAXSIZE 27
int main(void) {
	int shmid;
	key_t key;
	char *shm, *s;
	key = 2211;
	fflush(stdin);
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		perror("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (char*) -1)
		perror("shmat");
	s = shm;
	char num = *s;
	int x = num - '0'; //typecasting
	//printf("\n%d",x);
	char r[5]={'r','e','a','d','y'};
	for(int i = 0 ; i < 5 ; i++){
		*s = r[i];
		s++;
	}
	while(*shm != '*')
		sleep(1);
	printf("\n");
	for(int i = 1 ; i <= 10 ; i++){
		printf("%d * %d = %d\n",x,i,i*x);
	}
	return (0);
}

