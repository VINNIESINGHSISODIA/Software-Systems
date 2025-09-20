/*
======================================================================================================
Name:		1.c
Author : 	Vini Singh Rajput
Description:	Create the following types of a files using (i) shell command (ii) system call 
		a. soft link (symlink system call) 
		b. hard link (link system call) 
		c. FIFO (mkfifo Library Function or mknod system call)
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(){
	if(symlink("1.txt","softlink.txt")==-1){
		perror("softlink creation failed");
	}
	else
		printf("Soft link 'softlink.txt' created -> points to '1.txt'\n");


	if (link("1.txt", "hardlink.txt") == -1) {
        	perror("hard link creation failed");
    	} 
	else {
        	printf("Hard link 'hardlink.txt' created -> same inode as '1.txt'\n");
    	}

	 if (mkfifo("myfifo", 0666) == -1) {
        	perror("mkfifo creation failed\n");
    	} 
	else {
       	 	printf("FIFO 'myfifo' created\n");
    }

    return 0;

}
/*
====================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./1_output
Soft link 'softlink.txt' created -> points to '1.txt'
Hard link 'hardlink.txt' created -> same inode as '1.txt'
FIFO 'myfifo' created

====================================================================================================
*/
