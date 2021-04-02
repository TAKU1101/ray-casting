#include "cub3d.h"

static void	get_data(t_img *img)
{
	img->data = (int *)mlx_get_data_addr(img->ptr, &(img->bpp), \
	&(img->size_l), &(img->endian));
}

void		open_xpm(t_game_data *data)
{
	data->imgs.no_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.no_pass, &(data->imgs.no_w), &(data->imgs.no_h));
	get_data(&(data->imgs.no_img));
	data->imgs.so_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.so_pass, &(data->imgs.so_w), &(data->imgs.so_h));
	get_data(&(data->imgs.so_img));
	data->imgs.we_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.we_pass, &(data->imgs.we_w), &(data->imgs.we_h));
	get_data(&(data->imgs.we_img));
	data->imgs.ea_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.ea_pass, &(data->imgs.ea_w), &(data->imgs.ea_h));
	get_data(&(data->imgs.ea_img));
	data->imgs.s_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.s_pass, &(data->imgs.s_w), &(data->imgs.s_h));
	get_data(&(data->imgs.s_img));
	data->img.ptr = mlx_new_image(data->mlx, (data->mapkey).r_width, \
											(data->mapkey).r_hight);
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, \
		&(data->img.bpp), &(data->img.size_l), &(data->img.endian));
	init_window(data);
}

void		open_xpm_save(t_game_data *data)
{
	data->imgs.no_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.no_pass, &(data->imgs.no_w), &(data->imgs.no_h));
	get_data(&(data->imgs.no_img));
	data->imgs.so_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.so_pass, &(data->imgs.so_w), &(data->imgs.so_h));
	get_data(&(data->imgs.so_img));
	data->imgs.we_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.we_pass, &(data->imgs.we_w), &(data->imgs.we_h));
	get_data(&(data->imgs.we_img));
	data->imgs.ea_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.ea_pass, &(data->imgs.ea_w), &(data->imgs.ea_h));
	get_data(&(data->imgs.ea_img));
	data->imgs.s_img.ptr = mlx_xpm_file_to_image(data->mlx, \
	data->mapkey.s_pass, &(data->imgs.s_w), &(data->imgs.s_h));
	get_data(&(data->imgs.s_img));
	data->img.ptr = mlx_new_image(data->mlx, (data->mapkey).r_width, \
											(data->mapkey).r_hight);
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, \
		&(data->img.bpp), &(data->img.size_l), &(data->img.endian));
	init_window_save(data);
}
