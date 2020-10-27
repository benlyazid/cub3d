# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 09:33:45 by kbenlyaz          #+#    #+#              #
#    Updated: 2020/10/27 10:36:30 by kbenlyaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
WWWW = -Wall -Wextra -Werror
HEADER = cub3d.h
MLX = /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
SRC =	check_file.c check_maps.c color.c draw_3d_maps.c draw_maps2d.c error.c get_from_file.c \
		get_info_from_file.c get_path.c link_list.c main.c maps.c maps_utils.c math.c \
		move_player_in_2d.c player.c player_view.c ray_casring_y.c ray_casting_x.c resolutin.c \
		save_file.c sprite.c texteur.c wall_info.c \

all : $(NAME)

$(NAME): $(SRC) $(HEADER) 
	cd libft && make all
	gcc -o $(NAME) $(WWW) $(SRC) ./libft/libft.a -L $(MLX)

clean :
	cd libft && make fclean

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all