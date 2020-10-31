#ifndef DICT_H
# define DICT_H

#include <stdlib.h>

#include "boolean.h"
#include "status.h"
#include "contracted_type.h"

# define DEFAULT_PATH "numbers.dict"
# define SPACE ' '
# define DELIMITER ':'
# define FAILED 0
# define BYTE_1 1

// typedef struct	s_entry
// {
// 	char	*str;
// 	ulong	value;
// }				t_entry;

typedef struct	s_entry
{
	char	*str;
	ulong	value;
	ulong	*i_value;
	uint	i_size;
}				t_entry;

typedef struct	s_dict
{
	t_status	status;
	char		*path;
	uint		size;
	t_entry	*	entries;
}				t_dict;

int		open_file(char *path);
int		close_file(int fd);

t_dict	load_default_dict(void);
t_dict	load_dict(char *path);
t_entry	*load_entries(char *path, t_status *status, uint *size);
void	free_dict(t_dict *dict);

#endif
