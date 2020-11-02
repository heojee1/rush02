/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:07:09 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 18:47:20 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include <unistd.h>

# include "boolean.h"
# include "contracted_type.h"

t_bool	is_space(char c);
t_bool	is_printable(char c);
t_bool	is_numeric(char c);
t_bool	is_operator(char c);

void	ft_strncpy(char *dest, char *src, t_uint n);
char	*ft_strndup(char *src, t_uint n);
t_uint	ft_strlen(char *str);
char	*ft_strcat(char *s1, char *s2, t_bool need_space);
void	ft_putstr(char *str);

#endif
