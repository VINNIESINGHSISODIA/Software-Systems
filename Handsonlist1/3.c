/*
======================================================================================================
Name:		3.c
Author : 	Vini Singh Rajput
Description:	Write a program to create a file and print the file descriptor value. Use creat ( ) system call. 
Date : 		6th September, 2025
======================================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
int fd;
fd=creat("ans_3.txt",0644);
if(fd==-1){
perror("creat");
return 1;
}
printf("file created successfully with file descriptor: %d\n",fd);

close(fd);
return 0;
}

/*
===================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 3.c -o 3_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./3_output
file created successfully with file descriptor: 3
===================================================================================================
*/
