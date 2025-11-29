/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mageneix <mageneix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:27:54 by mageneix          #+#    #+#             */
/*   Updated: 2025/11/15 16:27:54 by mageneix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	found_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*line;
	int		i;
	int		j;

	line = malloc((sizeof(char) * ((ft_strlen(s1) + 1) + ft_strlen(s2))));
	if (!line)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		line[i + j] = s2[j];
		j++;
	}
	line[i + j] = '\0';
	free(s1);
	return (line);
}

char	*extract_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*extract_rest(char *str)
{
	int		i;
	int		j;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n' || str[i + 1] == '\0')
		return (NULL);
	line = malloc(sizeof(char) * ((ft_strlen(str) - i)));
	if (!line)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
	{
		line[j] = str[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (line);
}
