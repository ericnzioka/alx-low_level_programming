#include "main.h"

/**
 * create_file - a function that creates a file
 * @filename: A pointer to the name of the file to create
 * @text_content: A pointer to a string to write to the file
 * Return: i, If the function fails - -1
 **/

int create_file(const char *filename, char *text_content)
{
	int one;
	int win;
	int length;

	length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	one = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	win = write(o, text_content, length);

	if (one == -1 || win == -1)
		return (-1);

	close(one);

	return (1);
}