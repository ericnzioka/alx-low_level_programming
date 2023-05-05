#include "main.h"

/**
 * get_bit: a function that returns the value of a bit at a given index.
 * @n: number to  be evaluated
 * @index: index 
 * Return: Value of bit at index, or -1 if error occured.
**/

int get_bit(unsigned long int n, unsigned int index)
{
    const unsigned int MAX_INDEX = sizeof(unsigned long int) * 8 - 1; 
    if (index > MAX_INDEX)
    {
        return -1; 
    }
    unsigned long int mask = 1UL << index;
    return (n & mask) ? 1 : 0;
}
