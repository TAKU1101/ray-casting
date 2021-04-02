#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
		// printf("%zu, %d ", len, str[len]);
	}
	// printf("\n");
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char *p;
	char *rp;

	if (!s1)
		return (0);
	if (!(p = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	rp = p;
	while (*s1)
	{
		*p = *s1;
		s1++;
		p++;
	}
	*p = '\0';
	return (rp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*p;
	char			*rp;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	rp = p;
	while (*s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = '\0';
	return (rp);
}

void	*ft_memmove(void *dest, const void *srcs, size_t len)
{
	char		*p1;
	const char	*p2;
	size_t		i;

	p1 = dest;
	p2 = srcs;
	if (dest == (void *)0 && srcs == (void *)0)
		return (0);
	if (p1 > p2)
		while (len--)
			*(p1 + len) = *(p2 + len);
	else
	{
		i = 0;
		while (i < len)
		{
			*(p1 + i) = *(p2 + i);
			i++;
		}
	}
	return (dest);
}