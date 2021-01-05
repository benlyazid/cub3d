/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:39:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/01/05 09:08:50 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define R_P ( M_PI / 180)

float	config_angle(t_all_info *info)
{
	float	angle_center;
	float	x_angle;
	float	angle_ray;
	
	// Calcule the Angle between the center of the sprite and the array
	if (info->yp > info->sprt_strct_all->y_center)
		angle_center = -acos((info->sprt_strct_all->x_center - info->xp)
		/ info->rayon) * 180 / M_PI;
	else
		angle_center = acos((info->sprt_strct_all->x_center - info->xp)
		/ info->rayon) * 180 / M_PI;
	// transform all angle to 180
	x_angle = 180 - angle_center;
	angle_ray = x_angle + info->angle;
	// keep the angle between 0 and 360
	if (angle_ray < 0)
		angle_ray = 360 + angle_ray;
	if (angle_ray > 360)
		angle_ray -= 360;
	return (angle_ray);
}

char	*get_sprite_path(t_all_info *info)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	path = NULL;
	while (info->file[i])
	{
		if (info->file[i] == 'S' && info->file[i + 1] != 'O' &&
		(i == 0 || info->file[i - 1] == '\n'))
		{
			i++;
			if (info->file[i] != ' ')
				return (path);
			while (info->file[i] == ' ')
				i++;
			j = i;
			while (info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			break ;
		}
		i++;
	}
	return (path);
}

int		get_sprite_from_file(t_all_info *info)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	path = NULL;
	i = 0;
	path = get_sprite_path(info);
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)
		return (-1);
	close(i);
	info->sprite_img = mlx_xpm_file_to_image(info->mlx_ptr, path,
	(int*)&j, (int*)&i);
	info->sprt_h = i;
	info->sprt_w = j;
	info->data_sprite = (int*)mlx_get_data_addr(info->sprite_img, &i, &j, &k);
	if (check_xpm_ext(path) == -1)
		return (-1);
	free(path);
	free(info->sprite_img);
	return (1);
}

float	get_sprite_value(t_all_info *info)
{
	float	x;
	float	y;
	float	x_offsite;
	float	angle_ray;

	x = (cos(info->angle * R_P) * info->rayon) + info->xp;
	y = (sin(info->angle * R_P) * info->rayon) + info->yp;
	x_offsite = DEST_2P(x, y, info->sprt_strct_all->x_center,
	info->sprt_strct_all->y_center);
	angle_ray = config_angle(info);
	if (angle_ray > 180)
		x_offsite += (info->size / 2);
	else
		x_offsite = (info->size / 2) - x_offsite;
	return (x_offsite);
}
