#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char *line;
    int fd;

    line = "hello world";
    fd = open("sample3.txt", O_RDONLY);
    printf ("%d\n", fd);
    printf ("%d\n", get_next_line(fd, &line));
    printf ("%s\n", line);
}