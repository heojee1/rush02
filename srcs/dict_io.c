/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:08:38 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 22:06:32 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "dict.h"
#include "convert.h"
#include "file_io.h"
#include "ft_string.h"
#include "is.h"
#include "ft_realloc.h"

char		*read_line(int fd, t_uint *len, t_status *status)
{
	char	buffer[BYTE_1];
	char	*line;
	t_uint	new_bytes;

	*len = 0;
	new_bytes = read(fd, buffer, BYTE_1);
	while (new_bytes > 0)
	{
		line = realloc_str(line, buffer, *len, *len + new_bytes);
		*len += new_bytes;
		if (buffer[0] == '\n')
			break ;
		new_bytes = read(fd, buffer, BYTE_1);
	}
	if (new_bytes == 0)
		*status = eof;
	return (line);
}

t_status	process_line(t_uint len, char *line, t_entry *entry)
{
	t_uint	idx;
	char	*value_str;
	t_uint	size;

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
	if (line[idx] == '\n' || idx >= len - 1)
		return (parse_err);
	entry->value = ft_atoi(value_str);
	entry->i_value = ft_atoi_arr(value_str, &size);
	entry->i_size = size;
	entry->str = ft_strndup(line + idx, len - idx - 1);
	return (valid);
}

t_entry		*load_entries(char *path, t_status *status, t_uint *size)
{
	int		fd;
	char	*line;
	t_entry	*entries;
	t_uint	line_len;

	fd = open_file(path);
	if (fd < 0)
		*status = fail;
	*size = 0;
	entries = 0;
	while (fd > 0)
	{
		entries = realloc_entries(entries, *size, *size + 1);
		*status = valid;
		line = read_line(fd, &line_len, status);
		if (*status == eof)
			break ;
		*status = process_line(line_len, line, &entries[*size]);
		if (*status != valid)
			break ;
		(*size)++;
	}
	close_file(fd);
	return (entries);
}
