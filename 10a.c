/*  Consider the last 100 bytes as a region. Write a C program to check whether the region is locked or not. If the region is locked, print pid of the process which has locked. If the region is not locked,lock the region with an exclusive lock, read the last 50 bytes and unlock the region
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf[256];  // +1 for null terminator
    struct flock fv;

    if (argc < 2) {
        printf("usage %s <filename>\n", argv[0]);
        exit(0);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror("open");
        exit(1);
    }

    fv.l_type = F_WRLCK;
    fv.l_whence = SEEK_END;
    fv.l_start = -100; // last 100 bytes
    fv.l_len = 100;

    printf("press enter to set lock\n");
    getchar();

    printf("trying to get lock\n");
    if (fcntl(fd, F_SETLK, &fv) == -1) {
        perror("fcntl - set lock");
        fcntl(fd, F_GETLK, &fv);
        printf("file is locked by process pid: %d\n", fv.l_pid);
        close(fd);
        return -1;
    }
    printf("locked\n");

    if (lseek(fd, -50, SEEK_END) == -1) {
        perror("lseek");
        close(fd);
        exit(1);
    }

    ssize_t n = read(fd, buf, 100);
    if (n == -1) {
        perror("read");
        close(fd);
        exit(1);
    }
    buf[n] = '\0';  // null-terminate buffer

    printf("data from file:\n%s\n", buf);

    printf("press enter to unlock\n");
    getchar();

    fv.l_type = F_UNLCK;
    fv.l_whence = SEEK_SET;
    fv.l_start = 0;
    fv.l_len = 0;

    if (fcntl(fd, F_SETLK, &fv) == -1) {
        perror("fcntl - unlock");
        close(fd);
        exit(1);
    }

    printf("unlocked\n");
    close(fd);
    return 0;
}

