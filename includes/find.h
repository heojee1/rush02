/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:07:03 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 17:12:41 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_H
# define FIND_H

# include "dict.h"
# include "convert.h"
# include "is.h"
# include "ft_string.h"

# define BOUND 100

t_status	find(t_dict dict, char *str);
char		*find_val(t_entry *entries, t_uint bound_idx, t_ulong n);
char		*find_following(t_entry *entries, t_uint bound_idx, int num);
char		*find_first(t_entry *entries, t_uint bound_idx, int num);
char		*find_pow10(t_entry *entries, t_uint bound_idx, t_uint size);

#endif
