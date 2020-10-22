/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:53:57 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/22 18:21:06 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub3d.h"


int	exit_funct(int key, t_all_info *info)
{
	exit(1);
	return (0);
}

int move_player(t_all_info *info)
{
	mlx_hook(info->win_ptr, 2, 0, effect_move, info);
	mlx_hook(info->win_ptr, 17, 0, exit_funct, info);
	return 0;
}





int			draw_image_player(t_all_info *info)
{
	double	angle;
	double 	r;
	int	x;
	int	y;
	int		andex;

	angle = 0;
	while (angle <= 2 * M_PI)
	{
		r = 10;
		while (r >= 0)
		{
			x = (int)(((info->xp) +(r * cos(angle))));
			y = (int)(((info->yp) + (r * sin(angle))));
			andex = round((y * info->width) + x);
			info->data[andex] = 0x16FF00;			
			r -= 1;
		}
		angle += (0.1 * M_PI / 180);
	}
	
	return (0);
}
