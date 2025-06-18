#include "get_next_line.h"

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

	if (str->capa == 0)
        new_capa = 16;
    else
        new_capa = str->capa * 2;
	new_str = malloc(new_capa);
	if (!new_str)
		return (-1);
	i = 0;
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

int ft_getc(int fd)
{
	static char buf[BUFFER_SIZE];
	static char *bufp;
	static int n = 0;

	if (n <= 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			return (EOF);
		bufp = buf;
	}
	n--;
	return ((unsigned char)*bufp++);
}
