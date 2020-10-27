/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:23:21 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/27 11:16:07 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_d_wall	initiall_data(t_point point, char type, double dst)
{
	t_d_wall	wall;

	wall.destance = dst;
	wall.type = type;
	wall.x_wall = point.x;
	wall.y_wall = point.y;
	return (wall);
}

t_d_wall	calc_destance_to_wall(t_all_info *info)
{
	t_point		xp;
	t_point		yp;
	double		xd;
	double		yd;
	t_d_wall	dest_to_wall;

	xp = ray_casting_x(info);
	yp = ray_casting_y(info);
	xd = (xp.x >= 0 && xp.y >= 0) ? destance(info, xp.x, xp.y) : 2147483647;
	yd = (yp.x >= 0 && yp.y >= 0) ? destance(info, yp.x, yp.y) : 2147483647;
	if (xp.x >= 0 && xp.y >= 0 && yd >= xd)
	{
		dest_to_wall = initiall_data(xp, 'y', xd);
		return (dest_to_wall);
	}
	else if (yp.x >= 0 && yp.y >= 0 && xd > yd)
	{
		dest_to_wall = initiall_data(yp, 'x', yd);
		return (dest_to_wall);
	}
	dest_to_wall.x_wall = 0;
	dest_to_wall.y_wall = 0;
	dest_to_wall.type = 'z';
	dest_to_wall.destance = 0;
	return (dest_to_wall);
}
