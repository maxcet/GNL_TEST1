#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int			get_next_line(int fd, char **line);
int			get_n(char *str);
int			get_free(int reader, char **buffer);

size_t		ft_strlen(const char *str);

char		*ft_strnew(size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_save(char *save);
char		*get_line(char *str);

#endif