#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void){
	int fd,retval;
	char buff[100];
	fd = open("/tmp/newfile",O_RDONLY);
	retval = read(fd,buff, sizeof(buff));
	write(1,buff,sizeof(buff));
	printf(" :: 3rd READ PROCESS\n");
	close(fd);
	return 0;
}
