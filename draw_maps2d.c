/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maps2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:54:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/03 11:18:43 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	char_to_angle(char c, t_all_info *info)
{
	if (c == 'N')
		info->angle = 270;
	if (c == 'S')
		info->angle = 90;
	if (c == 'E')
		info->angle = 360;
	if (c == 'W')
		info->angle = 180;
}

int		get_player_info(t_all_info *info)
{
	int x;
	int	y;
	int i;

	i = -1;
	x = 0;
	y = 0;
	while (info->maps[++i])
	{
		if (ft_isalpha(info->maps[i]))
			if ((int)info->xp == 0 && (int)info->yp == 0)
			{
				char_to_angle(info->maps[i], info);
				info->xp = x + (info->size / 2);
				info->yp = y + (info->size / 2);
			}
		if (info->maps[i] == '\n')
		{
			x = 0;
			y += info->size;
		}
		if (info->maps[i] != ' ' && info->maps[i] != '\n')
			x += info->size;
	}
	return (0);
}

int		get_type_from_maps(float x, float y, t_all_info *info)
{
	int	index;
	int	index_x;
	int	index_y;

	index_x = x / info->size;
	index_y = y / info->size;
	index = (int)index_y * (int)info->width_number + (int)index_x;
	if (index < (int)info->width_number * (int)info->height_number)
		return (info->mp[(int)index]);
	return (0);
}

int		draw_2d_maps(t_all_info *info)
{
	info->save_angle = info->angle;
	draw_all_image_3d(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_3d, 0, 0);
	return (0);
}
