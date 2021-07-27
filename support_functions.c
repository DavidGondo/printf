#include "holberton.h"

/**
 * _strlen - finds length of a string
 * @str: first parameter
 *
 * Description: finds len of string
 * Return: strings length
 */

int _strlen(const char *str)
{
	int len = 0;

	for (; str[len] != '\0'; len++)
	{
	}

	return (len);
}

/**
 * _strncpy - creates copy of a string
 * @dest: first parameter
 * @src: second parameter
 *
 * Description: creates copy of string
 * Return: copy of a string
 */
char *_strncpy(char *dest, char *src)
{
	int i = 0;
	int len = 0;

	for (; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
		len++;
	}

	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

/**
 * _string_rev - reverses a string incuding the null terminating character
 *as part of the reversed string.
 * @str: first parameter
 *
 * Description: reverses a string
 * Return: reverse string
 */
char *_string_rev(char *str)
{
	int i;
	int len = 0;
	char temp;

	if (!str)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < (len / 2); i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return (str);
}

/**
 * itoa - converts integer to string type
 * @i: first parameter
 * @strout: second parameter
 * @base: third parameter
 *
 * Description: converts integer to string type
 * Return: string type
 */
char *itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}

	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}

	if (sign)
	{
		*str++ = '-';
	}

	*str = '\0';
	_string_rev(strout);
	return (strout);
}
