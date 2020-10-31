#include "ft_string.h"
#include <stdio.h>

void	ft_strncpy(char *dest, char *src, uint n)
{
	uint i;

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

char	*ft_strndup(char *src, uint n)
{
	uint i;
	uint len;
	char *dest;

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

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *s1, char *s2)
{
	uint s1_len;
	uint s2_len;
	char *str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	// printf("s1 %s len %u\n", s1, s1_len);
	// printf("s2 %s len %u\n", s2, s2_len);
	str = (char *)malloc((s1_len + s2_len + 2) * sizeof(char));
	if (!str)
		return (0);
	ft_strncpy(str, s1, s1_len);
	str[s1_len] = ' ';
	ft_strncpy(str + s1_len + 1, s2, s2_len);
	str[s1_len + s2_len + 1] = '\0';
	return (str);
}
