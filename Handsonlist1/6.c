/*
======================================================================================================
Name:		6.c
Author : 	Vini Singh Rajput
Description:	Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls   
Date : 		6th September, 2025
======================================================================================================
*/
#include <unistd.h>
int main(){
char buffer[1024];
ssize_t n;
while((n=read(0,buffer,sizeof(buffer)))>0){
write(1,buffer,n);
}
return 0;
}

/*
===================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 6.c -o 6_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./6_output
i m vini
i m vini
hello
hello
===================================================================================================
*/
