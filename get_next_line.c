/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skatsuya < skatsuya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:55:48 by skatsuya          #+#    #+#             */
/*   Updated: 2025/06/23 19:29:22 by skatsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_and_return(t_string *line, char *ret_val)
{
	ft_free_string(line);
	return (ret_val);
}

char	*get_next_line(int fd)
{
	t_string	line;
	int			c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_init_string(&line);
	c = ft_getc(fd);
	while (c != EOF)
	{
		if (ft_putc(&line, (char)c) == -1)
			return (clean_and_return(&line, NULL));
		if (c == '\n')
			break ;
		c = ft_getc(fd);
	}
	if (line.len == 0)
		return (clean_and_return(&line, NULL));
	if (ft_putc(&line, '\0') == -1)
		return (clean_and_return(&line, NULL));
	return (line.str);
}

// #include <fcntl.h>
// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	char	*line;

// 	if (argc != 2)
// 		return (1);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (printf("Error: open\n"), 1);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("<bos>%s<eos>", line);
// 		free(line);
// 	}
// 	line = get_next_line(fd);  // should be NULL
// 	printf("%s<eos>\n", line);
// 	free(line);
// 	return (0);
// }

// #include <fcntl.h>
// #include <stdlib.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     // ファイル名が引数でもらえているかチェック
//     if (argc < 2)
//     {
//         printf("Usage: %s <filename>\n", argv[0]);
//         return (1);
//     }

//     // ファイルを読み込み用でオープン
//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return (1);
//     }

//     // 1行ずつget_next_lineで読み込んで出力
//     // while ((line = get_next_line(fd)) != NULL)
//     // {
//     //     printf("%s", line);
//     //     free(line);
//     // }
// 	if ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }
