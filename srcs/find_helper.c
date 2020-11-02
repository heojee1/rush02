/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:08:56 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 20:32:50 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find.h"

char		*find_val(t_entry *entries, t_uint bound_idx, t_ulong n)
{
	long i;

	i = bound_idx;
	while (i >= 0)
	{
		if (entries[i].value == n)
			return (entries[i].str);
		i--;
	}
	return (0);
}

t_ulong		power_of_10(t_uint size)
{
	t_ulong num;
	t_ulong base;

	num = 1;
	base = 10;
	size = 3 * (size - 1);
	while (size)
	{
		num *= base;
		size--;
	}
	return (num);
}

char		*find_pow10(t_entry *entries, t_uint bound_idx, t_uint size)
{
	t_ulong pow10;

	pow10 = power_of_10(size);
	return (find_val(entries, bound_idx, pow10));
}

char		*find_first(t_entry *entries, t_uint bound_idx, int num)
{
	char *ans;

	ans = find_val(entries, bound_idx, num);
	if (!ans)
		return (0);
	ans = ft_strcat(ans, entries[bound_idx].str, True);
	return (ans);
}

char		*find_following(t_entry *entries, t_uint bound_idx, int num)
{
	long i;
	char *ans;

	ans = "\0";
	while (num)
	{
		i = bound_idx + 1;
		while (--i >= 0)
		{
			if (entries[i].value == (t_ulong)num)
			{
				ans = ft_strcat(ans, entries[i].str, ft_strlen(ans) > 0);
				return (ans);
			}
			if (entries[i].value < (t_ulong)num)
			{
				ans = ft_strcat(ans, entries[i].str, ft_strlen(ans) > 0);
				if (!ans)
					return (0);
				num %= entries[i].value;
			}
		}
		return (0);
	}
	return (ans);
}
