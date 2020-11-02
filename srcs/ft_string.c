/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeheo <jeheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:09:06 by jeheo             #+#    #+#             */
/*   Updated: 2020/11/01 22:07:18 by jeheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_strncpy(char *dest, char *src, t_uint n)
{
	t_uint i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

char	*ft_strndup(char *src, t_uint n)
{
	t_uint	i;
	t_uint	len;
	char	*dest;

	i = -1;
	len = 0;
	while (src[++i])
		len++;
	len = len > n ? n : len;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = -1;
	while (++i < n)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

t_uint	ft_strlen(char *str)
{
	t_uint len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *s1, char *s2, t_bool need_space)
{
	t_uint	s1_len;
	t_uint	s2_len;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1 + need_space) * sizeof(char));
	if (!str)
		return (0);
	ft_strncpy(str, s1, s1_len);
	if (need_space)
		str[s1_len] = ' ';
	ft_strncpy(str + s1_len + need_space, s2, s2_len);
	str[s1_len + s2_len + 1 + need_space] = '\0';
	return (str);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
