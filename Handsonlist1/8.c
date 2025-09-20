/*
======================================================================================================
Name:		8.c
Author : 	Vini Singh Rajput
Description:	Write a program to open a file in read only mode, read line by line and display each line as it is read. 
		Close the file when end of file is reached.    
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	char line[256];

	f=fopen("file.txt","r");

	if(f==NULL){
		printf("Error: could not open the file\n");
		exit(1);
	}
	while(fgets(line,sizeof(line),f)!=NULL){
		printf("%s",line);

	}
	fclose(f);
	return 0;

}

/*
===================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 8.c -o 8_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./8_output
a c r r
b f f
c
d
e
f
===================================================================================================
*/
