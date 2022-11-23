#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **commands;

size_t _getline(char **buffer, size_t *len, FILE *stream);
char **toklist(char *command, char *delim);
int _executer(char **args);
int is_delim(const char *delims, char str);
char *_strtok(char *str, char *delim, char **backup);
void *_realloc(void *ptr, unsigned int cursize, unsigned int newsize);
void free_tokens(char ***tokens);

int _strlen(char *str);
char *_strcat(char *dest, char *src);
void _strcpy(char *src, char *dest);
int _strspn(char *s1, char *s2);
char *_strchr(char *str, char c);
int _strcspn(char *s1, char *s2);
void rmnewl(char *str);

#endif
