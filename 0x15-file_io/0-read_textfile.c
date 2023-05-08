#include "main.h"

/**
 * read_textfile - a function that reads a text file and prints it to the POSIX standard output.
 * @filename: is the source file
 * @letters: is the number of letters to reads and prints
 * Return: 0 if the function fails is NULL
 **/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int den;
	int ten;
	char *mem;

	*mem = malloc(sizeof(char *) * letters);

	if (!mem)
		return (0);

	if (!filename)
		return (0);

	den = open(filename, O_RDONLY, 0600);
	if (den == -1)
		return (0);

	ten = read(den, mem, letters);
	write(STDOUT_FILENO, mem, ten);

	free(mem);
	close(den);
	return (ten);
}