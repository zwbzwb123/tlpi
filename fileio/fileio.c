#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

/*
 * int open(const char *pathname,int flags,...mode_t mode);
 *	 return fd on success,or -1 on error
 * flags:
 * 	file access mode flags:
 * 		O_RDONLY
 *    		O_WRONLY
 *    		O_RDWR
 *    	file creation flags:
 *     		O_CLOEXEC
 *		O_CREAT
 * 		O_DIRECT
 *   		O_DIRECTORY
 *  	file status flags:
 *   		O_APPEND  writes are always append to end of file
 *    		O_ASYNC   generate a signal when I/O is possible
 *    		O_NONBLOCK	open in nonblocking mode
 *     		O_SYNC		make file write sync
 *       	O_DSYNC		sync I/O data
 *     		O_TRUNC
 */

int main(int argc,char *argv[]){
	int fd;
	fd = open("/tlpi/test.txt",O_CREAT | O_RDWR | O_TRUNC,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	if(fd == -1){
		fprintf(stderr,"open %s error!","/tlpi/test.txt");
		exit(0);
	}else {
		printf("open %s success,fd is: %d","/tlpi/test.txt",fd);
	}
	return 1;
}
