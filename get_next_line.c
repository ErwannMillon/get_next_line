/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 04:23:06 by gmillon           #+#    #+#             */
/*   Updated: 2022/03/27 04:23:17 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_of_substr(int bytes_read, int nl)
{
	if (bytes_read <= nl)
		return (bytes_read);
	else
		return (nl);
}

int	cleanup(char **buff, char **bigbuff, char **result)
{
	if (buff && *buff)
	{
		free(*buff);
		*buff = NULL;
	}
	if (bigbuff && *bigbuff)
	{
		free(*bigbuff);
		*bigbuff = NULL;
	}
	if (result && *result)
	{
		free(*result);
	}
	return (1);
}

void	init_buffers(char **buff, char **bigbuff, int *bytes_read, int fd)
{
	if (!*buff && fd >= 0)
	{
		*buff = malloc(BUFFER_SIZE + 1);
		*bigbuff = malloc(BUFFER_SIZE + 1);
		bigbuff[0][0] = 0;
		buff[0][0] = 0;
	}
	if (*bigbuff && bigbuff[0][0] == 0 && fd >= 0)
	{
		*bytes_read = read(fd, *buff, BUFFER_SIZE);
		*bigbuff = buf_alloc(*bigbuff);
		ft_strncat(*bigbuff, *buff, *bytes_read);
	}
}

char	*seek_loop(int fd, int *b_read, char **bigbuff, char **buff)
{
	int		nl;
	char	*res;

	res = NULL;
	while (*b_read > 0)
	{
		nl = check_nl(*bigbuff);
		if (nl >= 0)
		{
			res = ft_substr_free(*bigbuff, 0, nl + 1, 0);
			*bigbuff = ft_substr_free(*bigbuff, nl + 1, ft_strlen(*bigbuff), 1);
			return (res);
		}
		*bigbuff = buf_alloc(*bigbuff);
		*b_read = read(fd, *buff, BUFFER_SIZE);
		if (*b_read == 0)
		{
			cleanup(buff, NULL, &res);
			return (*bigbuff);
		}
		if (*b_read > 0)
			ft_strncat(*bigbuff, *buff, *b_read);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static int	bytes_read = 0;
	static char	*buff = NULL;
	static char	*bigbuff = NULL;
	char		*returnval;

	init_buffers(&buff, &bigbuff, &bytes_read, fd);
	if ((bytes_read <= 0 || fd < 0) && cleanup(&buff, &bigbuff, NULL))
		return (NULL);
	returnval = seek_loop(fd, &bytes_read, &bigbuff, &buff);
	if (returnval)
		return (returnval);
	if (bytes_read == 0 && cleanup(&buff, &bigbuff, &returnval))
		return (NULL);
	return (0);
}

// int main(void)
// {
// 	int file = open("files/multiple_line_no_nl", O_RDONLY);
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));
// 	printf("result: _%s", get_next_line(file));

// 	printf("\nnewfile\n");
// 	int file2 = open("test2", O_RDONLY);
// 	printf("result: _%s_\n", get_next_line(file2));
// 	printf("result: _%s_\n", get_next_line(file2));
// 	printf("result: _%s_\n", get_next_line(file2));
// 	printf("result: _%s_\n", get_next_line(file2));
// 	printf("result: _%s_\n", get_next_line(file2));
// 	printf("result: _%s_\n", get_next_line(file2));
// 	printf("result: _%s_\n", get_next_line(file2));
// 	printf("result: _%s_\n", get_next_line(file2));

// }
