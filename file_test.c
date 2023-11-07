#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

// To create a file that contains "Hello world\n"
int main(int argc, char *argvp[]) {
    // Open file and Create this file
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd > -1);
    // Write some data to file
    int rc = write(fd, "hello world\n", 13);
    assert(rc == 13);
    printf("Write to file successfully : %d\n", rc);
    // Simpley close file
    close(fd);
    return 0;
}

// gcc file_test.c -o file_test
// ./file_test