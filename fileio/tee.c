#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[]) {
	int append = 0;
	char buffer[1024];
	int numRead;
	int flags = O_WRONLY;
        if( getopt(argc,argv,"a") != -1)
                append = 1;
	if(append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	int fd = open("/tlpi/test.txt",flags);
	if(fd == -1){
		printf("open test.txt error\n");
		exit(0);
	}
	printf("open file success\n");
	while((numRead = read(STDIN_FILENO,buffer,1024)) > 0){
		write(STDOUT_FILENO,buffer,numRead);
		write(fd,buffer,numRead);
	}
	if(numRead == -1)
		printf("read error!\n");
	return 1; 
}
