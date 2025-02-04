/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:07:03 by codespace         #+#    #+#             */
/*   Updated: 2025/02/04 16:02:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *buf, char *leftover)
{
	char	*temp;
	int	bytes_read;
	
	bytes_read = 1;
	while (!ft_strchr(buf, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if(bytes_read == -1)
		{
        	free(leftover);
			free (buf);
			return (NULL);
		}
		else if(bytes_read == 0)
			break;
		temp = leftover;
		buf[bytes_read] = '\0';
		leftover = ft_strjoin(leftover, buf);
		if (temp)
			free (temp);
	}
	free (buf);
	return (leftover);
}

char	*ft_extract_line(char *leftover)
{
	char	*line;
	size_t	i;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	line = ft_substr(leftover, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_update_line(char *leftover)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!leftover)
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] && leftover[i] == '\n')
		i++;
	line = ft_strdup(leftover + i);
	if (!line)
	{
		free (leftover);
		return (NULL);
	}
	free (leftover);
	leftover = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*line;
	char		*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	leftover[fd] = ft_read_line(fd, buffer, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	line = ft_extract_line(leftover[fd]);
	leftover[fd] = ft_update_line(leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	if (!*leftover[fd])
	{
		free (leftover[fd]);
		leftover[fd] = NULL;
	}
	return (line);
}
