#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
	int retval, fd;
	char buff[]="Write Process";
	retval = mkfifo("/tmp/newfile",0666);
	fd = open("/tmp/newfile",O_WRONLY);
	write(fd,buff,sizeof(buff));
	close(fd);
	return 0;
}
