'''6.b) Consider the last 100 bytes as a region. Write a C program to check whether the region is locked
or not. If the region is locked, print pid of the process which has locked. If the region is not locked,
lock the region with an exclusive lock, read the last 50 bytes and unlock the region.'''



#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[]){
int fd; char buf[255]; struct flock fv;
if(argc<2){
printf("usage %s <filename>\n",argv[0]);
exit(0);
}
if((fd=open(argv[1],O_RDWR))==-1){
printf("error\n");
exit(1);
}
fv.l_type=F_WRLCK; fv.l_whence=SEEK_END;
fv.l_start=SEEK_END-100; fv.l_len=100;
printf("press enter to set lock\n");
getchar();
printf("trying to get lock\n");
if((fcntl(fd,F_SETLK,&fv))==-1){
fcntl(fd,F_GETLK,&fv);
printf("file is locked by process pid: %d \n",fv.l_pid);
return -1;
}
printf("locked\n");
if((lseek(fd,SEEK_END-50,SEEK_END))==-1){
printf("lseek\n");
exit(1);
}
if((read(fd,buf,100))==-1){
printf("read\n");
exit(1);
}
printf("data from file:\n");
puts(buf);
printf("press enter to unlock\n");
getchar();
fv.l_type=F_UNLCK; fv.l_whence=SEEK_SET;
fv.l_start=0; fv.l_len=0;
if((fcntl(fd,F_UNLCK,&fv))==-1){
printf("error\n");
exit(0);
}
printf("unlocked\n");
close(fd);
return 0;
}


'''
Commands to Execute:
Open Two Terminals
In one,
vi program_name.c(type your program here)
cc program_name.c
./a.out <file_name>(file should exist)
In Second,
cc program_name.c
./a.out <file_name>(file should exist)'''