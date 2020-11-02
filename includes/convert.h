/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:06:53 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 17:06:54 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "contracted_type.h"
# include "ft_string.h"
# include "dict.h"

# define UNIT 3

t_llong	ft_atoi(char *str);
int		*ft_atoi_arr(char *str, t_uint *i_size);

#endif
