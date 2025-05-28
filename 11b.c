'''11.b) Write a program to perform the following operations:
i) To create a child process.
ii) The child process should execute a separate program (using exec() function) that calculates
the addition of two numbers by passing two integer values.
iii) Parent process should wait for the child to complete.'''


//Main program.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
if (argc != 3) {
printf("Usage: %s num1 num2\n", argv[0]);
exit(0);
}
pid_t pid = fork();
if (pid < 0) {
perror("fork failed");
exit(0);
} else if (pid == 0) {
execl("./p23", "p23", argv[1], argv[2], (char *)NULL);
perror("execl failed");
exit(EXIT_FAILURE);
} else {
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status)) {
printf("Child exited with status %d\n", WEXITSTATUS(status));
} else {
printf("Child terminated abnormally\n");
}
}
return 0;
}


//p23.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
if (argc != 3) {
printf("Usage: %s num1 num2\n", argv[0]);
exit(0);
}
int num1 = atoi(argv[1]);
int num2 = atoi(argv[2]);
int sum = num1 + num2;
printf("Sum: %d\n", sum);
return 0;
}


'''
Commands to Execute:
vi program_name.c
vi p23.c
cc -o main_program main_program.c
cc -o p23 p23.c
/main_program 5 6 (these numbers can be anything)'''