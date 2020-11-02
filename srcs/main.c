/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:09:13 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 22:04:30 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "status.h"
#include "print_utils.h"
#include "find.h"

t_status	set_up(int argc, char **argv, t_dict *dict, char **to_find)
{
	if (argc == 1)
	{
		*dict = load_default_dict();
		return (print_only);
	}
	else if (argc == 2)
	{
		*dict = load_default_dict();
		*to_find = argv[1];
	}
	else if (argc == 3)
	{
		*dict = load_dict(argv[1]);
		*to_find = argv[2];
	}
	else
		return (fail);
	return (valid);
}

t_bool		is_valid_input(char **str)
{
	int		idx;

	idx = 0;
	while (is_space(**str))
		(*str)++;
	if (**str == '+')
		(*str)++;
	while (is_space(**str))
		(*str)++;
	while (is_numeric(*(*str + idx)))
		idx++;
	if (*(*str + idx) && !is_space(*(*str + idx)))
		return (False);
	*(*str + idx) = '\0';
	if (idx < 1)
		return (False);
	return (True);
}

int			main(int argc, char **argv)
{
	t_dict		dict;
	char		*to_find;
	t_status	status;

	status = set_up(argc, argv, &dict, &to_find);
	if (status == print_only && dict.status == valid)
		print_dict(dict);
	if (status == valid && dict.status != valid)
		status = parse_err;
	if (status == valid)
	{
		if (is_valid_input(&to_find))
		{
			status = find(dict, to_find);
			if (status != valid)
				ft_putstr("Dict error - not found\n");
		}
		else
			ft_putstr("Dict error - wrong input\n");
		free(dict.entries);
	}
	else
		ft_putstr("Dict error\n");
}
