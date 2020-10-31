#ifndef FT_STRING_H
# define FT_STRING_H

#include <stdlib.h>

#include "boolean.h"
#include "contracted_type.h"

t_bool	is_space(char c);
t_bool	is_printable(char c);
t_bool	is_numeric(char c);
t_bool	is_operator(char c);

void	ft_strncpy(char *dest, char *src, uint n);
char	*ft_strndup(char *src, uint n);
int		ft_strlen(char *str);
char	*ft_strcat(char *s1, char *s2);

#endif
