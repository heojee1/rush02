#include "print_utils.h"

void	ft_first_digits(uint n)
{
	char	c;

	if (n > 9)
		ft_first_digits(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_following_digits(uint n)
{
	char c;

	c = n / 100 + '0';
	write(1, &c, 1);
	c = (n % 10) / 10+ '0';
	write(1, &c, 1);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	print_number(t_entry entry)
{
	uint i;

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
