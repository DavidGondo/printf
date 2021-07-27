#include "holberton.h"
#include <string.h>
#include <stdio.h>

/**
 *_printf - unction that produces output according to a format
 *@format: format specifier.
 *
 *Return: total number of characters printed.
 */

int _printf(const char *format, ...)
{
va_list ap;
int i = 0,  j = 0, alloc = 1024 ;
char *str;
char *temp;
char *string_copy;

va_start(ap, format); 
str = malloc(sizeof(char) * alloc);
temp = malloc(sizeof(char) * alloc / 2);
if (str == NULL || temp == NULL)
{
free(str);
free(temp);
return (-1);
}

while (format && format[i])
{
if(format[i] == '%')
{
i++;
switch (format[i])
{
case 'c': 
{
str[j] = (char)va_arg(ap, int );
j++;
break;
}
case 's': 
{
string_copy = va_arg(ap, char*);
_strncpy(&str[j], string_copy);
j += _strlen(string_copy);
break;
}
case 'd': 
{
itoa(va_arg(ap, int), temp, 10);
_strncpy(&str[j], temp);
j += _strlen(temp);
break;
}
case 'i': 
{
itoa(va_arg(ap, int), temp, 10);
_strncpy(&str[j], temp);
j += _strlen(temp);
break;
}

/*case 'x': 
{
itoa(va_arg(ap, int), temp, 16);
_strncpy(&str[j], temp);
j += _strlen(temp);
break;
}
case 'u': 
{
itoa(va_arg(ap, int), temp, 10);
_strncpy(&str[j], temp);
j += _strlen(temp);
break;
}
case 'o': 
{
itoa(va_arg(ap, int), temp, 8);
_strncpy(&str[j], temp);
j += _strlen(temp);
break;
}
case 'p':
{
string_copy = va_arg(ap, char*);
_strncpy(&str[j], string_copy);
j += _strlen(string_copy);
break;
}
*/

case '%':
{
str[j] = '%';
j++;
break;
}
default:
{
str[j] = '%';
j++;
break;
}
}
}
else
{
str[j] = format[i];
j++;
}
i++;
}

fwrite(str, j, stdout); 
va_end(ap);
return j;
}
