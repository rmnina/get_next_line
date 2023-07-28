/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:38:38 by jdufour           #+#    #+#             */
/*   Updated: 2023/05/02 22:50:42 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *line)
{
	int	i;

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
	int	i;
	int	j;

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

char	*get_new_line(char *buf, char *line, int fd)
{
	int	bytes;

	bytes = 1;
	line = ft_strjoin(line, buf);
	while (!(ft_strchr(line, '\n')) && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (line);
			return (NULL);
		}
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

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || read(fd, buf[fd], 0) == -1)
		return (NULL);
	line = get_new_line(buf[fd], line, fd);
	if (!line || line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}
// int	main()
// {
// 	int	fd1 = open("test.txt", O_RDONLY);
//     int fd2 = open("test2.txt", O_RDONLY);
// 	char	*line = NULL;
//     for (int i = 0 ; i < 10 ; i++)
//     {
//         line = get_next_line(fd1);
//         if (line == NULL)
//             break;
// 	    printf("line %d = %s", i, line);
//         line = get_next_line(fd2);
//         if (line == NULL)
//             break;
//         printf("line %d = %s", i, line);

//     }
//     free (line);
//     close (fd1);
//     close (fd2);
// }
