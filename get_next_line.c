/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:13:03 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/08 14:29:26 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		update_line_and_buffer(char **line, char buffer[BUFFER_SIZE + 1])
{
	int	i;

	i = ft_strchr_g(buffer, '\n');
	if (!(*line = ft_joinstr(*line, buffer, i)))
		return (0);
	ft_getsubstr(buffer, i, BUFFER_SIZE - i);
	return (1);
}

int		free_and_exit(char **line, int ret_value)
{
	if (line && *line && ret_value == -1)
	{
		free(*line);
		*line = NULL;
	}
	return (ret_value);
}

int		buffer_is_empty(char *buffer)
{
	if (ft_strlen(buffer) == 0)
		return (1);
	else
		return (0);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (!update_line_and_buffer(line, buffer))
		free_and_exit(line, -1);
	while (buffer_is_empty(buffer))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret <= 0)
			return (free_and_exit(line, ret));
		if (!update_line_and_buffer(line, buffer))
			free_and_exit(line, -1);
	}
	ft_getsubstr(buffer, 1, BUFFER_SIZE - 1);
	return (1);
}