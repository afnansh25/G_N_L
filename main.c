/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:58:25 by codespace         #+#    #+#             */
/*   Updated: 2025/02/02 11:56:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char    *line;
    int fd;
    
    fd = open("sample.txt", O_RDONLY);
    if (fd == -1)
        return 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free (line);
    }
    close(fd);
    return (0);
}