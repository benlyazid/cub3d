/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:33:13 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/01/15 16:39:12 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		main(int argc, char *argv[])
{
	t_all_info	info;
	int a ,b,c;
	get_all_info(argv[argc - 1], &info);
	info.mlx_ptr = mlx_init();
	info.win_ptr = mlx_new_window(info.mlx_ptr,info.width, info.height, "mlx");
	info.img = mlx_new_image(info.mlx_ptr, info.width, info.height);
	info.data = (int*)mlx_get_data_addr(info.img, &a, &b, &c);
	draw_2d_maps(&info);
	move_player(&info);

	mlx_loop(info.mlx_ptr);

	return (0);
}	
// 		index =(int) ((index_y * info->width_number  + index_x) * 2);