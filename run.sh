














#./x_malloc/compile.sh 2 LC main.c  gcc -o cube_3d -I /usr/local/include/   check_file.c data_for_2d_maps.c draw_3d_maps.c draw_maps2d.c draw_mini_maps.c error.c get_from_file.c get_info_from_file.c get_path.c link_list.c math.c move_player_in_2d.c player.c player_view.c save.c sprite.c texteur.c  ./libft/*.a  -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit  -Ofast  -fsanitize=address && ./cube_3d file.cub
#gcc -Wextra -Werror -Wall srcs/*.c GNL/*.c Libft/*.c -I mlx -L OpenGL -lmlx -framework OpenGL -framework AppKit#
#gcc -o cube_3d -I /usr/local/include/  *.c  ./libft/*.a  -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit && ./cube_3d file.cub
#gcc -I /usr/local/include/ *.c ./libft/*.a  -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
gcc    -o cube_3d  *.c  ./libft/*.a  -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit && ./cube_3d file.cub
#./compile.sh 2 LCF main.c gcc    -o cube_3d check_file.c check_the_maps.c colors.c draw_3d_maps.c draw_maps2d.c error.c get_from_file.c get_info_from_file.c get_path.c link_list.c  maps.c move_player_in_2d.c player.c ray_casting_x.c ray_casting_y.c resolution.c save.c save2.c sheck_data.c sprite.c texteur.c utils.c wall.c  ./libft/*.a  -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit   && ./cube_3d file.cub
