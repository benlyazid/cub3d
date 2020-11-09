/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:33:54 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/09 13:21:44 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_d_wall	initial_wall(char c, float dst, t_point point, t_all_info *info)
{
	t_d_wall	wall;

	if (c == 'z')
	{
		wall.x_wall = info->x_wall;
		wall.y_wall = info->y_wall;
		wall.destance = 0;
		wall.type = c;
	}
	else
	{
		wall.destance = dst;
		wall.x_wall = point.x;
		wall.y_wall = point.y;
		wall.type = c;
	}
	return (wall);
}

t_d_wall	calc_destance_to_wall(t_all_info *info)
{
	t_point		xpoint;
	t_point		ypoint;
	float		xd;
	float		yd;
	t_d_wall	dest_to_wall;

	xpoint = ray_casting_x(info);
	ypoint = ray_casting_y(info);
	if (xpoint.x >= 0 && xpoint.y >= 0)
		xd = destance(info, xpoint.x, xpoint.y);
	else
		xd = INT32_MAX;
	if (ypoint.x >= 0 && ypoint.y >= 0)
		yd = destance(info, ypoint.x, ypoint.y);
	else
		yd = INT32_MAX;
	if (xpoint.x >= 0 && xpoint.y >= 0 && yd >= xd)
		dest_to_wall = initial_wall('y', xd, xpoint, info);
	else if (ypoint.x >= 0 && ypoint.y >= 0 && xd > yd)
		dest_to_wall = initial_wall('x', yd, ypoint, info);
	else
		dest_to_wall = info->wall_dest;
	return (dest_to_wall);
}

int			draw_all_image_3d(t_all_info *info)
{
	float	save_angle;
	float	alpha;
	float	x;

	save_angle = info->angle;
	alpha = -30;
	x = 0;
	info->dst_player_projection = (info->width / 2) / tan(M_PI / 6);
	draw_flor_sol(info);
	while (x < info->width)
	{
		info->angle += alpha;
		draw_3d_image(info, x, alpha);
		info->angle = save_angle;
		alpha += (60 / info->width);
		x += 1;
	}
	info->angle = save_angle;
	return (0);
}

int			draw_flor_sol(t_all_info *info)
{
	int		i;
	int		j;
	int		index;
	float	float_dest;

	j = 0;
	while (j < info->height)
	{
		i = 0;
		while (i < info->width)
		{
			index = (j * info->width) + (int)i;
			i++;
			if (j < info->height / 2)
				info->data_3d[index] = (int)info->clr_c.value;
			else
				info->data_3d[index] = (int)info->clr_f.value;
		}
		j++;
	}
	return (0);
}
