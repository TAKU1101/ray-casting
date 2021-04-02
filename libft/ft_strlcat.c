#include "libft.h"

size_t	ft_strlcat(char *dest, const char *srcs, size_t size)
{
	size_t	dest_len;
	size_t	srcs_len;
	size_t	dest_i;
	size_t	srcs_i;

	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	srcs_len = 0;
	while (srcs[srcs_len])
		srcs_len++;
	if (dest_len >= size)
		return (size + srcs_len);
	dest_i = dest_len;
	srcs_i = 0;
	while (srcs[srcs_i] && dest_i < size - 1)
		dest[dest_i++] = srcs[srcs_i++];
	dest[dest_i] = '\0';
	return (dest_len + srcs_len);
}
