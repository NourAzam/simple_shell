#include "shell.h"

/**
 * interactional - returns true if shell is interactional mode
 * @x: struct address
 *
 * Return: 1 if interactional mode, 0 otherwise
 */
int interactional(infoX *x)
{
	return (isatty(STDIN_FILENO) && x->readfd <= 2);
}

/**
 * isDelimiter - checks if character is a delimiter
 * @ch: the char to check
 * @delimiter: the delimeter string
 * Return: 1 if true, 0 if false
 */
int isDelimiter(char ch, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == ch)
			return (1);
	return (0);
}

/**
 * isAlpha - checks for alphabetic character
 * @ch: The character to input
 * Return: 1 if ch is alphabetic, 0 otherwise
 */
int isAlpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * StrToInt - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int StrToInt(char *str)
{
	int i, f = 1, flag = 0, output;
	unsigned int res = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			f *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			flag = 1;
		}
		else if (flag == 1)
			flag = 2;
	}

	if (f == -1)
		output = -res;
	else
		output = res;

	return (output);
}
