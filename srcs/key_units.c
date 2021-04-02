#include "cub3d.h"

void		reload_r(float *x)
{
	if (*x > M_PI)
	{
		*x = M_PI - (*x - M_PI);
		*x *= -1;
	}
	else if (*x < (M_PI * -1))
	{
		*x *= -1;
		*x = M_PI - (*x - M_PI);
	}
}

void		reload_r_d(double *x)
{
	if (*x > M_PI)
	{
		*x = M_PI - (*x - M_PI);
		*x *= -1;
	}
	else if (*x < (M_PI * -1))
	{
		*x *= -1;
		*x = M_PI - (*x - M_PI);
	}
}

static void	reload_pos(int keycode, t_player *player, t_game_data *data)
{
	if (KEYCODE_RIGFT == keycode)
		player->dir -= M_PI / PLAYER_R_SPEED;
	else if (KEYCODE_LEFT == keycode)
		player->dir += M_PI / PLAYER_R_SPEED;
	else if (KEYCODE_W == keycode)
	{
		is_coll(player, cos(player->dir) / PLAYER_SPEED, \
			(sin(player->dir) / PLAYER_SPEED) * -1, data);
	}
	else if (KEYCODE_S == keycode)
	{
		is_coll(player, (cos(player->dir) / PLAYER_SPEED) * -1, \
			sin(player->dir) / PLAYER_SPEED, data);
	}
	else if (KEYCODE_A == keycode)
	{
		is_coll(player, (cos((M_PI / 2) - player->dir) / PLAYER_SPEED) * -1, \
			(sin((M_PI / 2) - player->dir) / PLAYER_SPEED) * -1, data);
	}
	else if (KEYCODE_D == keycode)
	{
		is_coll(player, cos((M_PI / 2) - player->dir) / PLAYER_SPEED, \
			sin((M_PI / 2) - player->dir) / PLAYER_SPEED, data);
	}
}

int			game_fin(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.no_img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.so_img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.we_img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.ea_img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.s_img.ptr);
	mlx_destroy_window(data->mlx, data->win);
	free_keys(&(data->mapkey), data->mapkey.map);
	free(data->mlx);
	exit(1);
	(void)data;
	return (0);
}

int			key_press(int keycode, t_game_data *data)
{
	t_player	*player;

	player = &(data->player);
	reload_pos(keycode, player, data);
	reload_r(&(player->dir));
	if (keycode == KEYCODE_ESC)
		game_fin(data);
	reload_window(data);
	(void)player;
	return (0);
}
