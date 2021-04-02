#include "cub3d.h"

void	is_coll(t_player *player, float x_d, float y_d, t_game_data *data)
{
	int x_b;
	int y_b;
	int x;
	int y;

	x_b = (int)(player->pos_x);
	y_b = (int)(player->pos_y);
	x = (int)(player->pos_x + x_d);
	y = (int)(player->pos_y + y_d);
	if ((x_b - x) && (y_b - y))
	{
		if (data->mapkey.map[y][x] == 1 || data->mapkey.map[y_b][x] == 1 || \
					data->mapkey.map[y][x_b] == 1)
			return ;
	}
	else if ((x_b - x))
	{
		if (data->mapkey.map[y_b][x] == 1)
			return ;
	}
	else if ((y_b - y))
		if (data->mapkey.map[y][x_b] == 1)
			return ;
	player->pos_x += x_d;
	player->pos_y += y_d;
}
