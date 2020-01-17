/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:55:05 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/01/15 13:53:05 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

int		draw_3d_image(t_all_info *info, int x, float alpha)
{
	float 	wall_h;
	float	destance_to_the_wall;
	float	destance_player_projection;
	float	projection_wall;
	float	bas;
	int	y;

	wall_h = info-> height_size;
	destance_to_the_wall = calc_destance_to_wall(info);
	destance_to_the_wall = destance_to_the_wall * cos (alpha * R_P);
	destance_player_projection = info->width / tan (30 * R_P);
	projection_wall = destance_player_projection * wall_h / destance_to_the_wall;
	if (projection_wall > info->height)
		projection_wall = info->height;
	bas = (info->height - projection_wall) / 2;

	y = 0;
	/*while (y < info->height && y >= 0 && x < info->width && x >= 0)
	{	 
		if (y <= bas && y <= projection_wall + bas)
			info->data[(y * info->width) + x] = 0x6416FAA;
		else if (y >= bas && y <= projection_wall + bas)
			info->data[(y * info->width) + x] = 0xffffff;
		if (y % (int)info->height_size == 0)
			info->data[(y * info->width) + x] = 0xFF0000;
		y++;
	}*/
		x = 0;
	return (0);
}

float	calc_destance_to_wall(t_all_info *info)
{
	float	destance;
	int 	i;
	int 	index;
	int		index_x;
	int		index_y;
	int		x;
	int		y;

	destance = 0;
	i = 0;
		while (1)
		{
				index_x = (int)((info->xp + (i * cos((info->angle) * R_P))) * info->width_number / info->width);
				index_y = (int)((info->yp + (i * sin((info->angle) * R_P))) * info->height_number / info->height);		
				index = (index_y * info->width_number + index_x) * 2;
				x = (int)(info->xp + (cos((info->angle) * R_P) * i));
				y = (int)(info->yp + (sin((info->angle) * R_P) * i));
				
				//ft_putnbr_fd(info->angle, 1);
				//ft_putstr_fd("\n", 1);
				if (info->maps[index] == '1')
					{
						destance = sqrt(((x - info->xp) * (x - info->xp)) + ((y - info->yp) * (y - info->yp)));
						return(destance); 
					}
				i++;
				destance++;
			}
}

int				draw_all_image_3d(t_all_info *info)
{
	float save_angle;
	float alpha;

	save_angle = info->angle;
	 alpha = -30;
	 while (alpha < 30)
	 {
		info->angle += alpha;
		draw_3d_image(info, (int)((alpha + 30) * info->width / 60), alpha);
		info->angle = save_angle;
		alpha+= ((float)60 / info->width);
	 }
	 info->angle = save_angle;
	return (0);
}
/*void remove_3d_image(t_all_info *info)
{
	int x;
	int	y;

	x = 0;
	while (x < info->width)
	{
		y  = 0;
		while (y < info->height)
		{
			info->data[(y * info->width) + x] = 0x0;
			y++;
		}
		x++;
	}
}*/
