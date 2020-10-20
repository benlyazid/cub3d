gcc	 -o cube_3d -I /usr/local/include/  *.c ./libft/*.a  -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit  -Ofast  -fsanitize=address && ./cube_3d file.cub
gcc -Wextra -Werror -Wall srcs/*.c GNL/*.c Libft/*.c -I mlx -L OpenGL -lmlx -framework OpenGL -framework AppKit

gcc -I /usr/local/include/ *.c ./libft/*.a  -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit