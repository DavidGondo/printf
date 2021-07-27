#ifndef HOLBERTON_PRINTF_PROJECT_H
#define HOLBERTON_PRINTF_PROJECT_H

int a_strlen(const char *str);
char *_strncpy(char *dest, char *src);
char *_string_rev(char *str);
char *itoa(int i, char *strout, int base);
int _printf(const char *format, ...);

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#endif /* HOLBERTON_PRINTF_PROJECT_H */
