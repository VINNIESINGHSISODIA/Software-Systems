/*
======================================================================================================
Name:		19.c
Author : 	Vini Singh Rajput
Description:	Write a program to find out time taken to execute getpid system call. Use time stamp counter. 
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc() {
    unsigned int low, high;
    __asm__ __volatile__("rdtsc" : "=a"(low), "=d"(high));
    return ((unsigned long long)high << 32) | low;
}

int main(){
	unsigned long long start, end;
	start=rdtsc();
	pid_t pid=getpid();
	end=rdtsc();
	printf("Process ID: %d\n",pid);
	printf("Time taken by getpid() in CPU cycles: %llu\n",end-start);
	return 0;
}
/*
================================================================================================
OUTPUT:
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 19.c -o 19_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./19_output
Process ID: 563
Time taken by getpid() in CPU cycles: 10740
===============================================================================================
*/
