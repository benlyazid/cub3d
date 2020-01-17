/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:53:57 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/01/15 13:56:45 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub3d.h"


t_all_info *move_player(t_all_info *info)
{
	mlx_hook(info->win_ptr, 2, 0, effect_move, info);
	return (info);
}

int			draw_image_player(t_all_info *info)
{
	float	angle;
	float 	r;
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
int				remove_player_image(t_all_info *info, int xp, int yp)
{
	float	angle;
	float 	r;
	int		x;
	int		y;
	int 	index;


	angle = 0;
	while (angle <= 2* M_PI)
	{
		r = 10;
		while (r >= 0)
		{
			x = floor(xp + (r * cos(angle)));
			y = floor(yp + (r * sin(angle)));
			index = (y * info->width) + x;
			info->data[index] = 0x0;			
			r -= 0.1;
		}
		angle += (0.1 * M_PI / 180);
	}
	
	return (0);
}
