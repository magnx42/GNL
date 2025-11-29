/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mageneix <mageneix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:27:45 by mageneix          #+#    #+#             */
/*   Updated: 2025/11/15 16:29:57 by mageneix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	reader(int *read_return, char **rest, char *buffer, int fd)
{
	*read_return = ((int)read(fd, buffer, BUFFER_SIZE));
	if (*read_return < 0)
	{
		if (*rest != NULL)
		{
			free(*rest);
			*rest = NULL;
		}
		return ;
	}
	else if (*read_return == 0)
		return ;
	else
	{
		buffer[*read_return] = '\0';
		*rest = ft_strjoin(*rest, buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	char		*new_rest;
	int			read_return;

	read_return = 1;
	if (BUFFER_SIZE <= 0 || (fd < 0 || fd >= 1024))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (found_newline(rest) == 0 && read_return > 0)
		reader(&read_return, &rest, buffer, fd);
	free(buffer);
	buffer = NULL;
	if (!rest || rest[0] == 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = extract_line(rest);
	new_rest = extract_rest(rest);
	free(rest);
	rest = new_rest;
	return (line);
}
