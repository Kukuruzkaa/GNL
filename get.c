/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:43:12 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/14 14:34:45 by ddiakova         ###   ########.fr       */
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


    if (!(buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1))))
        return (-1);
    if (fd == -1 || !line || BUF_SIZE <= 0)
        return (-1);
    while ((ret = read(fd, buf, BUF_SIZE)) > 0)
    {   
        (buf[ret] = '\0');
        i = 0;
        lu = ft_strjoin(lu, buf, ret);
        if ((i = ft_strchr_g(lu, '\n')) >= 0)
        {
            *line = ft_substr(lu, 0, i);
            temp = ft_strdup(&lu[i + 1]);
            if (lu)
                free(lu);
            lu = temp;
            return (1);
        }
    }
    if (ret < 0)
        return (-1);
    else if (ret == 0 && lu == NULL)
        return (0);
    if(buf)
        free (buf);
    i = 0;
    while (lu[i++] != '\0')
    {
        if (lu[i] == '\n')
        { 
            *line = ft_substr(lu, 0, i);
            temp = ft_strdup(&lu[i + 1]);
            if (lu)
                free(lu);
            lu = temp;
            return (1);
        }
        else 
        {
            *line = ft_strdup(lu);
            if (lu)
                free(lu);
            return (0);
        }
    }
    return (1);
}


int main ()
{
    int fd;
    char *line;
    int r;

    fd = open ("file.txt", O_RDONLY);
    while ((r = get_next_line (fd, &line)) >= 0)
    {   
        printf("%s\n", line);
        if (line)
            free(line);
    }
    printf("%s\n", line);
    if (line)
        free(line);
    return (0);
}

