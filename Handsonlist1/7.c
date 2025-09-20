/* 
============================================================
Name : 7.c
Author : Vini Singh Rajput
Description : Write a program to copy file1 into file2($cp file1 file2)
Date : 6th September, 2025
============================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define SIZE 4096
int main(int argc,char* argv[]){
	if(argc!=3){
		write(2,"Usage: ./copy file1 file2\n",27);
		return 1;
		
	}
	int in_fd=open(argv[1],O_RDONLY);
	if(in_fd<0){
		write(2,"Failed to open source file\n",27);
		return 1;
	}
	int out_fd=open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0644);
	if(out_fd<0){
		write(2,"Failed to open destination file\n", 32);
		close(in_fd);
		return 1;
	}
	char buf[SIZE];
	ssize_t n;
	while((n=read(in_fd,buf,SIZE))>0){
		if(write(out_fd,buf,n)!=n){
			write(2,"Error while writing data\n", 25);
			close(in_fd);
			close(out_fd);
			return 1;
		}
	}
	if(n<0){
		write(2,"Error while reading data\n",25);
	}
	
	close(in_fd);
	close(out_fd);
	write(1, "File successfully copied!\n", 27);


	return 0;
}
/*==========================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./7_output 7a.txt 7b.txt
File successfully copied!
============================================================
*/
