#include "convert.h"
#include <stdio.h>

llong	ft_atoi(char *str)
{
	llong	value;
	int		sign;

	value = 0;
	sign = 1;
	// while (is_space(*str))
	// 	str++;
	// while (is_operator(*str))
	// {
	// 	if (*str == '-')
	// 		sign *= -1;
	// 	str++;
	// }
	while (is_numeric(*str))
	{
		value = 10 * value + *str - '0';
		str++;
	}
	return (sign * value);
}

void	skip_zero(char **str)
{
	while (**str && **str == '0')
		(*str)++;
	if (!(**str))
		*str = "0";
}

ulong	*ft_atoi_arr(char *str, uint *i_size)
{
	ulong *i_value;
	uint unit_len;
	uint len;
	uint diff;
	uint i;
	uint j;

	skip_zero(&str);
	len = ft_strlen(str);
	unit_len = len % UNIT != 0 ? len + UNIT - (len % UNIT) : len;
	*i_size = unit_len / UNIT;
	i_value = (ulong *)malloc(*i_size * sizeof(ulong));
	diff = unit_len - len;
	i = 1;
	j = diff;
	while (i <= *i_size)
	{
		i_value[i - 1] = 0;
		i++;
	}
	i = 1;
	while (i <= *i_size)
	{
		while (j < UNIT * i)
		{
			i_value[i - 1] = i_value[i - 1] * 10 + str[j - diff] - '0';
			j++;
		}
		i++;
	}
	// printf("%u", i_value[0]);
	return (i_value);
}
