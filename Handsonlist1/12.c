/*
=====================================================================
Name: 12.c
Author : Vini Singh Rajput
Description: Write a program to find out the opening mode of a file. Use fcntl. 
Date : 6th September, 2025
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
	int fd;
	fd=open("12_testfile.txt",O_RDWR | O_APPEND | O_CREAT,0644);
	if(fd<0){
		perror("open");
		exit(1);
	}
	int flags=fcntl(fd,F_GETFL);
	if(flags<0){
		perror("fcntl");
		close(fd);
		exit(1);
	}

	int accessMode=flags & O_ACCMODE;
	printf("File opening mode:\n");
	
	if(accessMode==O_RDONLY)
		printf("Read only\n");
	else if(accessMode==O_WRONLY)
		printf("Write only\n");
	else if(accessMode==O_RDWR)
		printf("Read Write\n");

	if(flags & O_APPEND)
		printf("Append mode is ON\n");
	if(flags & O_NONBLOCK)
		printf("Non-Blocking mode is ON\n");
	return 0;
}
/*
==========================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 12.c -o 12_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./12_output
File opening mode:
Read Write
Append mode is ON
==========================================================================
*/
