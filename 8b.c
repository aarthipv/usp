'''8.b) Write a C program to perform the following operations
i. ii. iii. iv. To create a child process
The child process should execute a program (using exec( )) to show the use of the access function
The Parent process should wait for the child process to exit
Also print the necessary process IDs'''


//Main program,
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
int main() {
pid_t pid;
int status;
pid_t parent_pid = getpid();
pid = fork();
if (pid == -1) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid == 0) {
pid_t child_pid = getpid();
printf("Child process (PID: %d) executing...\n", child_pid);
execl("./p1", "p1", "example.txt", (char *)NULL);
perror("execl");
exit(EXIT_FAILURE);
} else {
printf("Parent process (PID: %d) executing...\n", parent_pid);
waitpid(pid, &status, 0);
printf("Parent process: Child process (PID: %d) has exited.\n", pid);
}
return 0;
}


//p1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
if (argc != 2) {
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
exit(EXIT_FAILURE);
}
char *filename = argv[1];
if (access(filename, F_OK) == 0) {
printf("File '%s' exists and can be accessed.\n", filename);
} else {
printf("File '%s' does not exist or cannot be accessed.\n", filename);
}
return 0;
}


'''
Commands to Execute:
vi program_name.c (type program here)
vi p1.c
cc -o p1 p1.c
cc program_name.c
./a.out'''