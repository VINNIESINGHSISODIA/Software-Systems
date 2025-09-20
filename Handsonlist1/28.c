/*
======================================================================================================
Name:		28.c
Author : 	Vini Singh Rajput
Description:	Write a program to get maximum and minimum real time priority. 
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

int main(){
	int minPriority,maxPriority;
	minPriority=sched_get_priority_min(SCHED_FIFO);
	if(minPriority==-1){
		printf("Error getting min priority for SCHED_FIFO: %s\n",strerror(errno));

	}
	else{
		printf("SCHED_FIFO -> Min priority: %d\n", minPriority);
	}
	maxPriority = sched_get_priority_max(SCHED_FIFO);
    	if(maxPriority==-1){
       		printf("Error getting max priority for SCHED_FIFO: %s\n",
               	strerror(errno));
   	 } 
	else {
        	printf("SCHED_FIFO -> Max priority: %d\n", maxPriority);
   	 }
	printf("------------------------------------------------\n");
	return 0;

}
/*
======================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 28.c -o 28_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./28_output
SCHED_FIFO -> Min priority: 1
SCHED_FIFO -> Max priority: 99

======================================================================================================
*/
