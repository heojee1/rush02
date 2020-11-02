/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:09:02 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 22:04:05 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_realloc.h"

char	*realloc_str(char *src, char *new_bs, t_uint old_len, t_uint new_len)
{
	char *dest;

	dest = (char *)malloc((new_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	if (src)
		ft_strncpy(dest, src, old_len);
	ft_strncpy(dest + old_len, new_bs, new_len - old_len);
	return (dest);
}

t_entry	*realloc_entries(t_entry *src, t_uint old_len, t_uint new_len)
{
	t_uint	i;
	t_entry	*dest;

	dest = (t_entry *)malloc(new_len * sizeof(t_entry));
	if (!dest)
		return (0);
	i = -1;
	while (++i < old_len)
		dest[i] = src[i];
	return (dest);
}
