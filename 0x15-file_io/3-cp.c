#include "main.h"
#define FULL_SIZE 1024
/**
 * error_file - can be opened? check.
 * @source_of_file: source_of_file
 * @file_to: file_to
 * @argv: arguments vector
 * dprintf - writing
 * Return: return nothing
 **/

void error_file(int source_of_file, int file_to, char *argv[])
{
	if (source_of_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check and run the code
 * @argc: has number of arguments
 * @argv: the arguments vector
 * Return: 0 always
 **/

int main(int argc, char *argv[])
{
	int source_of_file;
	int dest_of_file;
	int errorclose;
	ssize_t nchars;
	ssize_t nwr;

	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp source_of_file file_to");
		exit(97);
	}

	source_of_file = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(source_of_file, file_to, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(source_of_file, buf, 1024);
		if (nchars == -1)
			error_file(-1, 0, argv);
		nwr = write(file_to, buf, nchars);
		if (nwr == -1)
			error_file(0, -1, argv);
	}

	errorclose = close(source_of_file);
	if (errorclose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_of_file);
		exit(100);
	}

	errorclose = close(file_to);
	if (errorclose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_of_file);
		exit(100);
	}
	return (0);
}