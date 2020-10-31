#include "is.h"

t_bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\r' || c == '\f');
}

t_bool	is_printable(char c)
{
	return (32 <= c && c <= 126);
}

t_bool	is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}

t_bool	is_operator(char c)
{
	return (c == '+' || c == '-');
}
