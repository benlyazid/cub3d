/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:33:13 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/27 10:00:14 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_all_info	*info;

	info = malloc(sizeof(t_all_info));
	info->sprite_struct_start = NULL;
	info->all_sprt = NULL;
	info->fd = open(argv[1], O_RDONLY);
	if (check_file_error(info, argv[1]) == -1)
		return (-1);
	get_all_info(info);
	if (check_image_error(info) != 1)
		return (-1);
	get_player_info(info);
	draw_2d_maps(info);
	move_player(info);
	if (check_save_error(info, argv[2], argc) != 1)
		return (1);
	free(info->maps);
	free(info->file);
	mlx_loop(info->mlx_ptr);
	return (0);
}
