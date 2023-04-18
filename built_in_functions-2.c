#include "shell.h"

/**
 * History - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @x: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int History(infoX *x)
{
	print_list(x->history);
	return (0);
}

/**
 * unsetAlias - sets alias to string
 * @x: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unsetAlias(infoX *x, char *str)
{
	char *ptr, ch;
	int rt;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	ch = *ptr;
	*ptr = 0;
	rt = delete_node_at_index(&(x->alias),
		get_node_index(x->alias, node_starts_with(x->alias, c, -1)));
	*ptr = ch;
	return (rt);
}

/**
 * setAlias - sets alias to string
 * @x: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int setAlias(infoX *x, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(x, str));

	unsetAlias(x, str);
	return (add_node_end(&(x->alias), str, 0) == NULL);
}

/**
 * printAlias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int printAlias(list_t *node)
{
	char *ptr = NULL, *temp = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (temp = node->str; temp <= ptr; temp++)
		_putchar(*temp);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * Alias - mimics the alias builtin (man alias)
 * @x: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int Alias(infoX *x)
{
	int idx = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (x->argc == 1)
	{
		node = x->alias;
		while (node)
		{
			printAlias(node);
			node = node->next;
		}
		return (0);
	}
	for (idx = 1; x->argv[idx]; idx++)
	{
		ptr = _strchr(info->argv[idx], '=');
		if (ptr)
			setAlias(x, x->argv[idx]);
		else
			printAlias(node_starts_with(x->alias, x->argv[idx], '='));
	}

	return (0);
}
