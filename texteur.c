/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:31:47 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/04 09:50:44 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_x_value(t_all_info *info, float img_size_w, float img_size_h, int *data)
{
	float	x0;
	float	y0;
	int		index_0;

	x0 = (info->x_wall % (int)info->size) * img_size_w / info->size;
	x0 = (info->x_wall % (int)info->size) * img_size_w / info->size;
	info->txt_h = img_size_h;
	info->txt_w = img_size_w;
	info->txt_img_data = data;
	return (x0);
}

int	get_y_value(t_all_info *info, float img_size_w, float img_size_h, int *data)
{
	int	x0;
	int	y0;
	int	index_0;

	info->txt_h = img_size_h;
	info->txt_w = img_size_w;
	info->txt_img_data = data;
	x0 = (info->y_wall % (int)info->size) * img_size_w / info->size;
	return (x0);
}

int	get_texteur_value(t_all_info *info, int type)
{
	float	angle;

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
