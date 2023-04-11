#include "main.h"

/**
 *binary_to_uint - convert a binary number to unsigned int
 *@b:a pointer to a string of 0 & 1 chars
 *result: converted int
 *Return: converted number or if b is NULL or contains chars not 0 or 1 - 0.
 */

unsigned int binary_to_uint(const char *b) {
    unsigned int result = 0;
    int len;

    if (b == NULL) {
        return 0;
    }

    len = strlen(b);
    for (int i = 0; i < len; i++) {
        if (b[i] == '0') {
            result = (result << 1) | 0;
        } else if (b[i] == '1') {
            result = (result << 1) | 1;
        } else {
            // Invalid character in input string
            return 0;
        }
    }

    return result;
}
