#conter=1
#while [ $conter -le 50 ]
#do 
	gcc	-Wall -Wextra -Werror  -I /usr/local/include/  *.c ./libft/*.a  -L  /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit  &&./a.out file.cub 
#	((conter++))
#done
#echo finish