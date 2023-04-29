/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:00:53 by jdufour           #+#    #+#             */
/*   Updated: 2023/04/29 19:25:11 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5

char	*get_line(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (line[i] && line[i] == '\n')
        i++;
    line[i] = '\0';
	return (line);
}


char	*update_buffer(char *buf, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
        i++;
	j = 0;
	while (line[i])
    {
		buf[j] = line[i];
        i++;
        j++;
    }
	buf[j] = '\0';
	return (buf);
}

char    *get_new_line(char *buf, char *line, int fd)
{
   int bytes;
    
    bytes = 1;
    line = ft_strjoin(line, buf);
    while (!(ft_strchr(line, '\n')) && bytes != 0) 
    {
        bytes = read(fd, buf, BUFFER_SIZE);
        if (bytes == -1)
            return (NULL);
        buf[bytes] = '\0';
        line = ft_strjoin(line, buf);
    }
    buf = update_buffer(buf, line);
    line = get_line(line);
    if (!line)
    {
        free (line);
        return (NULL);
    }
    return (line);
}

char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char *line;

    line = NULL;
    if (fd == -1)
        return (NULL);
    if (read(fd, buf, 0) == -1)
        return (NULL);
    line = get_new_line(buf, line, fd);
    if (line[0] == '\0')
    {
        free (line);
        return (NULL);
    }
    return (line);
}

// int	main()
// {
// 	int	fd = open("test.txt", O_RDONLY);
// 	char	*line = NULL;
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (line == NULL)
//             break;
// 	    printf("line = %s", line);
// 	    free (line);
//     }
// }