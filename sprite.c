/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:39:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/03 09:04:18 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define R_P ( M_PI / 180)


int get_sprite_from_file(t_all_info *info)
{
	int i;
	int j;
	int k;
	char *path;

	path = NULL;
	i = 0;
	while(info->file[i])
	{
		if(info->file[i] == 'S' && info->file[i + 1] != 'O' && ( i == 0 || info->file[i - 1] == '\n'))
		{
			i++;
			if (info->file[i] != ' ')
				return -1;
			while(info->file[i] == ' ')
				i++;
			j = i;
			while(info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			break;
		}
		i++;
	}
	i  = open(path, O_WRONLY);
	if (path == NULL || i == -1)	
		return -1;
	close(i);
	info->sprite_img = mlx_xpm_file_to_image(info->mlx_ptr, path, (int*)&j, (int*)&i);
	info->sprite_h = i;
	info->sprite_w = j;
	info->data_sprite = (int*)mlx_get_data_addr(info->sprite_img, &i, &j, &k);
	free(path);
	free(info->sprite_img);
	return 1;
}

float	get_sprite_value(t_all_info *info)
{
	float	x;
	float	y;
	float	x_offsite;
	float	xc;
	float	yc;
	float	angle_center, angle_ray, x_angle;

	yc = info->sprite_struct_all->y_center;
	xc = info->sprite_struct_all->x_center;
	x = (cos(info->angle * R_P) * info->rayon) + info->xp;
	y = (sin(info->angle * R_P) * info->rayon) + info->yp;
	x_offsite = DEST_2P(x, y, xc, yc);
	//angle_center is 180 =  angle + x
	if (info->yp > yc)
		angle_center = -acos((xc - info->xp) / info->rayon) * 180 / M_PI;
	else
		angle_center = acos((xc - info->xp) / info->rayon) * 180 / M_PI;

	x_angle = 180 - angle_center;
	angle_ray = x_angle + info->angle;
	if (angle_ray < 0)
		angle_ray = 360 + angle_ray;
	if (angle_ray > 360)
		angle_ray -= 360;
	if (angle_ray > 180)
		x_offsite += (info->size / 2);
	else
		x_offsite = (info->size / 2) - x_offsite;
	
	
	return (x_offsite);
}
