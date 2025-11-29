/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mageneix <mageneix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:27:59 by mageneix          #+#    #+#             */
/*   Updated: 2025/11/15 16:30:07 by mageneix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*rest[1024];
	char		*buffer;
	char		*line;
	char		*new_rest;
	int			read_return;

	read_return = 1;
	if (BUFFER_SIZE <= 0 || (fd < 0 || fd >= 1024))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (found_newline(rest[fd]) == 0 && read_return > 0)
		reader(&read_return, &rest[fd], buffer, fd);
	free(buffer);
	buffer = NULL;
	if (!rest[fd] || rest[fd][0] == 0)
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (NULL);
	}
	line = extract_line(rest[fd]);
	new_rest = extract_rest(rest[fd]);
	free(rest[fd]);
	rest[fd] = new_rest;
	return (line);
}
