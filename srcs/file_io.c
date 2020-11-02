/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:08:51 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 17:08:52 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_io.h"

int		open_file(char *path)
{
	return (open(path, O_RDONLY));
}

int		close_file(int fd)
{
	return (close(fd));
}
