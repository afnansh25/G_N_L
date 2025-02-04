/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:58:25 by codespace         #+#    #+#             */
/*   Updated: 2025/02/04 16:07:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char    *line;
    int fd;
    int fd2;
    
    fd = open("sample.txt", O_RDONLY);
    fd2 = open("sample2.txt", O_RDONLY);
    // if (fd == -1)
    //     return 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("fd1: %s", line);
        free (line);
    }
    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("fd2: %s", line);
        free (line);
    }
    close(fd);
    close(fd2);
    return (0);
}