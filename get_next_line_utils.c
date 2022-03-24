#include "get_next_line.h"

int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != EOF))
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	while (src[i])
	{
        dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*buf_alloc(char *old, int nth)
{
	char		*new;
	static int	size = 1;
	// if (!nth)
	// 	size = BUFFER_SIZE;
	// else
	// 	size += BUFFER_SIZE;
	(void)nth;
	size += BUFFER_SIZE;
	new = malloc(size + 1);
	ft_strcpy(new, old);
	free(old);
	return(new);
}



int check_eof(char *buffer)
{
	int	i;
	
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == EOF)
			return (i);
		i++;
	}
	return(-1);
}

int check_nl(char *buffer)
{
	int	i;
	int eof;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	eof = check_eof(buffer);
	if (eof >= 0)
		return (eof);
	return(-1);
}

char *ft_strncat(char *dest, char *src, int n)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j] && j < n && (src[j] != EOF))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i+j] = 0;
	return (dest);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (s[start + i] && i < len)
		i++;
	sub = malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}