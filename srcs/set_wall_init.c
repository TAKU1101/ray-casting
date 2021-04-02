#include "cub3d.h"

void	init_xy(t_line_data *l_data, int q, t_game_data *data)
{
	if (q == 1 || q == 4)
		l_data->x = 1 - fmod(data->player.pos_x, 1.0);
	else
		l_data->x = fmod(data->player.pos_x, 1.0);
	if (q == 3 || q == 4)
		l_data->y = 1 - fmod(data->player.pos_y, 1.0);
	else
		l_data->y = fmod(data->player.pos_y, 1.0);
}

void	init_sign(int *c_sign, int *s_sign, int q)
{
	if (q == 1 || q == 4)
		*c_sign = 1;
	else
		*c_sign = -1;
	if (q == 1 || q == 2)
		*s_sign = 1;
	else
		*s_sign = -1;
}

void	init_xy_pos(t_line_data *l_data, float *x, float *y, int q)
{
	if (q == 1 || q == 2)
		*y = l_data->y * -1;
	else
		*y = l_data->y - 1;
	if (q == 2 || q == 3)
		*x = l_data->x * -1;
	else
		*x = l_data->x - 1;
}

double	init_radian(double player, double *h, int r_w, int r_h)
{
	*h = 1.0 / r_h;
	return (*h * (r_w / 2));
	(void)player;
}
