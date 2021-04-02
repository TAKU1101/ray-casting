#include "cub3d.h"

static int	**init_map(t_mapkey *keys)
{
	int **map;
	int i;

	if (!(map = (int **)malloc(keys->map_hight * sizeof(int *))))
		return (0);
	i = 0;
	while (i < keys->map_hight)
	{
		if (!(map[i] = (int *)ft_calloc(keys->map_width, sizeof(int))))
			return (0);
		i++;
	}
	return (map);
}

static int	map_val(t_player *player, char *line, int i, int j)
{
	if (j < (int)ft_strlen(line))
	{
		if (('0' <= line[j] && line[j] <= '2'))
			return (line[j] - '0');
		else if (line[j] == ' ')
			return (0);
		else if (ft_strchr("WESN", line[j]))
		{
			player->pos_y = i + 0.5;
			player->pos_x = j + 0.5;
			if (line[j] == 'N')
				player->dir = M_PI / 2;
			else if (line[j] == 'E')
				player->dir = 0;
			else if (line[j] == 'S')
				player->dir = (M_PI / 2) * -1;
			else if (line[j] == 'W')
				player->dir = M_PI;
			return (0);
		}
	}
	return (0);
}

int			**ch_int_map(t_list *map_lst, t_mapkey *keys, t_player *player)
{
	int		**map;
	char	*line;
	int		i;
	int		j;

	map = init_map(keys);
	i = 0;
	while (i < keys->map_hight)
	{
		j = 0;
		line = (char *)map_lst->content;
		while (j < keys->map_width)
		{
			map[i][j] = map_val(player, line, i, j);
			j++;
		}
		i++;
		map_lst = map_lst->next;
	}
	return (map);
}
