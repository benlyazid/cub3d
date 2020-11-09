/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:33:13 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/09 13:20:09 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		loop(t_all_info *info)
{
	draw_2d_maps(info);
	move_player(info);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_all_info	*info;

	if (!(info = malloc(sizeof(t_all_info))))
		return (-1);
	info->sprite_struct_start = NULL;
	info->sprt_strct_all = NULL;
	if (check_error(info, argv) == -1)
		return (-1);
	if (check_error2(info, argv) == -1)
	{
		return (-1);
	}
	get_player_info(info);
	draw_2d_maps(info);
	move_player(info);
	if (check_save(info, argv, argc) != 0)
		return (0);
	free(info->maps);
	free(info->file);
	mlx_loop_hook(info->mlx_ptr, loop, info);
	mlx_loop(info->mlx_ptr);
	return (0);
}
