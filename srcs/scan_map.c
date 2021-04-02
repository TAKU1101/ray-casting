#include "cub3d.h"

static int	is_map(char *line)
{
	line = line + skip_sp(line);
	return (('1' == *line));
}

static int	is_full(t_mapkey *keys)
{
	if (keys->no_pass && keys->so_pass && keys->we_pass && \
		keys->ea_pass && keys->s_pass && keys->r_width != -1 && \
		keys->r_hight != -1 && keys->f_color != -1 && keys->c_color != -1)
		return (1);
	return (0);
}

int			scan_map(t_mapkey *keys, char *line, t_list **map)
{
	static int	flag;

	if ((!is_map(line) && is_not_empty(line) && keys->map_hight))
		return (1);
	if (is_map(line) && !is_full(keys))
		return (1);
	if (flag && !is_map(line))
		return (1);
	if (is_map(line))
	{
		flag = 1;
		(keys->map_hight)++;
		ft_lstadd_back(map, ft_lstnew(ft_strdup(line)));
		if ((int)ft_strlen(line) > keys->map_width)
			keys->map_width = ft_strlen(line);
	}
	return (0);
}

void		free_line(void *line)
{
	free(line);
}

void		free_map(t_list *map)
{
	ft_lstclear(&map, &free_line);
}
