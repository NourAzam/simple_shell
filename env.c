#include "shell.h"

/**
 * env - prints the current environment.
 * @x: Structure that contains arguments.
 * Return: Always 0 (Success).
 */
int env(infoX *x)
{
	print_list_str(x->env);
	return (0);
}

/**
 * getenv - gets a value of an environment var.
 * @x: Structure that contains arguments.
 * @name: env var name.
 * Return: The Value.
 */
char *getenv(infoX *x, const char *name)
{
	list_t *node = x->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->str, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * setenv - Initialize new env variable.
 * @x: Structure that contains arguments.
 * Return: Always 0 (Success).
 */
int setenv(infoX *x)
{
	if (x->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (setenv(x, x->argv[1], x->argv[2]))
		return (0);
	return (1);
}

/**
 * unsetenv - Removes an env variable.
 * @x: Structure that contains arguments.
 * Return: Always 0 (Success).
 */
int unsetenv(infoX *x)
{
	int j;

	if (x->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		unsetenv(x, x->argv[i]);

	return (0);
}

/**
 * pop_env - populates environment linked lists.
 * @x: Structure that contains potential arguments.
 * Return: Always 0 (Success).
 */
int pop_env(infoX *x)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	x->env = node;
	return (0);
}
