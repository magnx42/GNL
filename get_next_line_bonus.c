#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*buffer;
	char		*line;
	char		*new_rest;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	int read_return ;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (found_newline(rest[fd]) == 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return < 0)
		{
			if (rest[fd] != NULL)
			{
				free(rest[fd]);
				rest[fd] = NULL;
			}
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		else if (read_return == 0)
			break ;
		else
		{
			buffer[read_return] = '\0';
			rest[fd] = ft_strjoin(rest[fd], buffer);
		}
	}
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
