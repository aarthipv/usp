'''7.b) C program to simulate copy command by accepting the filenames from command line. Report all
errors.'''



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int main(int argc, char *argv[]) {
if (argc < 3) {
return 1;
fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
}
int src_fd = open(argv[1], O_RDONLY);
if (src_fd == -1) {
perror("open source");
return 1;
}
int dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (dst_fd == -1) {
perror("open destination");
return 1;
}
char buffer[BUFFER_SIZE];
ssize_t bytes_read;
while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
if (write(dst_fd, buffer, bytes_read) != bytes_read) {
perror("write");
return 1;
}
}
if (bytes_read == -1) {
perror("read");
}
close(src_fd);
close(dst_fd);
return 0;
}


'''
Commands to Execute:
vi program_name.c (type program here)
cc program_name.c
./a.out <sourcefile_name> <destinationfile_name> (Write some content in sourcefile and keep
destinationfile empty )'''