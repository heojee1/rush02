/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:07:06 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 17:07:06 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REALLOC_H
# define FT_REALLOC_H

# include <stdlib.h>

# include "dict.h"
# include "contracted_type.h"
# include "ft_string.h"

char	*realloc_str(char *src, char *new_bs, t_uint old_len, t_uint new_len);
t_entry *realloc_entries(t_entry *src, t_uint old_len, t_uint new_len);

#endif
