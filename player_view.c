/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:18:26 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 11:49:31 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

t_point	ray_casting_x(t_all_info *info)
{
	double		x;
	double		y;
	t_point		point;
	int			moins;

	info->sprite = 0;
	info->xa = (cos(info->angle * R_P) > 0) ? info->size : -1 * info->size;
	info->ya = info->xa * tan(info->angle * R_P);
	x = (int)((int)(info->xp / info->size) * (int)(info->size));
	x = (cos(info->angle * R_P) > 0) ? x + info->size : x;
	moins = !(cos(info->angle * R_P) > 0) ? 1 : 0;
	y = (info->yp + (x - info->xp) * tan(info->angle * R_P));
	while (x >= 0 && y >= 0 && x < info->width_number * info->size && y
	< info->height_number * info->size)
	{
		if (get_type_from_maps(x - moins, y, info) == 1)
			return (execute_casting_x(info, moins, x, y));
		execute_casting_x(info, moins, x, y);
		x += info->xa;
		y += info->ya;
	}
	point.x = -1;
	point.y = -1;
	return (point);
}

t_point	ray_casting_y(t_all_info *info)
{
	double		x;
	double		y;
	t_point		point;
	int			moins;

	moins = 0;
	y = (int)((int)info->yp / (int)info->size) * ((int)info->size);
	y = (sin(info->angle * R_P) > 0) ? y + info->size : y;
	moins = (sin(info->angle * R_P) > 0) ? 0 : 1;
	x = info->xp + ((y - info->yp) / tan(info->angle * R_P));
	info->ya = (sin(info->angle * R_P) > 0) ? info->size : -info->size;
	info->xa = (sin(info->angle * R_P) == 1 || sin(info->angle * R_P) == -1) ?
	0 : info->ya / tan(info->angle * R_P);
	while (x >= 0.0 && y >= 0.0 && x < info->width_number * info->size && y <
	info->height_number * info->size)
	{
		if (get_type_from_maps(x, y - moins, info) == 1)
			return (execute_casting_y(info, moins, x, y));
		execute_casting_y(info, moins, x, y);
		x += info->xa;
		y += info->ya;
	}
	point.x = -1;
	point.y = -1;
	return (point);
}

double	destance(t_all_info *info, int x, int y)
{
	double	destance;
	double	xx;
	double	yy;

	xx = (info->xp - x) * (info->xp - x);
	yy = (info->yp - y) * (info->yp - y);
	destance = sqrt(xx + yy);
	return (destance);
}
