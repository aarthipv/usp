'''12.b) Write a C program to perform the following operations
i) ii) iii) To create a child and parent process with the use of an echoall file.
The Child should execute a process that prints the user defined values of environment
variables
The Parent should execute a process that prints default values for the environment
variables.
Main program
*** Remember to change the path in the first argument of both execle() and execlp(), set pat
according to the location of your echoall file ***'''

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void err_sys(const char *message) {
perror(message);
exit(1);
}
int main(void) {
pid_t pid;
char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL };
if ((pid = fork()) < 0) {
err_sys("fork error");
} else if (pid == 0) {
if (execle("/home/aneesh/echoall", "echoall", "myarg1", "MY ARG2", (char *)0, env_init) < 0) {
err_sys("execle error");
}
}
if (waitpid(pid, NULL, 0) < 0) {
err_sys("wait error");
}
if (execlp("/home/aneesh/echoall", "echoall", "only 1 arg", (char *)0) < 0) {
err_sys("execlp error");
}
return 0;
}


//echoall.c file
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
int i;
for(i=0;i<argc;i++){
printf("argv[%d]= %s\n",i,argv[i]);
}
return 0;
}

'''
Commands to Execute:
vi program_name.c
vi echoall.c
cc program_name.c
./a.out'''