SRCS	= srcs/cub3d.c \
		  srcs/scan_file.c \
		  srcs/scan_utils.c \
		  srcs/scan_map.c \
		  srcs/check_map.c \
		  srcs/ch_int_map.c \
		  srcs/free_key.c \
		  srcs/check_file.c \
		  srcs/reload_window.c \
		  srcs/open_xpm.c \
		  srcs/set_wall_ad.c \
		  srcs/set_wall_init.c \
		  srcs/init_line_data.c \
		  srcs/set_line_sp.c \
		  srcs/ft_lst_sp.c \
		  srcs/set_sp_line.c \
		  srcs/key_units.c \
		  srcs/set_wall_utils.c \
		  srcs/is_coll.c \
		  srcs/bitmap.c \
		  srcs/init_header.c

OBJS	= $(SRCS:.c=.o)
LIBS    = -lXext -lX11
NAME    = cub3D
CC      = gcc -Wall -Wextra -Werror -g
# CC		= gcc -g
RM      = rm -f

$(NAME): $(OBJS)
	$(MAKE) -C ./minilibx-linux
	$(MAKE) -C ./libft
	$(MAKE) -C ./get_next_line
	cp ./minilibx-linux/libmlx_Linux.a .
	$(CC) $(OBJS) -L. -L.minilibx-linux -lmlx_Linux $(LIBS) -lm ./get_next_line/get_next_line.a -lm ./libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./get_next_line
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./get_next_line
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(NAME) libmlx_Linux.a cub3D.bmp

re: fclean all

.PHONY: all clean fclean re .c.o

