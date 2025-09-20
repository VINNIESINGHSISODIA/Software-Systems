/*
======================================================================================================
Name:		4.c
Author : 	Vini Singh Rajput
Description:	Write a program to open an existing file with read write mode. Try O_EXCL flag also.  
Date : 		6th September, 2025
======================================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
int fd;
fd = open("ans_3.txt", O_RDWR);

if(fd==-1){
perror("open without O_EXCL");
}
else{
printf("file opened successfully with fd:%d\n",fd);
close(fd);
}

fd = open("ans3", O_CREAT | O_EXCL | O_RDWR, 0644);
if(fd==-1){
perror("open with O_EXCL");
}
else{
printf("file created successfully with fd(O_EXCL): %d\n",fd);
close(fd);
}
return 0;
}
/*
====================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./4_output
file opened successfully with fd:3
file created successfully with fd(O_EXCL): 3

====================================================================================================
*/
