/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maps2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:54:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/01/16 12:16:25 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
int	draw_2d_maps(t_all_info *info)
{
	int x;
	int	y;
	int i;
	int index;

	i = 0;
	x = 0;
	y = 0;
	while (info->maps[i])
	{
		if (ft_isalpha(info->maps[i]))
			{
				if (info->xp == 0 && info->yp == 0)
				{
					if (info->maps[i] == 'W')
						info->angle =  90;
					info->vision = info->maps[i];
					info->xp = x + (info->width_size / 2);
					info->yp = y + (info->height_size / 2);
				}
			}
		if (info->maps[i] == '\n')
			{
				x = 0;
				y += info->height_size;
			}
		if (info->maps[i] != ' ' && info->maps[i] != '\n')
			x += info->width_size;	
		i++;
	}
	draw_image_surface(info);
	draw_image_player(info);
	//draw_image_view_angle(info);
	//draw_image_view(info);
	//draw_all_image_3d(info);
	index = 0;
//////////////////////////////////////////////////////////////////////////////
/*y = 0;
x = 0;

while (info->height > y)
	{
		x = 0;
		while (info->width > x)
		{
			index = (y * info->width) + x;
			if (y % (int)info->height_size == 0)
				info->data[index] = 0xF11000;
			if (x % (int)info->width_size == 0)
				info->data[index] = 0xF11000;
			x++;
		}
		y++;
	}*/
////////////////////////////////////////////////////////////////////////////
	ray_casting(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img, 0, 0);
	return (0);
}

int	draw_image_surface(t_all_info *info)
{
	int x;
	int	y;
	int index;
	int	index_x;
	int	index_y;
	int index_data;
	y = 0;	
	while (info->height > y)
	{
		x = 0;
		while (info->width > x)
		{
			index_data = (y * info->width) + x;
			index_x = x * info->width_number / info->width;
			index_y = y * info->height_number / info->height;
			index = (index_y * info->width_number) + index_x; 
			if (info->mp[index] == 1)
				info->data[index_data] = 0xFFFFFF;	
			x++;
		}
		y++;
	}
	return (0);
}



