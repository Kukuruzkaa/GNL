/* ************************************************************************** */
/*											                                  */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:06:53 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/17 15:12:45 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void update_buffer(char buffer[BUFFER_SIZE + 1])
{
	int start;
	
	start = ft_strchr_g(buffer, '\n');
	ft_substr(buffer, start, BUFFER_SIZE - start);
}

void update_line_and_buffer(char **line, char buffer[BUFFER_SIZE + 1])
{	
	int	i;
	
	i = ft_strchr_g(buffer, '\n');
	*line = ft_strjoin(*line, buffer, i);
	update_buffer(buffer);
}

static int	buffer_is_empty(char *buffer)
{
	if (ft_strlen(buffer) == 0)
		return (1);
	else 
		return (0);
}

int get_next_line(int fd, char **line)
{
	int ret;
	static char buffer[BUFFER_SIZE + 1];

	*line = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
	{   
		return (-1);
	}
	update_line_and_buffer(line, buffer);
	while (buffer_is_empty(buffer))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret <= 0)
		{
			return (ret);
		}
		update_line_and_buffer(line, buffer);
	}
	ft_substr(buffer, 1, BUFFER_SIZE - 1); // Retire le char '\n'
	return (1);	
}

// // int main ()
// // {
// // 	int fd;
// // 	char *line;
// // 	int r;

// // 	fd = open ("file.txt", O_RDONLY);
// // 	//get_next_line(fd, &line);
// // 	while ((r = get_next_line (fd, &line)) > 0)
// // 	{   
// // 		printf("%s\n", line);
// // 		free(line);
// // 	}
// // 	printf("%s\n", line);
// // 		free(line);

// // 	return (0);
// // }
// int	main(int ac, char **av)
// {
// 	char *line;
// 	int fd;
// 	int ret;
// 	int countline;

// 	countline = 1;
// 	if (ac == 1)
// 		fd = 0;
// 	if (ac >= 2)
// 		fd = open(av[1], O_RDONLY);
// 	while ((ret = get_next_line(fd, &line))==1)
// 	{
// 		printf("line. %d = %s - [%d]\n", countline, line, ret);
// 		free(line);
// 		line = NULL;
// 		countline++;
// 	}
// 	printf("line %d = %s - [%d]\n", countline, line, ret);
// 	free(line);
// 		line = NULL;
// 	printf("\nTest de LEAKS\n");
// 	system("leaks a.out | grep leaked\n"); 
// 	return 0;
// }