'''9.b) Write a C program
i. To read first 20 characters from a file
ii. seek to 10th byte from the beginning and display 20 characters from there
iii. seek 10 bytes ahead from the current file offset and display 20 characters
iv. Display the file size'''


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return 1;
}
int fd = open(argv[1], O_RDONLY);
if (fd == -1) {
perror("open");
return 1;
}
char buffer[21];
if (read(fd, buffer, 20) != 20) {
perror("read");
close(fd);
return 1;
}
buffer[20] = '\0';
printf("First 20 characters: %s\n", buffer);
lseek(fd, 10, SEEK_SET);
if (read(fd, buffer, 20) != 20) {
perror("read");
close(fd);
return 1;
}
buffer[20] = '\0';
printf("20 characters from 10th byte: %s\n", buffer);
lseek(fd, 10, SEEK_CUR);
if (read(fd, buffer, 20) != 20) {
perror("read");
close(fd);
return 1;
}
buffer[20] = '\0';
printf("20 characters from current offset: %s\n", buffer);
off_t file_size = lseek(fd, 0, SEEK_END);
if (file_size == -1) {
perror("lseek");
close(fd);
return 1;
}
printf("File size: %lld bytes\n", (long long) file_size);
close(fd);
return 0;
}

'''
Commands to Execute:
vi program_name.c(type your program here)
cc program_name.c
./a.out <file_name>
(make sure to write arnd 100bytes content in file)
'''