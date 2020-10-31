#include <stdio.h>

#include "dict.h"
#include "status.h"
#include "print_utils.h"
#include "find.h"

t_status	set_up(int argc, char **argv, t_dict *dict, char **to_find)
{
	if (argc == 3)
	{
		*dict = load_dict(argv[1]);
		*to_find = argv[2];
	}
	else if (argc == 2)
	{
		*dict = load_default_dict();
		*to_find = argv[1];
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
	if (status == valid && dict.status != valid)
		status = parse_err;
	if (status == valid)
	{
		if (is_valid_input(&to_find))
		{
			status = find(dict, to_find);
		}
		else
			printf("Dict error - wrong input\n");
		// for (uint i = 0; i < dict.size; i++)
		// {
		// 	print_number(dict.entries[i]);
		// 	printf(" : ");
		// 	printf("%s\n", dict.entries[i].str);
		// }
		free(dict.entries);
	}
	else
		printf("Dict error\n");
}
