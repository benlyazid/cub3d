/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:19:11 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/07 10:34:40 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_x_ray(t_all_info *info)
{
	int	divs;

	info->moins = 0;
	info->sprite = 0;
	divs = info->xp / info->size;
	divs *= info->size;
	info->x = divs;
	if (cos(info->angle * R_P) > 0)
		info->x += info->size;
	else
		info->moins = 1;
	info->y = info->yp + (info->x - info->xp) * tan(info->angle * R_P);
	if (cos(info->angle * R_P) > 0)
		info->xa = info->size;
	else
		info->xa = -1 * info->size;
	info->ya = info->xa * tan(info->angle * R_P);
}

void	add_sprit_to_x(t_all_info *info, int moins, float x, float y)
{
	int sprite_center_x;
	int sprite_center_y;

	if (info->sprite == 0)
	{
		sprite_center_x = ((int)x - moins) / (int)info->size;
		sprite_center_x *= (int)info->size;
		sprite_center_x += ((int)info->size / 2);
		sprite_center_y = (int)y / info->size;
		sprite_center_y *= (int)info->size;
		sprite_center_y += ((int)info->size / 2);
		info->sprt_strct_all->x_center = sprite_center_x;
		info->sprt_strct_all->y_center = sprite_center_y;
		info->sprt_strct_all->dest = DEST_2P(info->xp, info->yp, x - moins, y);
		info->sprt_strct_all->next = NULL;
	}
	else
		insert_sprite_to_x(info, moins, x, y);
	info->sprite = 1;
}

void	insert_sprite_to_x(t_all_info *info, int moins, float x, float y)
{
	int			sprite_center_x;
	int			sprite_center_y;
	t_sprite	*sprite_data;

	if (!(sprite_data = (t_sprite*)malloc(sizeof(t_sprite))))
		return ;
	sprite_center_x = ((int)x - moins) / (int)info->size;
	sprite_center_x *= (int)info->size;
	sprite_center_x += ((int)info->size / 2);
	sprite_center_y = (int)y / info->size;
	sprite_center_y *= (int)info->size;
	sprite_center_y += ((int)info->size / 2);
	sprite_data->x_center = sprite_center_x;
	sprite_data->y_center = sprite_center_y;
	sprite_data->dest = DEST_2P(info->xp, info->yp, x - moins, y);
	sprite_data->next = NULL;
	add_to_last(info->sprt_strct_all, sprite_data);
}

t_point	ray_casting_x(t_all_info *info)
{
	t_point		point;
	int			type;

	initial_x_ray(info);
	while (info->x >= 0 && info->y >= 0 && info->x < info->width_number
	* info->size && info->y < info->height_number * info->size)
	{
		type = get_type_from_maps(info->x - info->moins, info->y, info);
		if (type == 1 || type == 2)
		{
			if (type == 1)
			{
				point.x = info->x - info->moins;
				point.y = info->y;
				return (point);
			}
			if (type == 2)
				add_sprit_to_x(info, info->moins, info->x, info->y);
		}
		info->x += info->xa;
		info->y += info->ya;
	}
	point.x = -1;
	point.y = -1;
	return (point);
}
