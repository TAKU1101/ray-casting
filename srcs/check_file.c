#include "cub3d.h"

static int	path_is_cub(char *line)
{
	int		n;
	char	*p;

	n = ft_strlen(line);
	p = ft_strnstr(line, ".cub", n);
	if (!p || n == 4)
		return (1);
	if ((char)*(p - 1) == '/')
		return (1);
	if (!(n - (p - line) - 4))
		return (0);
	return (1);
}

int			check_file(t_mapkey *keys, t_player *player, int argv, char *argc[])
{
	if (argv == 3)
	{
		if (!ft_strncmp(argc[2], "--save", 7) && !path_is_cub(argc[1]))
		{
			if (scan_file(argc[1], keys, player))
				return (0);
			return (2);
		}
		else
			write(2, "Argument Error\n", 16);
	}
	else if (argv == 2)
	{
		if (!path_is_cub(argc[1]))
		{
			if (scan_file(argc[1], keys, player))
				return (0);
			return (1);
		}
		else
			write(2, "Argument Error\n", 16);
	}
	return (0);
}
