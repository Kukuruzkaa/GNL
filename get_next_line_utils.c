/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:06:59 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/11 16:01:19 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		length;
	int		i;

	length = 0;
	while (s1[length])
		length++;
	if (!(s2 = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		j;
	size_t		length;
	char		*s2new;

	if (!s)
		return (NULL);
	j = 0;
	length = ft_strlen(s);
	if (!(s2new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start >= length)
	{
		s2new[0] = '\0';
		return (s2new);
	}
	while (j < len)
	{
		s2new[j] = s[j + start];
		j++;
	}
	s2new[j] = '\0';
	return (s2new);
}

int	ft_strlen(const char *s)
{
	int		l;

	l = 0;
	while (s[l] != '\0')
	{
		l++;
	}
	return (l);
}
