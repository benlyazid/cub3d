/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_in_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:06:14 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/07 16:48:30 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		setup_angle(t_all_info *info, int key)
{
	if (key == 124)
		info->angle += 5;
	if (key == 123)
		info->angle -= 5;
	if (info->angle == 365)
		info->angle = 5;
	if (info->angle == 0)
		info->angle = 360;
	return (info->angle);
}

void		exit_game(t_all_info *info)
{
	free(info->mp);
	free(info);
	exit(0);
}

int			check_abilitie_to_move(t_all_info *info, int key)
{
	int		index_x;
	int		index_y;
	int		index;
	double	angle;

	key = 0;
	angle = info->angle;
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

	if (key == 53 || key == 2 || key == 0 || key == 13
	|| key == 1 || key == 124 || key == 123)
	{
		setup_angle(info, key);
		if (key == 53)
			exit_game(info);
		xp = info->xp;
		yp = info->yp;
		effect_key_for_move(info, key, 3);
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

int			effect_key_for_move(t_all_info *info, int key, int multiple)
{
	if (key == 13)
	{
		info->xp += ((15 * multiple) * cos(info->angle * M_PI / 180));
		info->yp += ((15 * multiple) * sin(info->angle * M_PI / 180));
	}
	if (key == 1)
	{
		info->xp -= ((15 * multiple) * cos(info->angle * M_PI / 180));
		info->yp -= ((15 * multiple) * sin(info->angle * M_PI / 180));
	}
	if (key == 0)
	{
		info->xp -= ((15 * multiple) * cos((info->angle + 90) * M_PI / 180));
		info->yp -= ((15 * multiple) * sin((info->angle + 90) * M_PI / 180));
	}
	if (key == 2)
	{
		info->xp += ((15 * multiple) * cos((info->angle + 90) * M_PI / 180));
		info->yp += ((15 * multiple) * sin((info->angle + 90) * M_PI / 180));
	}
	return (0);
}
