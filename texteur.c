/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:31:47 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/02 12:02:36 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int coorect_collor(int index0, int img_w, int img_h, int *data)
{
	int color0;
	int color2;
	int color1;
	int color3;
	int color;
	int index;
	
	color0 = 0;
	color1 = 0;
	color2 = 0;
	color3 = 0;
	if (index0 < img_w * img_h && index0 > 0)
		color0 = data[index0];
	index = index0 + img_w;
	if (index < img_w * img_h && index > 0)
		color1 = data[index];
	index = index0 + 1;
	if (index < img_w * img_h && index > 0)
		color2 = data[index];
	index = index0 - img_w;
	if (index < img_w * img_h && index > 0)
		color3 = data[index];
	color = (color0 + color1 + color2 + color3) / 4;
	return data[index0];
	//return color;
}

int	get_x_value(t_all_info *info, float img_size_w, float img_size_h, int *data)
{
	int	x0;
	int	y0;
	int	index_0;
	
	x0 = (info->x_wall % (int)info->size) * img_size_w / info->size;
	info->txt_img_size_h = img_size_h;
	info->txt_img_size_w = img_size_w;
	info->txt_img_data = data;
	y0 = info->z * img_size_h / info->projection_wall;
	index_0 = ((int)y0 * img_size_w) + (int)x0;
	if (x0 >= 0 && x0 < img_size_w && y0 >= 0 && y0 < img_size_h)
		return (x0);
		//return (data[index_0]);
	return (0);
}

int	get_y_value(t_all_info *info, float img_size_w, float img_size_h, int *data)
{
	int	x0;
	int	y0;
	int	index_0;

	info->txt_img_size_h = img_size_h;
	info->txt_img_size_w = img_size_w;
	info->txt_img_data = data;
	x0 = (info->y_wall % (int)info->size) * img_size_w / info->size;
	y0 = info->z * img_size_h / info->projection_wall;
	index_0 = ((int)y0 * img_size_w) + (int)x0;
	if (x0 >= 0 && x0 < img_size_w && y0 >= 0 && y0 < img_size_h)
		return (x0);
	//return (data[index_0]);

	return (0);
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

int	get_flor_texteur(t_all_info *info)
{
	float angle;
	int	x0;
	int	y0;
	int	index_0;

	angle = info->angle;
	if (angle < 0)
		angle = 360 + angle;
	x0 = ((int)info->xp % (int)info->size) * info->img_wno / info->size;
	return (x0);
}