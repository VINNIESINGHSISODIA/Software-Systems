/*
======================================================================================================
Name:		15.c
Author : 	Vini Singh Rajput
Description:	Write a program to display the environmental variable of the user (use environ). 
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>

extern char ** environ;

int main(){
	char **env=environ;
	while(*env){
		printf("%s\n",*env);
		env++;
	}
	return 0;
}
/*
==================================================================================================
OUTPUT:
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 15.c -o 15_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./15_output
SHELL=/bin/bash
WSL2_GUI_APPS_ENABLED=1
WSL_DISTRO_NAME=Ubuntu
NAME=LAPTOP-98T9VC4K
PWD=/home/vinnie/handsonList1
LOGNAME=vinnie
HOME=/home/vinnie
LANG=C.UTF-8
WSL_INTEROP=/run/WSL/274_interop
WAYLAND_DISPLAY=wayland-0
TERM=xterm-256color
USER=vinnie
==================================================================================================
*/
