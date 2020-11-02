/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:07:12 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 17:07:12 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_H
# define IS_H

# include "boolean.h"

t_bool	is_space(char c);
t_bool	is_printable(char c);
t_bool	is_numeric(char c);
t_bool	is_operator(char c);

#endif
