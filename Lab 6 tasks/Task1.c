#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int main(void){
	pid_t pid;
	int fd[2];
	char buffer[19];
	char str[20] = "OS LAB 06";
	if(pipe(fd) == -1){
		fprintf(stderr,"\nPipe Failed");
		return 1;
	}
	pid = fork();
	if(pid == 0){
		sleep(1);
		printf("\nChild: %d of %d\n",getpid(),getppid());
		close(fd[0]);
		write(fd[1],str,strlen(str)+1);
		close(fd[1]);
	}
	if(pid>0){
		wait(NULL);
		printf("\nParent : %d",getpid());
		close(fd[1]);
		read(fd[0],buffer,sizeof(buffer));
		printf("\nMessage Received: %s\n",buffer);
		close(fd[0]);
	}
	return 0;
}
