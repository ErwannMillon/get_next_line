#include "get_next_line.h"

int		end_of_substr(int bytes_read, int nl)
{
	if (bytes_read <= nl)
		return (bytes_read);
	else
		return (nl);
}

void	cleanup(char **buffer, char **bigbuffer, char **result, int incbb)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (incbb && *bigbuffer)
	{
		free(*bigbuffer);
		*bigbuffer = NULL;
	}
	if (*result)
	{
		free(*result);
	}
}

void	init_buffers(char **buffer, char **bigbuffer, int *bytes_read, int fd)
{
	if (!*buffer && fd >= 0)
	{
		*buffer = malloc(BUFFER_SIZE + 1);
		*bigbuffer = malloc(BUFFER_SIZE + 1);
		bigbuffer[0][0] = 0;
		buffer[0][0] = 0;
	}
	if (*bigbuffer && bigbuffer[0][0] == 0 && fd >= 0)
	{
		*bytes_read = read(fd, *buffer, BUFFER_SIZE);
		*bigbuffer = buf_alloc(*bigbuffer);
		ft_strncat(*bigbuffer, *buffer, *bytes_read);
	}
}

char	*get_next_line(int fd)
{
	static int	bytes_read = 0;
	static char	*buffer = NULL;
	static char	*bigbuffer = NULL;
	int 		nl;
	int oldfd;
	char		*result;
	
	oldfd = -2;
	result = NULL;
	init_buffers(&buffer, &bigbuffer, &bytes_read, fd);
	if (bytes_read == 0 && fd == oldfd)
		return (NULL);
	// if (bytes_read <= 0 || fd < 0)
	// {
	// 	cleanup(&buffer, &bigbuffer, &result, 1);
	// 	return (NULL);
	// }
	while (bytes_read > 0)
	{
		nl = check_nl(bigbuffer);
		if (nl >= 0)
		{
			result = ft_substr_free(bigbuffer, 0, nl + 1, 0);
			bigbuffer = ft_substr_free(bigbuffer, nl + 1, ft_strlen(bigbuffer), 1);
			// //remove the if !result
			// if (!result || !bigbuffer)
			// 	return (NULL);
			return(result);
		}
		bigbuffer = buf_alloc(bigbuffer);		
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		/*TODO : CHECK IF YOU CAN MERGE THIS CONDITION
		 WITH THE NEXT BYTES READ == 0, TO AVOID DOUBLE FREE*/
		
		if (bytes_read == 0)
		{
			cleanup(&buffer, &bigbuffer, &result, 0);
			return (bigbuffer);
		}
		if (bytes_read > 0)
			ft_strncat(bigbuffer, buffer, bytes_read);
	}
	if (bytes_read == 0)
	{
		oldfd = fd;
		cleanup(&buffer, &bigbuffer, &result, 1);
		buffer = NULL;
		return(NULL);
	}
	return (0);
}

// int main(void)
// {
// 	int file = open("files/multiple_line_no_nl", O_RDONLY);
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	// printf("result: _%s", get_next_line(file));
// 	// printf("result: _%s", get_next_line(file));
// 	// printf("result: _%s", get_next_line(file));
// 	// printf("result: _%s", get_next_line(file));
// 	// printf("result: _%s", get_next_line(file));
// 	// printf("result: _%s", get_next_line(file));

// 	// printf("\nnewfile\n");
// 	// int file2 = open("test2", O_RDONLY);
// 	// printf("result: _%s_\n", get_next_line(file2));
// 	// printf("result: _%s_\n", get_next_line(file2));
// 	// printf("result: _%s_\n", get_next_line(file2));
// 	// printf("result: _%s_\n", get_next_line(file2));
// 	// printf("result: _%s_\n", get_next_line(file2));
// 	// printf("result: _%s_\n", get_next_line(file2));
// 	// printf("result: _%s_\n", get_next_line(file2));
// 	// printf("result: _%s_\n", get_next_line(file2));

// }