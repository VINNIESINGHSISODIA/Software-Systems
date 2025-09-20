/*
======================================================================================================
Name:		25.c
Author : 	Vini Singh Rajput
Description:	Write a program to create three child processes. The parent should wait for a particular child (use 
		waitpid system call).
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t cpid1,cpid2,cpid3;
	cpid1=fork();
	if(cpid1==0){
		printf("Child 1 (PID: %d)\n",getpid());
		sleep(2);
		exit(1);
	}

	cpid2 = fork();
   	if (cpid2 == 0) {
        	printf("Child 2 (PID: %d)\n", getpid());
      	 	sleep(4);
        	exit(2);
    	}

	cpid3 = fork();
    	if (cpid3 == 0) {
        	printf("Child 3 (PID: %d)\n", getpid());
        	sleep(6);
        	exit(3);
    	}

	int status;
	pid_t waited = waitpid(cpid2,&status,0);

	if(waited==cpid2){
		if(WIFEXITED(status)){
			printf("Parent waited for Child 2 (PID: %d), exited with status %d\n",cpid2,WEXITSTATUS(status));
		}
	}

	while(wait(NULL)>0);
	return 0;


}
/*
====================================================================================================
OUTPUT: 

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./25_output
Child 1 (PID: 775)
Child 2 (PID: 776)
Child 3 (PID: 777)
Parent waited for Child 2 (PID: 776), exited with status 2

=====================================================================================================
*/
