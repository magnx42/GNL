#ifndef GET_NEXT_LINE_BONUS_H_
# define GET_NEXT_LINE_BONUS_H_
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif
char *extract_rest(char *str);
char *extract_line(char *str);
char *ft_strjoin(char *s1, char *s2);
int found_newline(char *str);
int ft_strlen(char *str);
char *get_next_line(int fd);
#endif
