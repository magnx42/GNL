#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	char		*new_rest;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	int read_return ;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (found_newline(rest) == 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return < 0)
		{
			if (rest != NULL)
			{
				free(rest);
				rest = NULL;
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
			rest = ft_strjoin(rest, buffer);
		}
	}
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
