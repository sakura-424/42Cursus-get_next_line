/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skatsuya < skatsuya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:05:20 by skatsuya          #+#    #+#             */
/*   Updated: 2025/06/23 19:05:39 by skatsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

typedef struct s_string
{
	char				*str;
	size_t				len;
	size_t				capa;
}						t_string;

typedef struct s_fd_buffer
{
	int					fd;
	char				buffer[BUFFER_SIZE];
	char				*buf_pos;
	int					bytes_left;
	struct s_fd_buffer	*next;
}						t_fd_buffer;

char					*get_next_line(int fd);
void					ft_init_string(t_string *str);
void					ft_free_string(t_string *str);
int						ft_putc(t_string *str, char c);
t_fd_buffer				*get_fd_buffer(int fd);
void					clean_fd_buffer(int fd);

#endif
