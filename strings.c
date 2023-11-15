#include "shell.h"

/**
 * num_to_string - converts a number into a string
 * @num: number to convert
 * @str: char array to store the converted number
 */
void num_to_string(char *str, int num)
{
	int j, i = 0;

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	/* Reverse the string */
	for (j = 0; j < i / 2; j++)
	{
		char temp = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}

	/* Add null terminator at the end */
	str[i] = '\0';
}

/**
 * _strlen - returns the number of characters in a string
 * @str: string to count the chars from
 *
 * Return: number of characters
 */
int _strlen(const char *str)
{
	int len = 0;

	if (str == NULL)
	{
		return (0);
	}

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strncmp - compares the first n characters of two strings
 * @first_str: first string
 * @second_str: second string
 * @n: number of characters to check
 *
 * Return: 0 if the first n characters are equal,
 * otherwise difference between the ASCII values of the differing characters
 */
int _strncmp(char *first_str, char *second_str, int n)
{
	int i = 0;

	while (n > 0 && first_str[i] && (first_str[i] == second_str[i]))
	{
		i++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return ((unsigned char) first_str[i] - (unsigned char) second_str[i]);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: duplicated string
 */
char *_strdup(const char *str)
{
	char *duplicate;
	int len, i;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	duplicate = malloc(sizeof(char) * (len + 1));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		duplicate[i] = str[i];
	}

	duplicate[i] = '\0';
	return (duplicate);
}

/**
 * _concatenate - concatenates strings
 * @str1: first string
 * @str2: second string
 * @str3: third string
 *
 * Return: pointer to the newly allocated string
 */
char *_concatenate(char *str1, char *str2, char *str3)
{
	int len;
	char *new_str;

	len = _strlen(str1) + _strlen(str2) + _strlen(str3);

	new_str = malloc(len * sizeof(char));
	if (new_str)
	{
		_strcpy(new_str, str1);
		_strcat(new_str, str2);
		_strcat(new_str, str3);
	}

	return (new_str);
}
