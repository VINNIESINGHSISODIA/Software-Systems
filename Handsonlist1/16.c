/*
======================================================================================================
Name:		16.c
Author : 	Vini Singh Rajput
Description:	Write a program to perform mandatory locking. 
		a. Implement write lock 
		b. Implement read lock  
Date : 		6th September, 2025
======================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void lock_file(int fd, short type) {
    struct flock fl;
    fl.l_type = type;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Lock failed");
        exit(1);
    }

    printf("%s lock acquired. Press Enter to release.\n",
           (type == F_WRLCK) ? "Write" : "Read");
    getchar();

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    printf("Lock released.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Cannot open file");
        exit(1);
    }

    char choice;
    printf("Select lock type: (r)ead or (w)rite: ");
    scanf(" %c", &choice);
    getchar();

    if (choice == 'r')
        lock_file(fd, F_RDLCK);
    else if (choice == 'w')
        lock_file(fd, F_WRLCK);
    else
        printf("Invalid choice.\n");

    close(fd);
    return 0;
}
/*
===========================================================================================
OUTPUT:
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./16_output file.txt
Select lock type: (r)ead or (w)rite: r
Read lock acquired. Press Enter to release.

Lock released.
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./16_output file.txt
Select lock type: (r)ead or (w)rite: w
Write lock acquired. Press Enter to release.

Lock released.
===========================================================================================
*/
