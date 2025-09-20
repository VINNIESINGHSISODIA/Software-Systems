/*
======================================================================================================
Name:		30.c
Author : 	Vini Singh Rajput
Description:	Write a program to run a script at a specific time using a Daemon process. 
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main(){
	pid_t pid,sid;
	pid=fork();
	if(pid<0)
		exit(EXIT_FAILURE);
	else if(pid>0)
		exit(EXIT_SUCCESS);

	sid=setsid();
	if(sid<0)
		exit(EXIT_FAILURE);

	if((chdir("/"))<0)
		exit(EXIT_FAILURE);

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	setenv("TZ", "Asia/Kolkata", 1);
	tzset();

	while(1){
		time_t now=time(NULL);
		struct tm *t=localtime(&now);
		system("sh -c 'echo \"Live at $(date)\" >> /home/vinnie/handsonList1/30_log.txt'");


		if(t->tm_hour==12 && t->tm_min==25){
			system("/home/vinnie/handsonList1/script.sh");
			sleep(60);
		}
		sleep(1);
	}
	exit(EXIT_SUCCESS);

}

/*
================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 30.c
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./a.out &
[1] 1763
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ cat daemon.txt
Live at Sun Sep  7 06:29:51 UTC 2025
Live at Sun Sep  7 12:25:00 IST 2025
[1]+  Done                    ./a.out

==================================================================================================
*/
