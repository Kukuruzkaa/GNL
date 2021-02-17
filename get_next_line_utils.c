/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:06:59 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/13 16:14:37 by ddiakova         ###   ########.fr       */
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
	if (!s)
		return (l);
	while (s[l] != '\0')
	{
		l++;
	}
	return (l);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}

int 	ft_strchr_g(char *s, int c)
{
	int 		i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t size)
{
	int		str1len;
	int		i;
	int		j;
	char	*s3;

	str1len = ft_strlen(s1);
	if (!(s3 = (char*)malloc(sizeof(char) * (str1len + size + 1))))
		return (NULL);
	i = 0;
	while ( i < str1len)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[str1len + j] = s2[j];
		j++;
	}
	s3[str1len + size] = '\0';
	return (s3);
}