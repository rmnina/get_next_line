/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:54:29 by jdufour           #+#    #+#             */
/*   Updated: 2023/04/29 19:20:58 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

//#define BUFFER_SIZE 100

char    *get_next_line(int fd);
char	*get_line(char *line);
char	*update_buffer(char *buf, char *line);
char    *get_new_line(char *buf, char *line, int fd);
char    *ft_strchr(const char *str, int c);
void    *ft_calloc(size_t nmemb, size_t size);
int ft_strlen(const char *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char *s1, char *s2);

#endif