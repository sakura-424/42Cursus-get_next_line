#include "get_next_line_bonus.h"

void ft_init_string(t_string *str)
{
	if (!str)
		return;
	str->str = NULL;
	str->len = 0;
	str->capa = 0;
}

void ft_free_string(t_string *str)
{
	if (!str)
		return;
	if (str->str)
		free(str->str);
	ft_init_string(str);
}

static int expand_buffer(t_string *str)
{
	char *new_str;
	size_t new_capa;
	size_t i;

	i = 0;
	if (str->capa == 0)
        new_capa = 16;
    else
	{
		new_capa = str->capa * 2;
	}
	new_str = malloc(new_capa);
	if (!new_str)
		return (-1);
	while (i < str->len)
	{
		new_str[i] = str->str[i];
		i++;
	}
	if (str->str)
		free(str->str);
	str->str = new_str;
	str->capa = new_capa;
	return (0);
}
int ft_putc(t_string *str, char c)
{
	if (str->len + 1 > str->capa)
	{
		if (expand_buffer(str) == -1)
			return (-1);
	}
	str->str[str->len++] = c;
	return (0);
}

void clean_fd_buffer(int fd)
{
	t_fd_buffer *current;
	t_fd_buffer *prev;
	t_fd_buffer **fd_list_ptr;

	fd_list_ptr = NULL;
	prev = NULL;
	current = get_fd_buffer(-1);
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*fd_list_ptr = current->next;
			free(current);
			break ;
		}
		prev = current;
		current = current->next;
	}
}
