/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:09:57 by gmillon           #+#    #+#             */
/*   Updated: 2022/03/27 03:16:55 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main (int argc, char **argv)
{
// 	if (argc < 2)
// 		return (printf("error args\n"));
	int fd = open ("files/multiple_line_no_nl", O_RDONLY);
	char *line  =get_next_line(fd);

	while (line)
	{
		printf("%s", line);
		printf("\nfinished\n");
		free(line);
		line = get_next_line(fd);
	}
	// 	int file = open("files/multiple_line_no_nl", O_RDONLY);
	// printf("result: _%s", get_next_line(file));
	// printf("result: _%s", get_next_line(file));
	// printf("result: _%s", get_next_line(file));
	// printf("result: _%s", get_next_line(file));
	// printf("result: _%s", get_next_line(file));
	// printf("result: _%s", get_next_line(file));
	// printf("result: _%s", get_next_line(file));
	// printf("result: _%s", get_next_line(file));
	// printf("result: _%s", get_next_line(file));

	// printf("\nnewfile\n");
	int file2 = open("test2", O_RDONLY);
	line  =get_next_line(file2);
	while (line)
	{
		printf("%s", line);
		printf("\nfinished\n");
		free(line);
		line = get_next_line(file2);
	}
	// printf("result: _%s_\n", get_next_line(file2));
	// printf("result: _%s_\n", get_next_line(file2));
	// printf("result: _%s_\n", get_next_line(file2));
	// printf("result: _%s_\n", get_next_line(file2));
	// printf("result: _%s_\n", get_next_line(file2));
	// printf("result: _%s_\n", get_next_line(file2));
	// printf("result: _%s_\n", get_next_line(file2));
	// printf("result: _%s_\n", get_next_line(file2));
	printf("\n=====================================================================\n");
	system("leaks a.out");
	
}
