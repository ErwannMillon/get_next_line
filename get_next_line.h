#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
// #define	BUFFER_SIZE 9999
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
char	*buf_alloc(char *old, int nth);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int 	check_nl(char *buffer);
int 	check_eof(char *buffer);
char	*ft_strcpy(char *dest, char *src);
char 	*ft_strncat(char *dest, char *src, int n);
int		ft_strlen(char *s);
char 	*get_next_line(int fd);

#endif