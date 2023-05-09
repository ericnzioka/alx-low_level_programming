#include "main.h"

/**
 * main - should copy the file content to another
 * @argc: number argument count
 * @argv: vector of arguments passed *
 * Return: always 1 if success and exit otherwise
 */

int main(int argc, char *argv[])
{
    int source;
    int destination;
    int w_read = 1024;
    int writte;
    int close_source;
    int close_destination;
    unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    char buff[1024];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
        exit(97);
    }
    source = open(argv[1], O_RDONLY);
    start_io(source, -1, argv[1], 'O');
    destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
    start_io(destination, -1, argv[2], 'W');
    while (w_read == 1024)
    {
        w_read = read(source, buff, sizeof(buff));
        if (w_read == -1)
            start_io(-1, -1, argv[1], 'O');
        writte = write(destination, buff, w_read);
        if (writte == -1)
            start_io(-1, -1, argv[2], 'W');
    }
    close_source = close(source);
    start_io(close_source, source, NULL, 'C');
    close_destination = close(destination);
    start_io(close_destination, destination, NULL, 'C');
    return (0);
}

/**
 * start_io - a function that checks if a file can be opened or closed
 * @stat: file descriptor of the file to be opened
 * @filename: name of the file
 * @mode: closing or opening
 * @fd: file descriptor *
 * Return: void
 */

void start_io(int stat, int fd, char *filename, char mode)
{
    if (mode == 'C' && stat == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
    else if (mode == 'O' && stat == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
        exit(98);
    }
    else if (mode == 'W' && stat == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
        exit(99);
    }
}
