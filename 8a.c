//8.a) Write a C program that takes file name as an argument and prints the type of the given file.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
void err_ret(const char *msg) {
perror(msg);
}
int main(int argc, char *argv[]) {
int i;
struct stat buf;
char *ptr;
for (i = 1; i < argc; i++) {
printf("%s: ", argv[i]);
if (lstat(argv[i], &buf) < 0) {
err_ret("lstat error");
continue;
}
if (S_ISREG(buf.st_mode))
ptr = "regular";
else if (S_ISDIR(buf.st_mode))
ptr = "directory";
else if (S_ISCHR(buf.st_mode))
ptr = "character special";
else if (S_ISBLK(buf.st_mode))
ptr = "block special";
else if (S_ISFIFO(buf.st_mode))
ptr = "fifo";
else if (S_ISLNK(buf.st_mode))
ptr = "symbolic link";
else if (S_ISSOCK(buf.st_mode))
ptr = "socket";
else
ptr = "** unknown mode **";
printf("%s\n", ptr);
}
exit(0);
}


'''
Commands to Execute:
vi program_name.c (type program here)
cc program_name.c
./a.out <file_name1> <file_name2> <file_name3>'''