#include "cub3d.h"

void	free_keys(t_mapkey *keys, int **int_map)
{
	int i;

	i = 0;
	while (i < keys->map_hight && int_map)
	{
		if (int_map[i])
			free(int_map[i]);
		i++;
	}
	if (int_map)
		free(int_map);
	if (keys->no_pass)
		free(keys->no_pass);
	if (keys->so_pass)
		free(keys->so_pass);
	if (keys->we_pass)
		free(keys->we_pass);
	if (keys->ea_pass)
		free(keys->ea_pass);
	if (keys->s_pass)
		free(keys->s_pass);
}

void	scan_free(t_list *map, t_mapkey *keys)
{
	write(1, "File Error\n", 11);
	free_map(map);
	free_keys(keys, keys->map);
}
