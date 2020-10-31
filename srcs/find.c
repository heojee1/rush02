#include "find.h"
#include <stdio.h>

uint		get_bound_idx(t_entry *entries, uint size)
{
	uint idx;

	idx = 0;
	while (idx < size)
	{
		if (entries[idx].value == BOUND && entries[idx].i_size == 1)
			return (idx);
		idx++;
	}
	return (-1);
}

char	*find_val(t_entry *entries, uint bound_idx, ulong n)
{
	uint i;

	i = bound_idx;
	while (i >= 0)
	{
		if (entries[i].value == n)
			return (entries[i].str);
		i--;
	}
	// if (i < 0)
	return (0);
}

char	*find_size(t_entry *entries, uint bound_idx, uint ent_size, uint size)
{
	uint i;

	i = bound_idx;
	while (i < ent_size)
	{
		if (entries[i].i_size == size)
			return (entries[i].str);
		i++;
	}
	// if (i == ent_size)
	return (0);
}

char	*find_all(t_entry *entries, uint bound_idx, ulong num)
{
	char *ans;
	uint i;

	if (num >= BOUND)
	{
		printf("over bound\n");
		ans = find_val(entries, bound_idx, num / BOUND);
		printf("%s\n", ans);
		ans = ft_strcat(ans, entries[bound_idx].str);
		printf("%s\n", ans);
		num %= BOUND;
		printf("%lu\n", num);
		if (!ans)
			return (0);
	}
	while (num)
	{
		i = bound_idx;
		while (i >= 0)
		{
			if (entries[i].value == num)
			{
				ans = ft_strcat(ans, entries[i].str);
				printf("exact %s\n", ans);
				return(ans);
			}
			if (entries[i].value < num)
			{
				ans = ft_strcat(ans, entries[i].str);
				printf("below %s\n", ans);
				num %= entries[i].value;
			}
			i--;
		}
		if (i < 0)
			return (0);
	}
	return (0);
}

char	*lookup(t_dict dict, t_entry to_find)
{
	uint	bound_idx;
	uint	curr_unit;
	uint	num;
	char	*ans;
	char	*temp;

	bound_idx = get_bound_idx(dict.entries, dict.size);
	if (bound_idx < 0)
		bound_idx = dict.size - 1;
	printf("bound %u\n", bound_idx);
	curr_unit = 0;
	ans = "\0";
	while (curr_unit < to_find.i_size)
	{
		num = to_find.i_value[curr_unit];
		printf("num %lu\n", to_find.i_value[curr_unit]);
		temp = find_all(dict.entries, bound_idx, num);
		printf("done %s\n", temp);
		if (temp)
			ans = ft_strcat(ans, temp);
		printf("to ans %s\n", ans);
		if (to_find.i_size - curr_unit > 1)
		{
			temp = find_size(dict.entries, bound_idx + 1, dict.size, to_find.i_size - curr_unit);
			ans = ft_strcat(ans, temp);
		}
		curr_unit++;
	}
	return (ans);
}

t_status	find(t_dict dict, char *str)
{
	t_entry	to_find;
	uint	size;
	char	*ans;

	to_find = (t_entry){str, ft_atoi(str), 0, 0};
	to_find.i_value = ft_atoi_arr(str, &size);
	to_find.i_size = size;
	ans = lookup(dict, to_find);
	printf("~%s~\n", ans);
	return (0);
}
