//5.a) Write a program to copy access and modification time of a file to another file using utime function.
#include <stdio.h>
#include <utime.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
if (argc < 3) {
return 1;
fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
}
struct stat file_stat;
if (stat(argv[1], &file_stat) == -1) {
perror("stat");
return 1;
}
struct utimbuf new_times;
new_times.actime = file_stat.st_atime;
new_times.modtime = file_stat.st_mtime;
if (utime(argv[2], &new_times) == -1) {
perror("utime");
return 1;
}
return 0;
}



'''
Commands to Execute:
vi program_name.c (type program here)
cc program_name.c
./a.out <source_path> <destination_path>
[Ex. ./a.out /home/aneesh /home/aneesh/Downloads]
'''