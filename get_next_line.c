/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:06:53 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/15 12:53:12 by ddiakova         ###   ########.fr       */
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
        // free buf
    if (fd == -1 || !line || BUF_SIZE <= 0)
        return (-1);
        // free tout - 'lu'
    while ((ret = read(fd, buf, BUF_SIZE)) > 0)
    {   
        (buf[ret] = '\0');
        i = 0;
        lu = ft_strjoin(lu, buf, ret); // temp = ft_strjoin(lu, buf, ret);
        if ((i = ft_strchr_g(lu, '\n')) >= 0) // free(lu);
        {                                      // lu = temp
            *line = ft_substr(lu, 0, i);
            temp = ft_strdup(&lu[i + 1]);
            if (lu)
                free(lu);
            lu = temp;
            return (1);
        }
    }
    if (ret < 0)
    // free (tout ce aue j'ai malloc)
        return (-1);
    else if (ret == 0 && lu == NULL)
        return (0);
    // free tout sauf la line
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
            *line = ft_strdup(&lu[i]);
            lu = 0;
            return (0);
        }
    }
    return (1);
}


/*int main ()
{
    int fd;
    char *line;
    int r;

    fd = open ("mail.txt", O_RDONLY);
    //get_next_line(fd, &line);
    while ((r = get_next_line (fd, &line)) > 0)
    {   
        printf("%s\n", line);
        free(line);
    }
    printf("%s\n", line);
    free(line);
    return (0);
}*/
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
		countline++;
    }
	printf("line %d = %s - [%d]\n", countline, line, ret);
	free(line);
    printf("\nTest de LEAKS\n");
	system("leaks a.out | grep leaked\n"); 
	return 0;
}