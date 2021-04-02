#include "cub3d.h"

int		skip_sp(char *line)
{
	int i;

	i = 0;
	while (*line == ' ')
	{
		line++;
		i++;
	}
	return (i);
}

int		skip_num(char *line)
{
	int i;

	i = 0;
	while ('0' <= *line && *line <= '9')
	{
		line++;
		i++;
	}
	return (i);
}

void	init_mapkey(t_mapkey *key)
{
	key->no_pass = NULL;
	key->so_pass = NULL;
	key->we_pass = NULL;
	key->ea_pass = NULL;
	key->s_pass = NULL;
	key->r_width = -1;
	key->r_hight = -1;
	key->f_color = -1;
	key->c_color = -1;
	key->map_hight = 0;
	key->map_width = 0;
	key->map = NULL;
}

int		is_not_empty(char *line)
{
	while (*line)
	{
		if (*line != ' ')
			return (1);
		line++;
	}
	return (0);
}

int		sp_and_one(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '1')
			return (1);
		line++;
	}
	return (0);
}
