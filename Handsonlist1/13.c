/*
========================================================================================================
Name:		13.c
Author : 	Vini Singh Rajput
Description: 	Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to 
		verify whether the data is available within 10 seconds or not (check in $man 2 select).  
Date : 		6th September, 2025
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>     
#include <unistd.h>     
#include <sys/time.h>   
#include <sys/types.h>  
#include <sys/select.h> 

int main() {
    fd_set readfds;          
    struct timeval timeout;  
    int ret;

   
    FD_ZERO(&readfds);

   
    FD_SET(STDIN_FILENO, &readfds);

   
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

   
    printf("Waiting for input for 10 seconds...\n");
    fflush(stdout);
    ret=select(STDIN_FILENO+1,&readfds,NULL,NULL, &timeout);
    if(ret==-1){
	    perror("select error");
	    exit(1);
    }
    else if(ret==0){
	    printf("No data within 10 seconds(timeout).\n");
    }
    else{
	    if(FD_ISSET(STDIN_FILENO,&readfds)){
		    printf("Data is available on STDIN! You typed: ");

	    }
	    char buffer[100];
	    if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
		    printf("%s",buffer);
	    }
    }
    return 0;
 	
}    
/*
=====================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 13.c -o 13_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./13_output
Waiting for input for 10 seconds...
hey i am vini
Data is available on STDIN! You typed: hey i am vini
=====================================================================================================
*/
