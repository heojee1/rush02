/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:07:19 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 21:44:35 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

typedef enum	e_status
{
	parse_err,
	eof,
	no_entry,
	fail,
	valid,
	print_only
}				t_status;

#endif
