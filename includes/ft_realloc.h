#ifndef FT_REALLOC_H
# define FT_REALLOC_H

#include <stdlib.h>

#include "dict.h"
#include "contracted_type.h"
#include "ft_string.h"

char	*ft_realloc_str(char *src, char *new_bytes, uint old_len, uint new_len);
t_entry *ft_realloc_entries(t_entry *src, uint old_len, uint new_len);

#endif
