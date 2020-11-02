/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:09:17 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 18:56:44 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_utils.h"
#include "ft_string.h"

void	ft_first_digits(t_uint n)
{
	char	c;

	if (n > 9)
		ft_first_digits(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_following_digits(t_uint n)
{
	char c;

	c = n / 100 + '0';
	write(1, &c, 1);
	c = (n / 10) % 10 + '0';
	write(1, &c, 1);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	print_number(t_entry entry)
{
	t_uint i;

	i = 0;
	while (i < entry.i_size)
	{
		if (i == 0)
			ft_first_digits(entry.i_value[i]);
		else
			ft_following_digits(entry.i_value[i]);
		i++;
	}
}

void	print_found(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	print_dict(t_dict dict)
{
	t_uint i;

	i = -1;
	ft_putstr("=== DICTIONARY ===\n");
	while (++i < dict.size)
	{
		print_number(dict.entries[i]);
		ft_putstr(" : ");
		ft_putstr(dict.entries[i].str);
		ft_putstr("\n");
	}
	ft_putstr("======= END =======\n");
}
