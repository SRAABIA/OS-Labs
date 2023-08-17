#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAXSIZE 27
int main(void) {
	char c;
	int shmid;
	key_t key;
	char *shm, *s;

	key = 2211;
	
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		perror("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (char*) -1)
		perror("shmat");
	s = shm;
	printf("Enter number: ");
	scanf("%c",s);
	while(*shm != 'r')
		sleep(1);
	for( s=shm ; *s!='\0' ; s++){
		putchar(*s);
	}
	printf("\n");
	*shm = '*';
	return(0);
}
