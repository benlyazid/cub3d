/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maps2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:54:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/24 11:20:25 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int get_player_info(t_all_info *info)
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
			if ((int)info->xp == 0 && (int)info->yp == 0)
			{
				if (info->maps[i] == 'N')
					info->angle = 270;
				if (info->maps[i] == 'S')
					info->angle = 90;
				if (info->maps[i] == 'E')
					info->angle = 360;
				if (info->maps[i] == 'W')
					info->angle = 180;
				info->vision = info->maps[i];
				info->xp = x + (info->size / 2);
				info->yp = y + (info->size / 2);
			}
		}
		if (info->maps[i] == '\n')
			{
				x = 0;
				y += info->size;
			}
		if (info->maps[i] != ' ' && info->maps[i] != '\n')
				x+= info->size;
		i++;
	}
	return (0);
}

int get_type_from_maps(double x, double y, t_all_info *info)
{
	int	index;
	int	index_x;
	int	index_y;
	index_x = x / info->size;
	index_y = y / info->size;
	index = (int)index_y * (int)info->width_number + (int)index_x;

	
	
	if (index < (int)info->width_number * (int)info->height_number)
		return(info->mp[(int)index]);
	return 0;
}

int	draw_2d_maps(t_all_info *info)
{
	rm_all(info);	
	info->save_angle =  info->angle;
	draw_all_image_3d(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_3d, 0, 0);
	return (0);
}

int	rm_all(t_all_info *info)
{
	int i;
	i = 0;
	while(i < (int)info->height * (int)info->width)
	{
			info->data_3d[i] = 0;
			i++;
	}
	return (0);

}

