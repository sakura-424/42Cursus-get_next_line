#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

# if BUFFER_SIZE > INT_MAX
#  define BUFFER_SIZE INT_MAX
# endif

typedef struct s_string {
    char *str;
    size_t len;
    size_t capa;
} t_string;

char *get_next_line(int fd);

int ft_getc(int fd);
int ft_putc(t_string *str, char c);
void ft_init_string(t_string *str);
void ft_free_string(t_string *str);

#endif
