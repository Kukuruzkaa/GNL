/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:06:53 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/12 16:54:16 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    int ret;
    int i;
    char     *buf;
    static char *lu;
    char *temp;


    buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
    if (fd == -1 || !line || BUF_SIZE <= 0)
        return (-1);
    while ((ret = read(fd, buf, BUF_SIZE)) > 0)
    {   
        (buf[ret] = '\0');
        i = 0;
        lu = ft_strdup(buf);
        while (lu[i])
        {
            if (lu[i] == '\n')
            {
                *line = ft_substr(lu, 0, i);
                temp = ft_strdup(&lu[i+1]);
                free(lu);
                lu = temp;
                temp = NULL;
                break;
            }
            i++;
        }
        return (1);
    }
    return (0);
}

int main ()
{
    int fd;
    char *line;

    fd = open ("file.txt", O_RDONLY);
    get_next_line (fd, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd, &line);
    printf("%s\n", line);
    return (0);
}
