/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:06:53 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/13 16:28:58 by ddiakova         ###   ########.fr       */
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
        lu = ft_strjoin(lu, buf, ret);
        //printf("lu: %s\n", lu);
        if ((i = ft_strchr_g(lu, '\n')) >= 0)
        {
            *line = ft_substr(lu, 0, i);
            //printf("line: %s\n", *line);
            temp = ft_strdup(&lu[i + 1]);
            //printf("temp: %s\n", temp);
            free(lu);
            lu = temp;
            break;
            //printf("lu: %s\n", lu);
            //lu = ft_strdup(&temp[i + 1]);
        }
        return (1);
    }
    return (0);
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
        free(line);
    }
    printf("%s\n", line);
    free(line);
    return (0);
}
