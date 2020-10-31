#include <stdio.h>

#include "dict.h"

t_dict	load_default_dict(void)
{
	return(load_dict(DEFAULT_PATH));
}

t_dict	load_dict(char *path)
{
	t_dict		dict;
	t_entry		*entries;
	t_status	status;
	uint		size;

	dict = (t_dict){0, path, 0, 0};
	entries = load_entries(path, &status, &size);
	if (status == eof)
	{
		dict.status = valid;
		dict.size = size;
		dict.entries = entries;
	}
	else
		dict.status = fail;
	return (dict);
}

void	free_dict(t_dict *dict)
{
	free(dict->entries);
	free(dict);
}
