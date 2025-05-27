4.a) Write a C program to demonstrate the creation of soft links and the various properties of hard
links.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[]){
if(argc==3){
if((link(argv[1],argv[2]))==0){
printf("Hard link created\n");
}
else{
printf("Hard link error\n");
}
}
else if(argc==4){
if((symlink(argv[2],argv[3]))==0){
printf("Soft link created\n");
}
else{
printf("Soft link error\n");
}
}
return 0;
}



'''
Commands to Execute:
vi program_name.c (type program here)
cc program_name.c
For Hard Link
./a.out <existing filename> <filename which isn’t created> t2.txt (t2.txt shouldn’t be created using vi just pass it as name))
For Soft Link
(for ex if t1.txt is present , then ./a.out t1.txt
./a.out <existing filename> <filename1 which isn’t created> <filename2 which isn’t created> (for ex if
t1.txt is present , then ./a.out t1.txt t2.txt t3.txt (t2.txt,t3.txt shouldn’t be created using vi just pass them as
names))'''