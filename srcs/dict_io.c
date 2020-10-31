#include <stdio.h>

#include "dict.h"
#include "convert.h"
#include "file_io.h"
#include "ft_string.h"
#include "is.h"
#include "ft_realloc.h"

char		*read_line(int fd, uint *len, t_status *status)
{
	char	buffer[BYTE_1];
	char	*line;
	uint	new_bytes;

	*len = 0;
	new_bytes = read(fd, buffer, BYTE_1);
	while (new_bytes > 0)
	{
		line = ft_realloc_str(line, buffer, *len, *len + new_bytes);
		*len += new_bytes;
		if (buffer[0] == '\n')
			break ;
		new_bytes = read(fd, buffer, BYTE_1);
	}
	if (new_bytes == 0)
		*status = eof;
	return (line);
}

t_status	process_line(uint len, char *line, t_entry *entry)
{
	uint	idx;
	char	*value_str;
	uint	size;

	idx = 0;
	while (is_numeric(line[idx]))
		idx++;
	if (line[idx] == '\n' || idx == 0 || idx >= len)
		return (parse_err);
	value_str = ft_strndup(line, idx);
	while (line[idx] == SPACE)
		idx++;
	if (line[idx] != DELIMITER)
		return (parse_err);
	idx++;
	while (line[idx] == SPACE)
		idx++;
	if (line[idx] ==  '\n' || idx >= len - 1)
		return (parse_err);
	entry->value = ft_atoi(value_str);
	entry->i_value = ft_atoi_arr(value_str, &size);
	entry->i_size = size;
	entry->str = ft_strndup(line + idx, len - idx - 1);
	return (valid);
}

t_entry		*load_entries(char *path, t_status *status, uint *size)
{
	int		fd;
	char	*line;
	t_entry	*entries;
	uint	line_len;

	fd = open_file(path);
	if (fd < 0)
	{
		*status = fail;
		return (0);
	}
	*size = 0;
	entries = 0;
	while (True)
	{
		entries = ft_realloc_entries(entries, *size, *size + 1);
		*status = valid;
		line = read_line(fd, &line_len, status);
		if (*status == eof)
			break ;
		*status = process_line(line_len, line, &entries[*size]);
		if (*status != valid)
			return (entries);
		(*size)++;
	}
	close_file(fd);
	return (entries);
}
