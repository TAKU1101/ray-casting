#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	tail;
	char	head;
	char	mask1;
	char	mask2;

	if ((unsigned char)c <= 0x7F)
		write(fd, &c, 1);
	else
	{
		mask1 = 0b00111111;
		mask2 = 0b11000000;
		head = (((unsigned char)c & mask2) >> 6) | mask2;
		tail = ((unsigned char)c & mask1) | 0b10000000;
		write(fd, &head, 1);
		write(fd, &tail, 1);
	}
}
