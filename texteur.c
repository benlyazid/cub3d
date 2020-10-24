/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:31:47 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/24 10:53:24 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_x_value(t_all_info *info, double img_size_w, double img_size_h, int *data)
{
	double	x0;
	double	y0;
	int		index_0;

	x0 = (info->x_wall % (int)info->size) * img_size_w / info->size;
	y0 = info->z * img_size_h / info->projection_wall;
	index_0 = ((int)y0 * img_size_w) + (int)x0;
	if (x0 >= 0 && x0 < img_size_w && y0 >= 0 && y0 < img_size_h)
		return (data[index_0]);
	return (0);
}

int	get_y_value(t_all_info *info, double img_size_w, double img_size_h, int *data)
{
	double	x0;
	double	y0;
	int		index_0;

	x0 = (info->y_wall % (int)info->size) * img_size_w / info->size;
	y0 = info->z * img_size_h / info->projection_wall;
	index_0 = ((int)y0 * img_size_w) + (int)x0;
	if (x0 >= 0 && x0 < img_size_w && y0 >= 0 && y0 < img_size_h)
		return (data[index_0]);
	return (0);
}

int	get_texteur_value(t_all_info *info, int z, int type)
{
	double	x0;
	double	y0;
	int		index_0;
	double	angle;

	info->z = z;
	angle = info->angle;
	if (angle < 0)
		angle = 360 + angle;
	if (type == 'x')
	{
		if (angle < 360 && angle >= 180)
			return (get_x_value(info, info->img_wno, info->img_hno,
			info->data_texteur_no));
		else
			return (get_x_value(info, info->img_wso, info->img_hso,
			info->data_texteur_so));
	}
	else if (type == 'y')
	{
		if (angle > 90 && angle < 270)
			return (get_y_value(info, info->img_wwe, info->img_hwe,
			info->data_texteur_we));
	}
	return (get_y_value(info, info->img_wea, info->img_hea,
	info->data_texteur_ea));
}
