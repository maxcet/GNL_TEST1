#include "get_next_line.h"

char	*get_save(char *save)
{
	char	*srch;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	srch = malloc(sizeof(char) * (i + 1));
	if (!srch)
		return (0);
	i++;
	while (save[i])
		srch[j++] = save[i++];
	srch[j] = '\0';
	free(save);
	return (srch);
}

char	*get_line(char *str)
{
	int		i;
	char	*srch;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	srch = malloc(sizeof(char) * (i + 1));
	if (!srch)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		srch[i] = str[i];
		i++;
	}
	srch[i] = '\0';
	return (srch);
}

int	get_n(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i++])
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

int	get_free(int reader, char **buffer)
{
	if (reader == -1)
	{
		free(buffer);
		return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char			*save;
	char				*buffer;
	int					reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (!get_n(save) && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (get_free(reader, &buffer) == -1)
			return (-1);
		buffer[reader] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);
}
