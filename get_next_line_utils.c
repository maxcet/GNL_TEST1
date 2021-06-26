#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dst == src)
		return (dst);
	if (source < dest)
	{
		while (len--)
			*(dest + len) = *(source + len);
		return (dst);
	}
	while (len--)
		*dest++ = *source++;
	return (dst);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	len_str1;
	size_t	len_str2;
	size_t	len;
	char	*srch;

	if (!str1 && !str2)
		return (0);
	len_str1 = ft_strlen((char *)str1);
	len_str2 = ft_strlen((char *)str2);
	len = len_str1 + len_str2 + 1;
	srch = malloc(sizeof(char) * len);
	if (!srch)
		return (0);
	ft_memmove(srch, str1, len_str1);
	ft_memmove(srch + len_str1, str2, len_str2);
	srch[len - 1] = '\0';
	free((char *)str1);
	return (srch);
}

int	get_n(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}
