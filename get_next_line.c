#include "get_next_line.h"

int		end_of_substr(int bytes_read, int nl)
{
	if (bytes_read <= nl)
		return (bytes_read);
	else
		return (nl);
}

char	*get_next_line(int fd)
{
	static int	bytes_read = 0;
	static char	*buffer = NULL;
	static char	*bigbuffer = NULL;
	static int	index = 0;
	int			i;
	int 		nl;
	char		*result;

	i = 0;
	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		bigbuffer = malloc(BUFFER_SIZE + 1);
		bigbuffer[0] = 0;
		buffer[0] = 0;
	}
	if (bigbuffer[0] == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		ft_strncat(bigbuffer, buffer, BUFFER_SIZE);
	}
	while (bytes_read > 0)
	{
		nl = check_nl(bigbuffer);
		if (nl >= 0)
		{
			result = ft_substr(bigbuffer, 0, nl + 1);
			bigbuffer = ft_substr(bigbuffer, nl + 1, ft_strlen(bigbuffer));
			if (!result)
				return (NULL);
			return(result);
		}
		else if (bytes_read == 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == 0)
				return (NULL);
		}
		else
		{
			bigbuffer = buf_alloc(bigbuffer, index);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			ft_strncat(bigbuffer, buffer, BUFFER_SIZE);

	}
	if (bytes_read == 0)
	{
		// printf("bytesread return\n");
		free(buffer);
		buffer = NULL;
		return(NULL);
	}
	return (0);
}

int main(void)
{
	int file = open("test", O_RDONLY);
	printf("result: _%s", get_next_line(file));
	printf("result: _%s", get_next_line(file));
	printf("result: _%s", get_next_line(file));
	printf("result: _%s", get_next_line(file));
	printf("result: _%s", get_next_line(file));
	printf("result: _%s", get_next_line(file));
	printf("result: _%s", get_next_line(file));

	printf("\nnewfile\n");
	int file2 = open("test2", O_RDONLY);
	printf("result: _%s_\n", get_next_line(file2));
	printf("result: _%s_\n", get_next_line(file2));
	printf("result: _%s_\n", get_next_line(file2));
	printf("result: _%s_\n", get_next_line(file2));
	printf("result: _%s_\n", get_next_line(file2));
	printf("result: _%s_\n", get_next_line(file2));
	printf("result: _%s_\n", get_next_line(file2));
	printf("result: _%s_\n", get_next_line(file2));

}