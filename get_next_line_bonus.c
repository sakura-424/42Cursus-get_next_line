/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skatsuya < skatsuya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:03:11 by skatsuya          #+#    #+#             */
/*   Updated: 2025/06/23 19:29:40 by skatsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*clean_and_return(t_string *line, char *ret_val)
{
	ft_free_string(line);
	return (ret_val);
}

t_fd_buffer	*get_fd_buffer(int fd)
{
	static t_fd_buffer	*fd_list;
	t_fd_buffer			*current;
	t_fd_buffer			*new_node;

	fd_list = NULL;
	current = fd_list;
	while (current && current->fd != fd)
		current = current->next;
	if (current)
		return (current);
	new_node = malloc(sizeof(t_fd_buffer));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->bytes_left = 0;
	new_node->next = fd_list;
	fd_list = new_node;
	return (new_node);
}

static int	ft_getc_bonus(int fd)
{
	t_fd_buffer	*buffer;

	buffer = get_fd_buffer(fd);
	if (!buffer)
		return (EOF);
	if (buffer->bytes_left <= 0)
	{
		buffer->bytes_left = read(fd, buffer->buffer, BUFFER_SIZE);
		if (buffer->bytes_left <= 0)
			return (EOF);
		buffer->buf_pos = buffer->buffer;
	}
	buffer->bytes_left--;
	return ((unsigned char)*buffer->buf_pos++);
}

char	*get_next_line(int fd)
{
	t_string	line;
	int			c;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	ft_init_string(&line);
	c = ft_getc_bonus(fd);
	while (c != EOF)
	{
		if (ft_putc(&line, (char)c) == -1)
			return (clean_and_return(&line, NULL));
		if (c == '\n')
			break ;
		c = ft_getc_bonus(fd);
	}
	if (line.len == 0)
		return (clean_and_return(&line, NULL));
	if (ft_putc(&line, '\0') == -1)
		return (clean_and_return(&line, NULL));
	return (line.str);
}
