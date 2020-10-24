/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:33:13 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/24 12:51:07 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//396
int		main(int argc, char *argv[])
{
	int ret;
	ret = 0;
	t_all_info	*info;
	int a ,b,c, sw, sh;
	info = malloc(sizeof(t_all_info));
	info->sprite_struct_start = NULL;
	info->sprite_alloc = 0;
	info->sprite_struct_all = NULL;
	
	int	fd;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		set_error(100, info);
		return (-1);
	}
	
	info->file = read_file(fd);
	
	if (info->file == NULL)
	{
		set_error(100, info);
		return - 1;
	}
	
	if (check_file(info->file) == -1 || check_file_if_is_dot_cub(argv[1]) == -1)
	{
		set_error(90, info);
		return -1;
	}
	
	int res =check_the_maps(info);
	if (res == -1)
	{
		set_error(80, info);
		return -1;
	}
	
	get_all_info(argv[argc - 1], info);	
	info->mlx_ptr = mlx_init();
	if (info->height == 0 || info->width == 0)
	{
		set_error(70, info);
		return -1;
	}


	info->win_ptr = mlx_new_window(info->mlx_ptr, info->width, info->height, "mlx");
	info->img_3d = mlx_new_image(info->mlx_ptr, info->width, info->height);
	info->data_3d = (int*)mlx_get_data_addr(info->img_3d, &a, &b, &c);

	ret += get_no_texteur_from_file(info);
	ret += get_ea_texteur_from_file(info);
	ret += get_we_texteur_from_file(info);
	ret += get_so_texteur_from_file(info);
	if (ret != 4)
	{
		set_error(60, info);
		return -1;
	}
	ret += get_sprite_from_file(info);
	if (ret != 5)
	{
		set_error(50, info);
		return -1;
	}
	if(info->color_flor.status == 0 || info->color_coll.status == 0)
	{
		set_error(40, info);
		return -1;
	}
	
	get_player_info(info);

	draw_2d_maps(info);
	move_player(info);

	if (argc > 2)
	{
		if (check_argv(argv[2]) == -1)
		{
			set_error(30, info);
			return (-1);
		}
		else
		{
			save_bmp(info);
			free(info->mp);
			free(info);
			leakcheckfull();
			
			return (1);
		}
	}
	
	free(info->maps);
	free(info->file);
	//save(info);
	///return 0;
	////////
	mlx_loop(info->mlx_ptr);


	return (0);
}	
//1160 560