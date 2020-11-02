/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:09:09 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 17:09:10 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
