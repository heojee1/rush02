/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:07:15 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 22:52:58 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UTILS_H
# define PRINT_UTILS_H

# include <unistd.h>

# include "dict.h"

# define UNIT 3

void	print_number(t_entry entry);
void	print_found(char *str);
void	print_dict(t_dict dict);

#endif
