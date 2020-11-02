/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:08:43 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 20:32:40 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

t_llong	ft_atoi(char *str)
{
	t_llong	value;

	value = 0;
	while (is_numeric(*str))
	{
		value = 10 * value + *str - '0';
		str++;
	}
	return (value);
}

void	skip_zero(char **str)
{
	while (**str && **str == '0')
		(*str)++;
	if (!(**str))
		*str = "0";
}

t_uint	get_unit_len(t_uint len)
{
	return (len % UNIT != 0 ? len + UNIT - (len % UNIT) : len);
}

int		*ft_atoi_arr(char *str, t_uint *i_size)
{
	int		*i_value;
	t_uint	len;
	t_uint	diff;
	t_uint	i;
	t_uint	j;

	skip_zero(&str);
	len = ft_strlen(str);
	*i_size = get_unit_len(len) / UNIT;
	i_value = (int *)malloc(*i_size * sizeof(int));
	diff = get_unit_len(len) - len;
	i = 0;
	while (++i <= *i_size)
		i_value[i - 1] = 0;
	i = 0;
	j = diff;
	while (++i <= *i_size)
	{
		while (j < UNIT * i)
		{
			i_value[i - 1] = i_value[i - 1] * 10 + str[j - diff] - '0';
			j++;
		}
	}
	return (i_value);
}
