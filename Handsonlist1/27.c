/*
======================================================================================================
Name:		27.c
Author : 	Vini Singh Rajput
Description:	Write a program to execute ls -Rl by the following system calls 
		a. execl 
		b. execlp 
		c. execle 
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[]){

	if(argc!=2){
	printf("Usage: %s [execl | execlp | execle | execv | execvp]\n",argv[0]);
	exit(1);
	}
	
	if(strcmp(argv[1],"execl")==0){
		printf("Running ls -Rl using execl...\n");
		execl("/bin/ls","ls", "-Rl",(char* )NULL );
		perror("execl failed");
	}

	else if(strcmp(argv[1],"execlp")==0){
		printf("Running ls -Rl using execlp...\n");
		execlp("ls","ls","-Rl",(char *)NULL);
		perror("execlp failed");
	}
	else if(strcmp(argv[1],"execle")==0){
		printf("Running ls -Rl using execle...\n");
		char *envp[] = { "PATH=/bin", NULL };
		execle("/bin/ls","ls","-Rl",(char *)NULL, envp);
		perror("execle failed");
	}
	else if(strcmp(argv[1],"execv")==0){
		printf("Running ls -Rl in execv...\n");
		char * args[]={"ls","-Rl",NULL};
		execv("/bin/ls",args);
		perror("execv failed");
	}
	else if(strcmp(argv[1],"execvp")==0){
		printf("Running ls -Rl in execvp...\n");
		char* args[]={"ls","-Rl",NULL};
		execvp("ls",args);
		perror("execvp failed");
	}
	else
		printf("Invalid choice! Use: execl, execlp, execle, execv, or execvp\n");

	return 0;
}
/*
====================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 27.c -o 27_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./27_output
Usage: ./27_output [execl | execlp | execle | execv | execvp]
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./27_output execlp
Running ls -Rl using execlp...
.:
total 636
-rw-r--r-- 1 vinnie vinnie   963 Sep  6 12:37 1
-rw-r--r-- 1 vinnie vinnie  1522 Sep  6 20:25 1.c
-rw------- 3 vinnie vinnie     1 Sep  2 15:59 1.txt
-rw-r--r-- 1 vinnie vinnie   676 Sep  6 13:04 10.c
-rw-r--r-- 1 vinnie vinnie    31 Sep  6 13:06 10_file.txt
-rwxr-xr-x 1 vinnie vinnie 16304 Sep  6 13:04 10_output
-rw-r--r-- 1 vinnie vinnie  1025 Sep  6 13:56 11.c
-rwxr-xr-x 1 vinnie vinnie 16336 Sep  6 13:57 11_output
-rw-r--r-- 1 vinnie vinnie  1278 Sep  6 16:40 12.c

===================================================================================================
*/
