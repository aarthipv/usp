'''4.b) Write a C program to
i. To create a child process.
ii. The child should execute an interpreter file by passing a few arguments
iii. Create an interpreter file that has the path of echoall.c file and pass one argument
iv. Create echoall.c file which prints the arguments received from both child process and
interpreter file.
echoall.c'''



#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
int i;
for(i=0;i<argc;i++){
printf("argv[%d]= %s\n",i,argv[i]);
}
return 0;
}
inter.c
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
pid_t pid=fork();
if(pid<0){
printf("error\n");
}
else if(pid==0){
if(execl("textinterpreter","test","myarg1","myarg2","myarg4",(char *)0)<0)
printf("error\n");
if(waitpid(pid,NULL,0)<0)
printf("error\n");
}
return 0;
}

'''
textinterpreter file
#! /home/<your name/computer name>/echoall my2
[Ex. #! /home/aneesh/echoall my2]
Commands to Execute:
gcc -o echoall echoall.c
chmod 777 textinterpreter
gcc -o inter inter.c
./inter
'''