/*
======================================================================================================
Name:		18.c
Author : 	Vini Singh Rajput
Description:	Write a program to perform Record locking. 
		a. Implement write lock 
		b. Implement read lock 
		Create three records in a file. Whenever you access a particular record, first lock it then modify/access 
		to avoid race condition.
Date : 		6th September, 2025
======================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct record {
    int id;
    char data[50];
};

void lock_record(int fd, int rec_no, short type) {
    struct flock fl;
    fl.l_type = type;
    fl.l_whence = SEEK_SET;
    fl.l_start = rec_no * sizeof(struct record);
    fl.l_len = sizeof(struct record);

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Lock failed");
        exit(1);
    }
}

void unlock_record(int fd, int rec_no) {
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = rec_no * sizeof(struct record);
    fl.l_len = sizeof(struct record);
    fcntl(fd, F_SETLK, &fl);
}

int main() {
    int fd = open("records.dat", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Cannot open file");
        exit(1);
    }

    // Initialize 3 records if file is empty
    struct record rec;
    if (lseek(fd, 0, SEEK_END) == 0) {
        for (int i = 0; i < 3; i++) {
            rec.id = i + 1;
            snprintf(rec.data, sizeof(rec.data), "Record %d", rec.id);
            write(fd, &rec, sizeof(rec));
        }
    }

    int choice, rec_no;
    printf("Select operation:\n1. Read record\n2. Write record\nChoice: ");
    scanf("%d", &choice);
    printf("Enter record number (1-3): ");
    scanf("%d", &rec_no);
    rec_no--; // array index 0-2

    if (choice == 1)
        lock_record(fd, rec_no, F_RDLCK);
    else if (choice == 2)
        lock_record(fd, rec_no, F_WRLCK);
    else {
        printf("Invalid choice\n");
        close(fd);
        exit(1);
    }

    lseek(fd, rec_no * sizeof(struct record), SEEK_SET);
    read(fd, &rec, sizeof(rec));

    if (choice == 1) {
        printf("Record %d: %s\n", rec.id, rec.data);
    } else {
        printf("Current data: %s\n", rec.data);
        printf("Enter new data: ");
        getchar(); // consume newline
        fgets(rec.data, sizeof(rec.data), stdin);
        lseek(fd, rec_no * sizeof(struct record), SEEK_SET);
        write(fd, &rec, sizeof(rec));
        printf("Record updated.\n");
    }

    unlock_record(fd, rec_no);
    close(fd);
    return 0;
}
/*
==================================================================================================
OUTPUT:

vinnie@LAPTOP-98T9VC4K:~/handsonList1$ gcc 18.c -o 18_output
vinnie@LAPTOP-98T9VC4K:~/handsonList1$ ./18_output
Select operation:
1. Read record
2. Write record
Choice: 1
Enter record number (1-3): 2
Record 2: Record 2
==================================================================================================
*/
