/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:18:26 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/04 12:48:00 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	insert_sprite_to_y(t_all_info *info, int moins, float x, float y)
{
	int			sprite_center_x;
	int			sprite_center_y;
	t_sprite	*sprite_data;

	sprite_center_x = ((int)x) / (int)info->size;
	sprite_center_x *= (int)info->size;
	sprite_center_x += ((int)info->size / 2);
	sprite_center_y = (int)(y - info->moins) / info->size;
	sprite_center_y *= (int)info->size;
	sprite_center_y += ((int)info->size / 2);
	sprite_data = (t_sprite*)malloc(sizeof(t_sprite));
	sprite_data->x_center = sprite_center_x;
	sprite_data->y_center = sprite_center_y;
	sprite_data->dest = DEST_2P(info->xp, info->yp, x, y - info->moins);
	sprite_data->next = NULL;
	add_to_last(info->sprt_strct_all, sprite_data);
}

void	add_sprit_to_y(t_all_info *info, int moins, float x, float y)
{
	int sprite_center_x;
	int sprite_center_y;

	sprite_center_x = ((int)x) / (int)info->size;
	sprite_center_x *= (int)info->size;
	sprite_center_x += ((int)info->size / 2);
	sprite_center_y = (int)(y - info->moins) / info->size;
	sprite_center_y *= (int)info->size;
	sprite_center_y += ((int)info->size / 2);
	if (info->sprite == 0)
	{
		info->sprt_strct_all->x_center = sprite_center_x;
		info->sprt_strct_all->y_center = sprite_center_y;
		info->sprt_strct_all->next = NULL;
		info->sprt_strct_all->dest = DEST_2P(info->xp, info->yp, x, y - moins);
	}
	else
	{
		insert_sprite_to_y(info, moins, x, y);
	}
	info->sprite = 1;
}

void	initial_y_ray(t_all_info *info)
{
	int	divs;

	info->moins = 0;
	divs = (int)info->yp / (int)info->size;
	divs *= (int)info->size;
	info->y = divs;
	if (sin(info->angle * R_P) > 0)
		info->y += info->size;
	else
		info->moins = 1;
	info->x = info->xp + ((info->y - info->yp) / tan(info->angle * R_P));
	if (sin(info->angle * R_P) > 0)
		info->ya = info->size;
	else
		info->ya = -1 * info->size;
	if (sin(info->angle * R_P) == 1 || sin(info->angle * R_P) == -1)
		info->xa = 0;
	else
		info->xa = info->ya / tan(info->angle * R_P);
}

t_point	ray_casting_y(t_all_info *info)
{
	t_point		point;
	int			divs;
	int			sprite_center_x;
	int			sprite_center_y;
	int			type;

	initial_y_ray(info);
	while (info->x >= 0.0 && info->y >= 0.0 && info->x < info->width_number
	* info->size && info->y < info->height_number * info->size)
	{
		type = get_type_from_maps(info->x, info->y - info->moins, info);
		if (type == 1)
		{
			point.x = info->x;
			point.y = info->y - info->moins;
			return (point);
		}
		if (type == 2)
			add_sprit_to_y(info, info->moins, info->x, info->y);
		info->x += info->xa;
		info->y += info->ya;
	}
	point.x = -1;
	point.y = -1;
	return (point);
}

float	destance(t_all_info *info, int x, int y)
{
	float	destance;
	float	xx;
	float	yy;

	xx = (info->xp - x) * (info->xp - x);
	yy = (info->yp - y) * (info->yp - y);
	destance = sqrt(xx + yy);
	return (destance);
}
