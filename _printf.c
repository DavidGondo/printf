#include "holberton.h"
#include <string.h>
/**
 *_printf - unction that produces output according to a format
 *@format: format specifier.
 *
 *Return: total number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int a = 0, b = 0, alloc;
	char *string, *temp;
	char *string_copy;

	va_start(valist, format);
	alloc = 1024;
	string = malloc(sizeof(char) * alloc);
	temp = malloc(sizeof(char) * alloc / 2);
	if (string == NULL || temp == NULL)
	{
		free(string);
		free(temp);
		return (-1);
	}
	while (format && format[a])
	{
		if (format[a] == '%')
		{
			a++;
			switch (format[a])
			{
				case 'c':
					string[b] = (char)va_arg(valist, int);
					b++;
					break;
				case 's':
					string_copy = va_arg(valist, char*);
					_strncpy(&string[b], string_copy);
					b +=strlen(string_copy);
					break;
				case '%':
					string[b] = '%';
					b++;
					break;
				case 'd':
					itoa(va_arg(valist, int), temp, 10);
					_strncpy(&string[b], temp);
					b +=strlen(temp);
					break;
				case 'i':
					itoa(va_arg(valist, int), temp, 10);
					_strncpy(&string[b], temp);
					b +=strlen(temp);
					break;
			}
		}
		else
		{
			string[b] = format[a];
			b++;
		}
		a++;
	}
	write(1, string, b);
	va_end(valist);
	return (b);
}
