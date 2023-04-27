/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:43:35 by jdufour           #+#    #+#             */
/*   Updated: 2023/04/27 16:22:02 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *ptr;
	size_t i;
    char    *new_ptr;

    i = 0;
	ptr = malloc(nmemb * size);
    if (!(ptr))
        return (NULL);
    if ((nmemb * size) / size != nmemb)
		return (NULL);
	new_ptr = ptr;
	while (i < size)
    {
        new_ptr[i] = 0;
        i++;
    }
    return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_strlen(dest);
	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
	
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int	size;
	char	*cat;
	
	size = ft_strlen(s1) + ft_strlen(s2);
	cat = ft_calloc(size + 1, sizeof(char));
	if (!(cat))
		return (NULL);
	cat = ft_strcat(cat, s1);
	cat = ft_strcat(cat, s2);
	return (cat);
}