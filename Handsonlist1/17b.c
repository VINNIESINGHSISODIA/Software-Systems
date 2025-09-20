/*
======================================================================================================
Name:		17b.c
Author : 	Vini Singh Rajput
Description:	Write a program to simulate online ticket reservation.  Implement write lock  
		Write a program to open a file, store a ticket number and exit.  Write a separate program, to 
		open the file, implement write lock, read the ticket number, increment the number and print 
		the new ticket number then close the file. 
Date : 		6th September, 2025
======================================================================================================
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ticketfile>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Cannot open file");
        exit(1);
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Lock failed");
        close(fd);
        exit(1);
    }

    int ticket;
    if (read(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
        perror("Read failed");
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        exit(1);
    }

    ticket++;
    lseek(fd, 0, SEEK_SET);

    if (write(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
        perror("Write failed");
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        exit(1);
    }

    printf("Ticket reserved successfully. Your ticket number is %d\n", ticket);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}
/*
==================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 17a.c -o init_ticket
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 17b.c -o reserve_ticket
17b.c:69:1: error: expected identifier or ‘(’ before ‘:’ token
   69 | :wq!
      | ^
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ vim 17b.c
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 17b.c -o reserve_ticket
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./init_ticket tickets.dat
Ticket file initialized with ticket number 0.
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./reserve_ticket tickets.dat
Ticket reserved successfully. Your ticket number is 1
=================================================================================================
*/

