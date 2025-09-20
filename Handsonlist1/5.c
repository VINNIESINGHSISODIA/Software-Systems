/*
======================================================================================================
Name:		5.c
Author : 	Vini Singh Rajput
Description:	Write a program to create five new files with infinite loop. Execute the program in the background 
		and check the file descriptor table at /proc/pid/fd.   
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
int fd[5];
char filename[50];
pid_t pid=getpid();
 
printf("Program running with PID: %d\n",pid);

for(int i=0;i<5;i++){
sprintf(filename,"file%d.txt",i+1 );
fd[i]=open(filename,O_CREAT | O_RDWR,0644);

if(fd[i]==-1){
perror("open");
return 1;
}
printf("creates %s with FD:%d\n",filename,fd[i]);
}
while(1){
sleep(5);
}
return 0;

}
/*
===================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./5_output &
[1] 15300
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ Program running with PID: 15300
creates file1.txt with FD:3
creates file2.txt with FD:4
creates file3.txt with FD:5
creates file4.txt with FD:6
creates file5.txt with FD:7
kill 15300
===================================================================================================
*/
