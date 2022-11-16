#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

size_t _getline(char **buffer, size_t *len, FILE *stream);
char **toklist(char *command, char *delim);
int _executer(char **args);
int is_delim(const char *delims, char str);
char *_strtok(char *str, const char *delim, char **backup);
void *_realloc(void *ptr, unsigned int cursize, unsigned int newsize);

#endif
