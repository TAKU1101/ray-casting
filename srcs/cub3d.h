#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define KEYCODE_SPACE	32
# define KEYCODE_ENTER	65293
# define KEYCODE_RIGFT	65363
# define KEYCODE_LEFT	65361
# define KEYCODE_UP		65362
# define KEYCODE_DOWN	65364
# define KEYCODE_W		119
# define KEYCODE_A		97
# define KEYCODE_S		115
# define KEYCODE_D		100
# define KEYCODE_ESC	65307

# define PLAYER_SPEED	25
# define PLAYER_R_SPEED 50

# define HEADER_DATA_SIZE 14
# define HEADER_INFO_SIZE 40
# define HEADER_SIZE 54

typedef struct	s_mapkey
{
	char		*no_pass;
	char		*so_pass;
	char		*we_pass;
	char		*ea_pass;
	char		*s_pass;
	int			r_width;
	int			r_hight;
	int			f_color;
	int			c_color;
	int			map_hight;
	int			map_width;
	int			**map;
}				t_mapkey;

typedef struct	s_player
{
	float		dir;
	float		pos_x;
	float		pos_y;
}				t_player;

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_imgs
{
	t_img		no_img;
	int			no_h;
	int			no_w;
	t_img		so_img;
	int			so_h;
	int			so_w;
	t_img		we_img;
	int			we_h;
	int			we_w;
	t_img		ea_img;
	int			ea_h;
	int			ea_w;
	t_img		s_img;
	int			s_h;
	int			s_w;
}				t_imgs;

typedef struct	s_game_data
{
	t_mapkey	mapkey;
	t_player	player;
	t_imgs		imgs;
	t_img		img;
	void		*mlx;
	void		*win;
}				t_game_data;

typedef struct	s_sp
{
	int			w_n;
	int			h_n;
	struct s_sp	*next;
}				t_sp;

typedef struct	s_line_data
{
	int			i;
	int			*img;
	int			line_n;
	int			w;
	int			h;
	float		x;
	float		y;
	float		r;
	float		pos;
	t_sp		*next;
}				t_line_data;

int				scan_file(char *pass, t_mapkey *keys, t_player *player);
int				skip_sp(char *line);
int				skip_num(char *line);
void			init_mapkey(t_mapkey *key);
int				scan_map(t_mapkey *keys, char *line, t_list **map);
int				check_map(t_list *map);
int				is_not_empty(char *line);
int				sp_and_one(char *line);
int				**ch_int_map(t_list *map_lst, t_mapkey *keys, t_player *player);
void			free_line(void *line);
void			free_map(t_list *map);
void			free_keys(t_mapkey *keys, int **int_map);
int				check_file(t_mapkey *keys, t_player *player, \
												int argv, char *argc[]);
void			reload_window(t_game_data *data);
void			init_window(t_game_data *data);
void			init_window_save(t_game_data *data);
void			open_xpm(t_game_data *data);
void			open_xpm_save(t_game_data *data);
void			set_wall(int *img_data, t_game_data *data);
void			init_xy(t_line_data *l_data, int q, t_game_data *data);
void			init_sign(int *c_sign, int *s_sign, int q);
void			init_xy_pos(t_line_data *l_data, float *x, float *y, int q);
double			init_radian(double player, double *h, int r_w, int r_h);
void			init_line_x(t_line_data *l_data, t_game_data *data, \
															float n, int q);
void			init_line_y(t_line_data *l_data, t_game_data *data, \
															float n, int q);
void			set_line_sp(t_line_data *l_data, t_game_data *data, \
															float x, float y);
t_sp			*ft_lstnew_sp(int h, int w);
void			ft_lstadd_front_sp(t_sp **lst, t_sp *new);
void			ft_lstdelone_sp(t_sp *lst);
void			ft_lstclear_sp(t_sp **lst);
void			set_sp_line(t_game_data *data, int *map, t_line_data *l_data);
int				key_press(int keycode, t_game_data *data);
int				game_fin(t_game_data *data);
int				ft_close(t_game_data *data);
void			jif_init(int *j, int *i, int *f, t_game_data *data);
void			if_init(int *i, int *f, t_game_data *data, int len);
void			is_coll(t_player *player, float x_d, float y_d, \
														t_game_data *data);
void			bitmap(t_game_data *data);
void			init_header(unsigned char *header, t_game_data *data);
int				expose(t_game_data *data);
void			reload_r_d(double *x);
void			scan_free(t_list *map, t_mapkey *keys);

#endif
