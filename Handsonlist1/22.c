/*
======================================================================================================
Name:		22.c
Author : 	Vini Singh Rajput
Description:	Write a program, open a file, call fork, and then write to the file by both the child as well as the 
		parent processes. Check output of the file.  
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int fd;
	pid_t pid;

	fd=open("22file.txt", O_CREAT | O_WRONLY | O_APPEND,0644);
	if(fd<0){
		perror("open");
		exit(1);
	}

	pid=fork();
	if(pid<0){
		perror("fork");
		exit(1);
	}
	else if(pid==0){
		char childMsg[]="This is written by child process.\n";
		write(fd,childMsg,sizeof(childMsg)-1);
	}
	else{
		 char parentMsg[]="This is written by parent process.\n";
                write(fd,parentMsg,sizeof(parentMsg)-1);
	}
	close(fd);
	return 0;
}
/*
=====================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 22.c -o 22_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./22_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ cat 22file.txt
This is written by parent process.
This is written by child process.
===================================================================================================
*/
