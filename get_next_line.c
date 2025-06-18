#include "get_next_line.h"

static char *clean_and_return(t_string *line, char *ret_val)
{
	ft_free_string(line);
	return (ret_val);
}

char *get_next_line(int fd)
{
	t_string line;
	int c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_init_string(&line);
	while ((c = ft_getc(fd)) != EOF)
	{
		if (ft_putc(&line, (char)c) == -1)
			return (clean_and_return(&line, NULL));
		if (c == '\n')
			break;
	}
	if (line.len == 0)
		return (clean_and_return(&line, NULL));
	if (ft_putc(&line, '\0') == -1)
		return (clean_and_return(&line, NULL));
	return (line.str);
}

#include <fcntl.h>
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("Error: open\n"), 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("<bos>%s<eos>", line);
		free(line);
	}
	line = get_next_line(fd);  // should be NULL
	printf("%s<eos>\n", line);
	free(line);
	return (0);
}
