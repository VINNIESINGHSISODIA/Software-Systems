/*
======================================================================================================
Name:		9.c
Author : 	Vini Singh Rajput
Description:	Write a program to print the following information about a given file. 
		a. inode 
		b. number of hard links 
		c. uid 
		d. gid 
		e. size 
		f. block size 
		g. number of blocks 
		h. time of last access 
		i. time of last modification 
		j. time of last change     
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> //stat() function gives file metadata
#include <unistd.h>
#include <time.h>

int main(int argc,char *argv[]){
	struct stat fileStat;
	if(argc<2){
		printf("Usage: %s file\n",argv[0]);
		exit(1);
	}
	if(stat(argv[1],&fileStat)<0){
		perror("stat");
		exit(1);
	}
	printf("File: %s\n",argv[1]);
	printf("a. Inode: %ld\n",(long)fileStat.st_ino);
	printf("b. Number of Hard Links: %ld\n",(long)fileStat.st_nlink);
	printf("c. UID: %d\n",fileStat.st_uid);
	printf("d. GID: %d\n",fileStat.st_gid);
	printf("e. Size: %ld bytes\n",(long)fileStat.st_size);
	printf("f. Block Size: %ld bytes\n",(long)fileStat.st_blksize);
	printf("g. Number of Blocks: %ld\n",(long)fileStat.st_blocks);
	printf("h. Time of last access: %s",ctime(&fileStat.st_atime));
	printf("i. Time of last modification: %s",ctime(&fileStat.st_mtime));
	printf("j. Time of last change(metadata): %s",ctime(&fileStat.st_ctime));
	return 0;

}

/*
 ================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./9_output 9.txt
File: 9.txt
a. Inode: 2601
b. Number of Hard Links: 1
c. UID: 1000
d. GID: 1000
e. Size: 0 bytes
f. Block Size: 4096 bytes
g. Number of Blocks: 0
h. Time of last access: Sun Sep  7 07:51:31 2025
i. Time of last modification: Sun Sep  7 07:51:31 2025
j. Time of last change(metadata): Sun Sep  7 07:51:31 2025
=================================================================================================
*/
