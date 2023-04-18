#include "shell.h"

/**
 * exit - exits the shell
 * @x: Struct that contains arguments.
 * Return: 0 if x.argv[0] != "exit".
 */
int exit(infoX *x)
{
	int ex_check;

	if (x->argv[1])
	{
		ex_check = _erratoi(x->argv[1]);
		if (ex_check == -1)
		{
			x->status = 2;
			print_error(x, "Illegal number: ");
			_eputs(x->argv[1]);
			_eputchar('\n');
			return (1);
		}
		x->err_num = _erratoi(x->argv[1]);
		return (-2);
	}
	x->err_num = -1;
	return (-2);
}

/**
 * cd - changes the current working directory of the process.
 * @x: Struct that contains arguments.
 * Return: Always 0
 */
int cd(infoX *x)
{
	char *str, *direc, buffer[1024];
	int cd_r;

	str = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!x->argv[1])
	{
		direc = _getenv(x, "HOME=");
		if (!direc)
			cd_r = /* TODO: what should this be? */
				chdir((direc = _getenv(x, "PWD=")) ? direc : "/");
		else
			cd_r = chdir(direc);
	}
	else if (_strcmp(x->argv[1], "-") == 0)
	{
		if (!_getenv(x, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(x, "OLDPWD=")), _putchar('\n');
		cd_r =
			chdir((direc = _getenv(x, "OLDPWD=")) ? direc : "/");
	}
	else
		cd_r = chdir(x->argv[1]);
	if (cd_r == -1)
	{
		print_error(x, "can't cd to ");
		_eputs(x->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(x, "OLDPWD", _getenv(x, "PWD="));
		_setenv(x, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help - changes the current working directory of the process.
 * @x: Struct that contains arguments.
 * Return: Always 0
 */
int help(infoX *x)
{
	char **arg_arr;

	arg_arr = x->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
