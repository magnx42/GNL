/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mageneix <mageneix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:27:57 by mageneix          #+#    #+#             */
/*   Updated: 2025/11/15 16:29:25 by mageneix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*extract_rest(char *str);
char	*extract_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		found_newline(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
#endif
