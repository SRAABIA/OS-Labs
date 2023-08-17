#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
	int fd,retval;
	char buff[100];
	fd = open("/tmp/newfile",O_RDONLY);
	retval=read(fd,buff, sizeof(buff));
	printf("%s",buff);
	//write(1,buff,sizeof(buff));
	printf(" :: 1st READ PROCESS\n");
	close(fd);
	return 0;
}
