#include "cub3d.h"

int			expose(t_game_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	(void)data;
	return (0);
}

void		reload_size(t_mapkey *keys, t_game_data *data)
{
	int	sizex;
	int sizey;

	mlx_get_screen_size(data->mlx, &sizex, &sizey);
	if (sizex < data->mapkey.r_width)
	{
		data->mapkey.r_width = sizex;
		keys->r_width = sizex;
	}
	if (sizey < data->mapkey.r_hight)
	{
		data->mapkey.r_hight = sizey;
		keys->r_hight = sizey;
	}
}

int			main(int argv, char *argc[])
{
	t_mapkey	keys;
	t_player	player;
	t_game_data	data;
	int			r;

	if (!(r = check_file(&keys, &player, argv, argc)))
		return (0);
	data.mapkey = keys;
	data.player = player;
	data.mlx = mlx_init();
	if (r == 2)
	{
		open_xpm_save(&data);
		bitmap(&data);
		return (0);
	}
	reload_size(&keys, &data);
	data.win = mlx_new_window(data.mlx, keys.r_width, keys.r_hight, "Cub3D");
	open_xpm(&data);
	mlx_hook(data.win, 2, 1L << 0, &key_press, &data);
	mlx_hook(data.win, 17, 1L << 17, &game_fin, &data);
	mlx_hook(data.win, 12, 1L << 15, &expose, &data);
	mlx_loop(data.mlx);
	free_keys(&keys, keys.map);
}
