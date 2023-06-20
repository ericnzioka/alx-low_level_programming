#include "main.h" 
#include <unistd.h>
/*
 * _putchar: takes a char (one byte) as argument  and prints it to standard output
 * @c: argument contains the character to be printed
 * (1, &c, 1): 1 he file descriptor of the stream to write to. The standard output stream.
 * 		&c, takes the address of variable
 * 		1, the number of bytes
 * Return: printed
 */

int _putchar(char c)
{
	return (write (1, &c, 1));
}
