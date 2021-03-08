/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:56:12 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/08 14:11:33 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
void	ft_getsubstr(char *s, unsigned int start, size_t len);
int		ft_strlen(const char *s);
char	*ft_joinstr(char *s1, char *s2, size_t size);
void	*ft_getmemset(void *b, int c, size_t len);
int		ft_strchr_g(char *s, int c);

#endif
