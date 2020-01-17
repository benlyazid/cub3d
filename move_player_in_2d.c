/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_in_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:11 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/01/16 16:26:13 by kbenlyaz         ###   ########.fr       */
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
	index_x = (info->xp + (5 * cos(angle))) * info->width_number / info->width;
	index_y = (info->yp + (5 * sin(angle))) * info->height_number / info->height;	
	index = (index_y * info->width_number  + index_x) * 2;
	if (info->maps[index] == '1')
			return (0);
		angle += (0.1 * M_PI / 180);
	}
	return (1);
}

int			effect_move(int key, t_all_info *info)
{
	int xp;
	int yp;
	float angle;
	
	angle = info->angle;
	if (key == 53)
		exit(1);
	if (key == 2)
		info->angle += 3;
	if (key == 0)
		info->angle -= 3;
	xp = info->xp;
	yp = info->yp;
	effect_key_for_move(info, key);
	if (check_abilitie_to_move(info, key))
	{
		//remove_3d_image(info);
		rm_all(info);
		//remove_player_image(info,xp,yp);
		//destrow_image_view_angle(info,xp, yp, angle);
		//destrow_image_view(info, xp, yp, angle);
		//rm_ray_casting_x(info,xp, yp, angle);
		draw_2d_maps(info);
		return (1);
	}
	info->xp = xp;
	info->yp = yp;
	return (0);
}

int		effect_key_for_move(t_all_info *info, int key)
{
	// ft_putstr_fd(ft_itoa(info->angle),1);
	// ft_putstr_fd("    xp----->: ", 1);
	// ft_putstr_fd(ft_itoa(info->xp),1);
	// ft_putstr_fd("    yp----->: ", 1);
	// ft_putstr_fd(ft_itoa(info->yp),1);
	if (key == 13) // w
	{
		info->xp += (int)((info->width_size / 5) * cos(info->angle * M_PI / 180));
		info->yp += (int)((info->height_size / 5) * sin(info->angle * M_PI / 180)); 
	
	}
	// ft_putstr_fd("    xpn----->: ", 1);
	// ft_putstr_fd(ft_itoa(info->xp),1);
	// ft_putstr_fd("    ypn----->: ", 1);
	// ft_putstr_fd(ft_itoa(info->yp),1);
	// ft_putstr_fd("\n", 1);
	
	if (key == 1) //s
	{
		info->xp -= (int)((info->width_size / 5) * cos(info->angle * M_PI / 180));
		info->yp -= (int)((info->height_size / 5) * sin(info->angle * M_PI / 180)); 
	}
	return (0);
}