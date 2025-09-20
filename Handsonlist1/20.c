/*
======================================================================================================
Name:		20.c
Author : 	Vini Singh Rajput
Description:	Find out the priority of your running program. Modify the priority with nice command. 
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){
	pid_t pid=getpid();
	int priority=getpriority(PRIO_PROCESS,pid);
	printf("Current priority of process %d is %d\n",pid,priority);
	return 0;
}
/*
=====================================================================================================
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 20.c -o 20_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./20_output
Current priority of process 584 is 0
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ nice -n 4 ./20_output
Current priority of process 585 is 4\
=====================================================================================================
*/
