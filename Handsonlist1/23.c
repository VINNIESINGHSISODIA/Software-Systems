/*
======================================================================================================
Name:		23.c
Author : 	Vini Singh Rajput
Description:	Write a program to create a Zombie state of the running program.  
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid=fork();
	if (pid < 0) {
        perror("fork failed");
        exit(1);
    	}
	else if(pid==0){
		printf("Child process (PID: %d) exiting...\n",getpid());
		exit(0);
	}
	else{
		printf("Parent process (PID: %d) sleeping, Child PID: %d\n",getpid(),pid);
		sleep(20);
		printf("Parent process exiting...\n");
	}
	return 0;
	
}
/*
=====================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./23_output
Parent process (PID: 716) sleeping, Child PID: 717
Child process (PID: 717) exiting...
Parent process exiting...

=====================================================================================================
*/

