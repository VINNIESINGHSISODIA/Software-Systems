/*
======================================================================================================
Name:		11.c
Author : 	Vini Singh Rajput
Description:	Write a program to open a file, duplicate the file descriptor and append the file with both the 
		descriptors and check whether the file is updated properly or not. 
		a. use dup 
		b. use dup2 
		c. use fcntl 
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	int fd,fd_dup1,fd_dup2,fd_dup3;
	fd=open("dup_test.txt",O_WRONLY | O_CREAT | O_APPEND,0644);
	if(fd<0){
		perror("open");
		exit(1);
	}
	printf("Original file descriptor: %d\n",fd);
	fd_dup1=dup(fd);
	if(fd_dup1<0){
		perror("dup1");
		close(fd);
		exit(1);
	}
	printf("File Descriptor duplicated with dup1: %d\n",fd_dup1);

	fd_dup2=dup2(fd,50);
	if(fd_dup2<0){
		perror("dup2");
		close(fd);
		exit(1);
	}
	printf("File Descriptor duplicated with dup2: %d\n",fd_dup2);
	fd_dup3=fcntl(fd,F_DUPFD,100);
	if(fd_dup3<0){
		perror("fcntl");
		close(fd);
		exit(1);
	}
	printf("File Descriptor duplicated with fcntl: %d\n",fd_dup3);

	write(fd,"Hello from fd\n",14);
	write(fd_dup1,"Hello from fd_dup1\n",20);
	write(fd_dup2,"Hello from fd_dup2\n",20);
	write(fd_dup3,"Hello from fd_dup3\n",20); 

	close(fd);
	close(fd_dup1);
	close(fd_dup2);
	close(fd_dup3);

	printf("Check dup_test.txt to see the contents appended.\n");
	return 0;
}
/*
===================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./11_output
Original file descriptor: 3
File Descriptor duplicated with dup1: 4
File Descriptor duplicated with dup2: 50
File Descriptor duplicated with fcntl: 100
Check dup_test.txt to see the contents appended.
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ cat dup_test.txt
Hello from fd
Hello from fd_dup1
Hello from fd_dup2
Hello from fd_dup3

Hello from fd
Hello from fd_dup1
Hello from fd_dup2
Hello from fd_dup3
===================================================================================================
*/
