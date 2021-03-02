/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:43:12 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/17 11:38:49 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char* ft_malloctail(void)
{
	char *dest;

	if(!(dest = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	dest = NULL;
	return (dest);
}

static int		find_n(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n')
	{
		i++;
	}
	return (i);
}

int get_next_line(int fd, char **line)
{
	int i;
	int ret;
	static char *tail;
	char *temp;
	char buf[BUFFER_SIZE + 1];

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);	
	if (tail == NULL)
	{
		tail = ft_malloctail();
	}
	i = 0;
	if ((ft_strchr_g(tail, '\n')))
	{
		i = find_n(tail);
		*line = ft_substr(tail, 0, i);
		temp = tail;
		tail = ft_strdup(&tail[i + 1]);
		if (temp)
			free(temp);
		return (1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{   
        if (ret < 0)
        {
            free(tail);
            return(-1);
        }
		 (buf[ret] = '\0');
		 temp = tail;
		 tail = ft_strjoin(tail, buf);
		 free(temp);
		 if ((ft_strchr_g(tail, '\n')))
		 {
			 i = find_n(tail);
			 *line = ft_substr(tail, 0, i);
			 temp = tail;
			 tail = ft_strdup(&tail[i + 1]);
			if (temp)
				free(temp);
			 return (1);
		 }
	}
	if (tail)
		free(tail);
	return (0);		
}
