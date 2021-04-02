#include "cub3d.h"

static void	freee(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.no_img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.so_img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.we_img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.ea_img.ptr);
	mlx_destroy_image(data->mlx, data->imgs.s_img.ptr);
	free_keys(&(data->mapkey), data->mapkey.map);
	free(data->mlx);
}

static void	set_zero(unsigned char *line, int real_w)
{
	int i;

	i = 0;
	while (i < real_w)
	{
		line[i] = 0;
		i++;
	}
}

static void	set_data(int fd, t_game_data *data)
{
	unsigned char	line[data->mapkey.r_width * 3 + data->mapkey.r_width % 4];
	int				real_w;
	int				i;
	int				j;

	real_w = data->mapkey.r_width * 3 + data->mapkey.r_width % 4;
	set_zero(line, real_w);
	i = 0;
	while (i < data->mapkey.r_hight)
	{
		j = 0;
		while (j < data->mapkey.r_width)
		{
			line[j * 3] = (unsigned char)(data->img.data[(data->mapkey.\
				r_hight - i - 1) * data->mapkey.r_width + j] & 0xFF);
			line[j * 3 + 1] = (unsigned char)(data->img.data[(data->mapkey.\
				r_hight - i - 1) * data->mapkey.r_width + j] >> 8 & 0xFF);
			line[j * 3 + 2] = (unsigned char)(data->img.data[(data->mapkey.\
				r_hight - i - 1) * data->mapkey.r_width + j] >> 16 & 0xFF);
			j++;
		}
		write(fd, line, real_w);
		i++;
	}
}

static void	write_header(int fd, t_game_data *data)
{
	unsigned char	header[HEADER_SIZE];

	init_header(header, data);
	write(fd, header, HEADER_SIZE);
	set_data(fd, data);
}

void		bitmap(t_game_data *data)
{
	int fd;

	fd = open("cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, \
						__S_IREAD | __S_IWRITE);
	write_header(fd, data);
	freee(data);
	(void)data;
}
