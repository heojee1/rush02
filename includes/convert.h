#ifndef CONVERT_H
# define CONVERT_H

#include "contracted_type.h"
#include "ft_string.h"
#include "dict.h"

# define UNIT 3

llong ft_atoi(char *str);
// void	ft_atoi_arr(t_entry *entry, char *str);
ulong	*ft_atoi_arr(char *str, uint *i_size);

#endif
