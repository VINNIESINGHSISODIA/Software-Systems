/*
======================================================================================================
Name:		24.c
Author : 	Vini Singh Rajput
Description:	Write a program to create an orphan process.  
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
		sleep(10);
		printf("Child process (PID: %d),new parent pid: %d\n",getpid(),getppid());
	}
	else{
		printf("Parent process (PID: %d)exiting, child PID: %d\n",getpid(),pid);
		exit(0);
	}
	return 0;


}
/*
=======================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./24_output
Parent process (PID: 745)exiting, child PID: 746
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ Child process (PID: 746),parent pid: 274

=====================================================================================================
*/
