/*
======================================================================================================
Name:		14.c
Author : 	Vini Singh Rajput
Description:	Write a program to find the type of a file. 
		a. Input should be taken from command line. 
		b. program should be able to identify any type of a file.  
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Usage: %s <filename>\n",argv[0]);
		exit(1);
	}
	struct stat filestat;
	if(stat(argv[1],&filestat)==-1){
		perror("stat");
		exit(1);
	}
	switch(filestat.st_mode & S_IFMT){
		case S_IFREG:
			printf("%s is a Regular file\n",argv[1]);
			break;
		case S_IFDIR:
			printf("%s is a Directory\n",argv[1]);
			break;
		case S_IFLNK:
			printf("%s is a Symbolic link\n",argv[1]);
			break;
		case S_IFCHR:
			printf("%s is a Character device\n",argv[1]);
			break;
		case S_IFBLK:
			printf("%s is a Block device\n",argv[1]);
			break;
		case S_IFIFO:
			printf("%s is a FIFO\n",argv[1]);
			break;
		case S_IFSOCK:
			printf("%s is a Socket\n",argv[1]);
			break;
		default:
			printf("%s is of Unknown type\n",argv[1]);
			break;
	}
	return 0;
}
/*=============================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 14.c -o 14_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./14_output
Usage: ./14_output <filename>
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./14_output file.txt
file.txt is a Regular file
===============================================================================================
*/
