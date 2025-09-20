/*
======================================================================================================
Name:		26.c
Author : 	Vini Singh Rajput
Description:	Write a program to execute an executable program. 
		a. use some executable program 
		b. pass some input to an executable program. (for example execute an executable of $./a.out name) 
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	printf("Parent process: Executing anothe program...\n");
	execl("./a.out","xxx","Vinnie",NULL);
	perror("execl failed");
	return 1;
}
/*
=====================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./26_output
Parent process: Executing anothe program...
Hello from a.out!
Received argument: Vinnie

====================================================================================================
*/

