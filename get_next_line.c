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

static char	*update_buffer(char *buffer)
{
	int start;
	char *temp;
	
	start = ft_strchr_g(buffer, '\n');
	temp = ft_substr(buffer, start, BUFFER_SIZE - start);
	free (buffer);
	buffer = temp;
	return (buffer);
}

static char *update_line_and_buffer(char **line, char *buffer)
{	
	int	i;
	

	// printf("line1 : '%s' buffer1 : '%s'\n", *line, buffer);
	i = ft_strchr_g(buffer, '\n');
	// printf("line2 : '%s' buffer2 : '%s'\n", *line, buffer);
	*line = ft_strjoin(*line, buffer, i);
	//printf("line3 : '%s' buffer3 : '%s'\n", *line, buffer);
	buffer = update_buffer(buffer);
	//printf("line4 : '%s' buffer4 : '%s'\n", *line, buffer);
	return (buffer);
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
	static char *buffer;

	//printf("***START OF GNL***\n");

	//printf("line : '%s' buffer : '%s'\n", *line, buffer);
	*line = NULL;
	
	if (fd == -1 || !line || BUFFER_SIZE <= 0)
	{   
		if (buffer)
			free(buffer);
		return (-1);
	}
	
	buffer = update_line_and_buffer(line, buffer);
	//printf("\n");
	while (buffer_is_empty(buffer))
	{
		// if (buffer == NULL)
		buffer = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buffer == NULL)
		{
			return (-1);
		}
		//printf("line : '%s' buffer : '%s'\n", *line, buffer);
		ret = read(fd, buffer, BUFFER_SIZE);
		//printf("%d\n", ret);
		//printf("line : '%s' buffer : '%s'\n", *line, buffer);
		if (ret <= 0)
		{
			free(buffer);
			buffer = NULL;
			return (ret);
		}
		buffer = update_line_and_buffer(line, buffer);
		//printf("line : '%s' buffer : '%s'\n", *line, buffer);
	}
	buffer = ft_substr(buffer, 1, BUFFER_SIZE - 1);
	free(buffer);
	//printf("line : '%s' buffer : '%s'\n", *line, buffer);
	//printf("***END OF GNL***\n");
	return (1);	
}

// int main ()
// {
// 	int fd;
// 	char *line;
// 	int r;

// 	fd = open ("file.txt", O_RDONLY);
// 	//get_next_line(fd, &line);
// 	while ((r = get_next_line (fd, &line)) > 0)
// 	{   
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 		free(line);

// 	return (0);
// }
int	main(int ac, char **av)
{
	char *line;
	int fd;
	int ret;
	int countline;

	countline = 1;
	if (ac == 1)
		fd = 0;
	if (ac >= 2)
		fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line))==1)
	{
		printf("line. %d = %s - [%d]\n", countline, line, ret);
		free(line);
		line = NULL;
		countline++;
	}
	printf("line %d = %s - [%d]\n", countline, line, ret);
	free(line);
		line = NULL;
	printf("\nTest de LEAKS\n");
	system("leaks a.out | grep leaked\n"); 
	return 0;
}