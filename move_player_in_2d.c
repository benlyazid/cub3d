/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_in_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:11 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/19 19:34:07 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

int			check_abilitie_to_move(t_all_info *info, int key)
{
	int		index_x;
	int		index_y;
	int 	index;
	float	angle;

	key = 0;
	angle = 0;
	while (angle <= 2 * M_PI)
	{
	index_x = ((int)info->xp + ((info->size / 4) * (int)cosf(angle))) / (int)info->size;
	index_y = ((int)info->yp + ((info->size / 4) * (int)sinf(angle))) / (int)info->size;	

	index = (index_y * (int)info->width_number + index_x);

	if (info->mp[index] == 1 || info->mp[index] == 2)
			return (0);
		angle += (0.5 * M_PI / 180);
	}
	return (1);
}

int			effect_move(int key, t_all_info *info)
{
	float xp;
	float yp;
	float angle;
	
	if (key ==53 || key == 2 || key == 0 || key == 13 || key == 1)
	{
		//printf("key is : %d\n", key);
		angle = info->angle;
		if (key == 53)
			exit(1);
		if (key == 2)
			//info->angle += (60/ info->width) * 50;
			info->angle += 30;
		if (key == 0)
			//info->angle -=  (60/ info->width) * 50;
			info->angle -=  30;
		xp = info->xp;
		yp = info->yp;

		//// i just add this lina of the angle
		if (info->angle == 390)
			info->angle = (int)info->angle % 360;
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
		info->xp += ((info->size / 5) * cosf(info->angle * M_PI / 180));
		info->yp += ((info->size / 5) * sinf(info->angle * M_PI / 180)); 
	}
	if (key == 1) //s
	{
		info->xp -= ((info->size / 5) * cosf(info->angle * M_PI / 180));
		info->yp -= ((info->size / 5) * sinf(info->angle * M_PI / 180)); 
	}
	
	return (0);
}