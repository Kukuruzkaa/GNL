/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:56:12 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/13 16:26:34 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

int	get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
int	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, size_t size);
void    *ft_calloc(size_t count, size_t size);
void    *ft_memset(void *b, int c, size_t len);
int 	ft_strchr_g(char *s, int c);

#endif
