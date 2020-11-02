/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:08:47 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 17:08:48 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "dict.h"

int		cmp(t_entry e1, t_entry e2)
{
	t_uint i;

	if (e1.i_size > e2.i_size)
		return (1);
	if (e1.i_size == e2.i_size)
	{
		i = -1;
		while (++i < e1.i_size)
		{
			if (e1.i_value[i] > e2.i_value[i])
				return (1);
			if (e1.i_value[i] < e2.i_value[i])
				return (-1);
		}
		return (0);
	}
	return (-1);
}

void	sort_dict(t_dict *dict)
{
	t_bool	swapped;
	t_entry	*entries;
	t_uint	size;
	t_uint	i;
	t_entry	temp;

	entries = dict->entries;
	size = dict->size;
	swapped = True;
	while (swapped)
	{
		swapped = False;
		i = -1;
		while (++i < size - 1)
		{
			if (cmp(entries[i], entries[i + 1]) > 0)
			{
				temp = entries[i];
				entries[i] = entries[i + 1];
				entries[i + 1] = temp;
				swapped = True;
			}
		}
	}
}

t_dict	load_default_dict(void)
{
	return (load_dict(DEFAULT_PATH));
}

t_dict	load_dict(char *path)
{
	t_dict		dict;
	t_entry		*entries;
	t_status	status;
	t_uint		size;

	dict = (t_dict){0, path, 0, 0};
	entries = load_entries(path, &status, &size);
	if (status == eof)
	{
		dict.status = valid;
		dict.size = size;
		dict.entries = entries;
		sort_dict(&dict);
	}
	else
		dict.status = fail;
	return (dict);
}
