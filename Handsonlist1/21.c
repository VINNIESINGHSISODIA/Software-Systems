/*
======================================================================================================
Name:		21.c
Author : 	Vini Singh Rajput
Description:	Write a program, call fork and print the parent and child process id. 
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fork failed");
                return 1;
	}
	else if(pid==0){
		printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
	}
	 else {
        // parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
	
}
/*
===================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 21.c -o 21_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./21_output
Parent process: PID = 607, Child PID = 608
Child process: PID = 608, Parent PID = 607
===================================================================================================
*/
