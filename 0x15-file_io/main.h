#ifndef MAIN_H
#define MAIN_H

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void start_io(int stat, int fd, char *filename, char mode);
ssize_t read_textfile(const char *filename, size_t letters);
int _strlen(char *s);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void copy_file(const char *src, const char *dest);

void see_elf(unsigned char *identity);
void printing_new_stuff(unsigned char *identity);
void printing_new_clas(unsigned char *identity);
void data_display(unsigned char *identity);
void version_display(unsigned char *identity);
void magic_display(unsigned char *identity);
void osac_display(unsigned char *identity);
void tpes_display(unsigned int e_type, unsigned char *identity);
void entrypoint_display(unsigned long int e_entry, unsigned char *identity);
void ending(int elf);

#endif
