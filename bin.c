#include "shell.h"

/**
 * exit - exits the shell
 * @info: Struct that contains arguments.
 * Return: 0 if info.argv[0] != "exit".
 */
int exit(info_t *info)
{
	int ex_check;

	if (info->argv[1])
	{
		ex_check = _erratoi(info->argv[1]);
		if (ex_check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * cd - changes the current working directory of the process.
 * @info: Struct that contains arguments.
 * Return: Always 0
 */
int cd(info_t *info)
{
	char *str, *direc, buffer[1024];
	int cd_r;

	str = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		direc = _getenv(info, "HOME=");
		if (!direc)
			cd_r = /* TODO: what should this be? */
				chdir((direc = _getenv(info, "PWD=")) ? direc : "/");
		else
			cd_r = chdir(direc);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cd_r =
			chdir((direc = _getenv(info, "OLDPWD=")) ? direc : "/");
	}
	else
		cd_r = chdir(info->argv[1]);
	if (cd_r == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help - changes the current working directory of the process.
 * @info: Struct that contains arguments.
 * Return: Always 0
 */
int help(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
