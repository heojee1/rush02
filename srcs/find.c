/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:08:59 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 22:52:18 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find.h"
#include "print_utils.h"

t_uint		get_bound_idx(t_entry *entries, t_uint size)
{
	t_uint idx;

	idx = 0;
	while (idx < size)
	{
		if (entries[idx].value == BOUND && entries[idx].i_size == 1)
			return (idx);
		idx++;
	}
	return (size - 1);
}

char		*find_all(t_entry *entries, t_uint bound_idx, int num)
{
	char *ans;
	char *temp;

	ans = "\0";
	if (num >= BOUND)
	{
		ans = find_first(entries, bound_idx, num / BOUND);
		if (!ans)
			return (0);
		num %= BOUND;
	}
	temp = find_following(entries, bound_idx, num);
	if (!temp)
		return (0);
	if (ft_strlen(temp))
	{
		ans = ft_strcat(ans, temp, ft_strlen(ans) > 0);
		free(temp);
		return (ans);
	}
	return (ans);
}

char		*lookup(t_dict dict, t_entry to_find, t_uint bound_idx)
{
	t_uint	c;
	char	*ans;
	char	*temp;

	ans = "\0";
	c = -1;
	while (++c < to_find.i_size)
	{
		if (to_find.i_value[c] == 0 && to_find.i_size == 1)
			return (find_val(dict.entries, bound_idx, 0));
		temp = find_all(dict.entries, bound_idx, to_find.i_value[c]);
		if (!temp)
			return (0);
		if (ft_strlen(temp))
			ans = ft_strcat(ans, temp, c != 0);
		if (ft_strlen(temp) && to_find.i_size - c > 1)
		{
			temp = find_pow10(dict.entries, dict.size - 1, to_find.i_size - c);
			if (!temp)
				return (0);
			ans = ft_strcat(ans, temp, True);
			free(temp);
		}
	}
	return (ans);
}

t_status	find(t_dict dict, char *str)
{
	t_entry	to_find;
	t_uint	size;
	t_uint	bound_idx;
	char	*ans;

	bound_idx = get_bound_idx(dict.entries, dict.size);
	to_find = (t_entry){str, ft_atoi(str), 0, 0};
	to_find.i_value = ft_atoi_arr(str, &size);
	to_find.i_size = size;
	ans = lookup(dict, to_find, bound_idx);
	if (!ans)
		return (fail);
	print_found(ans);
	free(ans);
	return (valid);
}
