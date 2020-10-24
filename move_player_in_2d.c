/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_in_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:11 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/24 18:33:08 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

int			check_abilitie_to_move(t_all_info *info, int key)
{
	int		index_x;
	int		index_y;
	int 	index;
	double	angle;

	key = 0;
	angle = 0;
	while (angle <= 2 * M_PI)
	{
	index_x = ((int)info->xp + ((info->size / 4) * (int)cos(angle))) / (int)info->size;
	index_y = ((int)info->yp + ((info->size / 4) * (int)sin(angle))) / (int)info->size;	

	index = (index_y * (int)info->width_number + index_x);

	if (info->mp[index] == 1 || info->mp[index] == 2)
			return (0);
		angle += (0.5 * M_PI / 180);
	}
	return (1);
}

int			effect_move(int key, t_all_info *info)
{
	double xp;
	double yp;
	double angle;
	if (key ==53 || key == 2 || key == 0 || key == 13 || key == 1 || key == 124 || key == 123)
	{
		angle = info->angle;
		if (key == 53)
			{
				free(info->mp);
				free(info);
				leakcheckfull();
				exit(1);
			}
		if (key == 124)
			info->angle += 10;
		if (key == 123)
			info->angle -= 10;
		
		
		xp = info->xp;
		yp = info->yp;

		if (info->angle == 370)
			info->angle = 10;
		if (info->angle == 0)
			info->angle = 360 ;
		effect_key_for_move(info, key);
		if (check_abilitie_to_move(info, key))
		{
			draw_2d_maps(info);
			return (1);
		}
		
		info->xp = xp;
		info->yp = yp;
	}
	return (0);
}

int		effect_key_for_move(t_all_info *info, int key)
{

	if (key == 13) // w
	{
		info->xp += ((info->size / 5) * cos(info->angle * M_PI / 180));
		info->yp += ((info->size / 5) * sin(info->angle * M_PI / 180)); 
	}
	if (key == 1) //s
	{
		info->xp -= ((info->size / 5) * cos(info->angle * M_PI / 180));
		info->yp -= ((info->size / 5) * sin(info->angle * M_PI / 180)); 
	}
	
	
	if (key == 0) // a
	{
			info->xp -= ((info->size / 5) * cos((info->angle + 90) * M_PI / 180));
			info->yp -= ((info->size / 5) * sin((info->angle + 90) * M_PI / 180));
	}
	if (key == 2) //d
	{
			info->xp += ((info->size / 5) * cos((info->angle + 90) * M_PI / 180));
			info->yp += ((info->size / 5) * sin((info->angle + 90) * M_PI / 180));
	}
	
	return (0);
}