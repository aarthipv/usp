//1.b) Write a C program to create a child process and show how parent and child processes will share the text file and justify that both parent and child shares the same file offset.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main() {
int fd = open("t2.txt", O_RDWR);
if (fd == -1) {
perror("open");
return 1;
}
pid_t pid = fork();
if (pid == -1) {
perror("fork");
return 1;
} else if (pid == 0) {
char buffer[10];
read(fd, buffer, 5);
buffer[5] = '\0';
printf("Child read: %s\n", buffer);
} else {
wait(NULL);
char buffer[10];
read(fd, buffer, 5);
buffer[5] = '\0';
printf("Parent read: %s\n", buffer);
}
close(fd);
return 0;
}


//gedit t2.txt
// cc 1b.c
// ./a.out