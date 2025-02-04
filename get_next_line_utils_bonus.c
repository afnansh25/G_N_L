/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:24:06 by codespace         #+#    #+#             */
/*   Updated: 2025/02/04 15:49:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    size_t  i;
    char   *str;
    char   letter;

    if (!s)
		return (NULL);
    i = 0;
    str = (char *)s;
    letter = (char)c;
    while (str[i])
    {
        if (str[i] == letter)
            return (char *)(s + i);
        i++;
    }
    if (letter == '\0')
        return (char *)(s + i);
    return (NULL);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *join;
    size_t  len1;
    size_t  len2;

    if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
    join = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!join)
        return (NULL);
    len1 = 0;
    len2 = 0;
    while (s1 && s1[len1])
    {
        join[len1] = s1[len1];
        len1++;
    }
    while (s2 && s2[len2])
        join[len1++] = s2[len2++];
    join[len1] = '\0';
    return (char *)join;
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sstr;
    size_t i;
    
    i = 0;
    if (!s)
        return (NULL);
    if (ft_strlen(s) < start)
        len = 0;
    if (ft_strlen(s) - start < len)
        len = ft_strlen(s) - start;
    sstr = (char *)malloc(sizeof (char) * len + 1);
    if(!sstr)
        return (NULL);
    while (i < len)
    {
        sstr[i++] = s[start++];
    }
    sstr[i] = '\0';
    return (char *)sstr; 
}

char    *ft_strdup(const char *s)
{
    size_t  i;
    char    *dup;

    if (!s)
		return (NULL);
    i = 0;
    dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!dup)
        return (NULL);
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
