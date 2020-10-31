#include "ft_realloc.h"

char	*ft_realloc_str(char *src, char *new_bytes, uint old_len, uint new_len)
{
	char *dest;

	dest = (char *)malloc((new_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	if (src)
		ft_strncpy(dest, src, old_len);
	ft_strncpy(dest + old_len, new_bytes, new_len - old_len);
	return (dest);
}

t_entry *ft_realloc_entries(t_entry *src, uint old_len, uint new_len)
{
	uint i;

	t_entry *dest = (t_entry *)malloc(new_len * sizeof(t_entry));
	if (!dest)
		return (0);
	i = -1;
	while (++i < old_len)
		dest[i] = src[i];
	return (dest);
}
