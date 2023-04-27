/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:00:53 by jdufour           #+#    #+#             */
/*   Updated: 2023/04/27 16:50:23 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5

char	*get_line(char *buf)
{
	char *line;
    int i;

    i = 0;
    line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!(line))
        return (NULL);
    while (line[i - 1] != '\n')
    {
        line[i] = buf[i];
        i++;
    }
    line[i] = '\0';
	return (line);
}

char	*update_buffer(char *buf)
{
	int		i;
	int		j;
	char	*new_buf;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	i++;
	j = 0;
	while (buf[i])
		new_buf[j++] = buf[i++];
	new_buf[j] = '\0';
	return (new_buf);
}

char    *get_from_buffer(int fd, char *buf)
{
    char    *str;
    int pos;

    str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    pos = 1;
    while (!(ft_strchr(buf, '\n')) && pos != 0)
    {
        pos = read(fd, str, BUFFER_SIZE);
        str[pos] = '\0';
        buf = ft_strjoin(buf, str);
    }
    free (str);
    return (buf);
}

char    *get_next_line(int fd)
{
    static char *buf;
    char *line;

    buf = get_from_buffer(fd, buf);
    printf("buf : %s\n", buf);
    line = get_line(buf);
    printf("line : %s\n", line);
    buf = update_buffer(buf);
    printf("new buf : %s\n", buf);
    return (line);
}

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	// char	*buf = get_buffer(fd);
	char	*line = get_next_line(fd);
	printf("line = %s\n", line);
	// buf = get_buffer(fd);
	line = get_next_line(fd);
	printf("line = %s\n", line);
	free (line);
}