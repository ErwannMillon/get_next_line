#include "get_next_line.h"

char *get_next_line(int fd, char **line)
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
	// if (!buffer)
	// 	return (-1);
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
			result = ft_substr(bigbuffer, 0, nl);
			// printf("result: %s\n", result );
			bigbuffer = ft_substr(bigbuffer, nl + 1, ft_strlen(bigbuffer));
			bytes_read -= ft_strlen(result) + 1;
			return(result);
		}
		else if (check_eof(bigbuffer) >= 0)
		{
			return (bigbuffer);
		}
		else if (check_eof(bigbuffer) == 0)
		{
			return (NULL);
		}
		else
		{
			// printf("before realloc: %s\n", bigbuffer);
			bigbuffer = buf_alloc(bigbuffer, index);
			// printf("after realloc: %s\n", bigbuffer);
			
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			ft_strncat(bigbuffer, buffer, BUFFER_SIZE);

	}
	if (bytes_read == 0)
	{
		free(buffer);
		buffer = NULL;
		return(bigbuffer);
	}
	return (0);
}

// int main(void)
// {
// 	char **test;
// 	int file = open("test", O_RDONLY);
// 	printf("result: %s\n", get_next_line(file, test));
// 	printf("result: %s\n", get_next_line(file, test));
// 	printf("result: %s\n", get_next_line(file, test));
// 	printf("result: %s\n", get_next_line(file, test));
// 	printf("result: %s\n", get_next_line(file, test));
// 	printf("result: %s\n", get_next_line(file, test));
// 	int file2 = open("test2", O_RDONLY);
// 	printf("result: %s\n", get_next_line(file2, test));
// 	printf("result: %s\n", get_next_line(file2, test));
// 	printf("result: %s\n", get_next_line(file2, test));
// 	printf("result: %s\n", get_next_line(file2, test));
// }