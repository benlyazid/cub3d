/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_in_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:(20/01/02 17:42:11 by kbenlyaz          #+#    #+#             */
/*   Updated:(20/10/31 18:29:12 by kbenlyaz         ###   ########.fr       */
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
	angle = info->angle;

	index_x = ((int)info->xp + ((info->size / 2) * (int)cos(angle * R_P))) / (int)info->size;
	index_y = ((int)info->yp + ((info->size / 2) * (int)sin(angle * R_P))) / (int)info->size;	
	
	index_x = info->xp / info->size;
	index_y = info->yp / info->size;
	index = (index_y * (int)info->width_number + index_x);
	if (info->mp[index] == 1 || info->mp[index] == 2)
			return (0);
	return (1);
}

int			effect_move(int key, t_all_info *info)
{
	float xp;
	float yp;
	float angle;

	if (key ==53 || key == 2 || key == 0 || key == 13 || key == 1 || key == 124 || key == 123)
	{
		angle = info->angle;
		if (key == 53)
			exit(1);
		if (key == 124)
			info->angle += 5;
		if (key == 123)
			info->angle -= 5;
		xp = info->xp;
		yp = info->yp;
		if (info->angle == 365)
			info->angle = 5;
		if (info->angle == 0)
			info->angle = 360 ;
		effect_key_for_move(info, key, 2);
		if (check_abilitie_to_move(info, key))
		{
				info->xp = xp;
				info->yp = yp;
				effect_key_for_move(info, key, 1);
			draw_2d_maps(info);
			return (1);
		}
		
		info->xp = xp;
		info->yp = yp;
	}
	return (0);
}

int		effect_key_for_move(t_all_info *info, int key, int multiple)
{

	if (key == 13) // w
	{
		info->xp += ((20 * multiple) * cos(info->angle * M_PI / 180));
		info->yp += ((20 * multiple) * sin(info->angle * M_PI / 180)); 
	}
	if (key == 1) //s
	{
		info->xp -= ((20 * multiple) * cos(info->angle * M_PI / 180));
		info->yp -= ((20 * multiple) * sin(info->angle * M_PI / 180)); 
	}
	
	
	if (key == 0) // a
	{
		info->xp -= ((20 * multiple) * cos((info->angle + 90) * M_PI / 180));
		info->yp -= ((20 * multiple) * sin((info->angle + 90) * M_PI / 180));
	}
	if (key == 2) //d
	{
		info->xp += ((20 * multiple) * cos((info->angle + 90) * M_PI / 180));
		info->yp += ((20 * multiple) * sin((info->angle + 90) * M_PI / 180));
	}
	return (0);
}