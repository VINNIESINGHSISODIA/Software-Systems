/*
======================================================================================================
Name:		10.c
Author : 	Vini Singh Rajput
Description:	Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
		bytes (use lseek) and write again 10 bytes.  
		a. check the return value of lseek 
		b. open the file with od and check the empty spaces in between the data.      
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
	int fd;
	off_t offset;

	fd=open("10_file.txt",O_RDWR | O_CREAT,0644);
	if(fd<0){
		perror("open");
		exit(1);
	}
	char buf1[10]="PQRSTUVWXY";
	if(write(fd,buf1,10)!=10){
		perror("write");
		close(fd);
		exit(1);
	}
	printf("Wrote first 10 bytes.\n");

	offset=lseek(fd,10,SEEK_CUR);
	if(offset==(off_t)-1){
		perror("lseek");
		close(fd);
		exit(1);
	}
	printf("File pointer moved. Current offset: %ld\n",(long)offset);
	char buf2[10]="ABCDEFGHIJ";
	if(write(fd,buf2,10)!=10){
		perror("write");
		close(fd);
		exit(1);
	}
	printf("Wrote next 10 bytes.\n");
	close(fd);
	return 0;
}
/*
===================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 10.c -o 10_output
./10_output
Wrote first 10 bytes.
File pointer moved. Current offset: 20
Wrote next 10 bytes.
===================================================================================================
*/
