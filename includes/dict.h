/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:06:26 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 17:08:17 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stdlib.h>

# include "boolean.h"
# include "status.h"
# include "contracted_type.h"

# define DEFAULT_PATH	"numbers.dict"
# define SPACE			' '
# define DELIMITER		':'
# define FAILED			0
# define BYTE_1			1

typedef struct	s_entry
{
	char		*str;
	t_ulong		value;
	int			*i_value;
	t_uint		i_size;
}				t_entry;

typedef struct	s_dict
{
	t_status	status;
	char		*path;
	t_uint		size;
	t_entry		*entries;
}				t_dict;

int				open_file(char *path);
int				close_file(int fd);

int				cmp(t_entry e1, t_entry e2);
t_dict			load_default_dict(void);
t_dict			load_dict(char *path);
t_entry			*load_entries(char *path, t_status *status, t_uint *size);

#endif
