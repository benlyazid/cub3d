/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:25:22 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 19:17:06 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			insert_sprit_x(t_all_info *info, int moins, double x, double y)
{
	if (info->sprite == 0)
	{
		info->all_sprt->xc = (int)(((int)x - moins) / (int)info->size);
		info->all_sprt->xc *= (int)info->size;
		info->all_sprt->xc += (int)(info->size / 2);
		info->all_sprt->yc = (int)((int)y / info->size);
		info->all_sprt->yc *= (int)info->size;
		info->all_sprt->yc += (int)(info->size / 2);
		info->all_sprt->visible = info->cast_type;
		info->all_sprt->x = x;
		info->all_sprt->y = y;
		info->all_sprt->dest = destance_2_points(info->xp,
		info->yp, x - moins, y);
		info->all_sprt->next = NULL;
	}
	return (1);
}

int			add_sprit_allocate_x(t_all_info *info, int m, double x, double y)
{
	t_sprite	*sprite_data;

	sprite_data = (t_sprite*)malloc(sizeof(t_sprite));
	if (info->sprite != 0)
	{
		sprite_data->xc = (int)(((int)x - m) / (int)info->size);
		sprite_data->xc *= (int)info->size;
		sprite_data->xc += (int)(info->size / 2);
		sprite_data->yc = (int)y / info->size;
		sprite_data->yc *= (int)info->size;
		sprite_data->yc += (int)(info->size / 2);
		sprite_data->visible = info->cast_type;
		sprite_data->x = x;
		sprite_data->y = y;
		sprite_data->dest = destance_2_points(info->xp,
		info->yp, x - m, y);
		sprite_data->next = NULL;
		add_to_last(info->all_sprt, sprite_data);
	}
	//free(sprite_data);
	return (1);
}

t_point		execute_casting_x(t_all_info *info, int moins, double x, double y)
{
	t_point	point;

	if (get_type_from_maps(x - moins, y, info) == 1)
	{
		point.x = x - moins;
		point.y = y;
	}
	else if (get_type_from_maps(x - moins, y, info) == 2)
	{
		info->cast_type = 'x';
		insert_sprit_x(info, moins, x, y);
		add_sprit_allocate_x(info, moins, x, y);
		info->sprite = 1;
	}
	return (point);
}
