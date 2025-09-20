/*
======================================================================================================
Name:		29.c
Author : 	Vini Singh Rajput
Description:	Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  
		SCHED_RR). 
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <error.h>
#include <string.h>

int main(){
	int pid=getpid();
	int policy;

	policy= sched_getscheduler(pid);
	if(policy==-1){
		perror("sched_getscheduler failed");
		exit(1);
	}

	printf("Current scheduling policy: ");
	if(policy==SCHED_OTHER)
		printf("SCHED_OTHER(default)\n");
	else if(policy==SCHED_FIFO)
		printf("SCHED_FIFO\n");
	else if(policy==SCHED_RR)
		printf("SCHED_RR\n");
	else
		printf("Unknown\n");

	struct sched_param param;
	param.sched_priority=20;

	if(sched_setscheduler(pid,SCHED_FIFO,&param)==-1){
		perror("sched_setscheduler(SCHED_FIFO) failed");
	}
	else
		printf("Policy changed to SCHED_FIFO with priority %d\n",param.sched_priority);

	param.sched_priority=50;
	if(sched_setscheduler(pid,SCHED_RR,&param)==-1)
		perror("sched_setscheduler(SCHED_RR) failed");
	else
		printf("Policy changed to SCHED_RR with priority %d\n",param.sched_priority);

	return 0;
}

/*
===================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ sudo ./29_output
[sudo] password for vinnie:
Current scheduling policy: SCHED_OTHER(default)
Policy changed to SCHED_FIFO with priority 20
Policy changed to SCHED_RR with priority 50

===================================================================================================
*/
