/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:18:26 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/24 11:16:02 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

#define R_P ( M_PI / 180)


		
t_point	ray_casting_x(t_all_info *info)
{
	double	x;
	double	y;
	double	xa;
	double 	ya;
	int		index_x;
	int		index_y;
	int		index;
	t_point	point;
	int		divs;
	int		moins;
	double index_x_f, index_y_f;
	int sprite_center_x, sprite_center_y;
	t_sprite *sprite_data;
	int type;

	moins = 0;
	
	info->sprite = 0;
	divs = info->xp / info->size;
	divs *= info->size;
	x = divs;
	t_sprite *save;
	if (cos(info->angle * R_P) > 0)
		x += info->size;
	else
		moins = 1;
	y = info->yp + (x - info->xp) * tan(info->angle * R_P);
	if (cos(info->angle * R_P) > 0)
		xa = info->size;
	else
		xa = -1 * info->size;
	ya = xa * tan(info->angle * R_P);
	while (x >= 0.0 && y >= 0.0 && x < info->width_number * info->size && y < info->height_number * info->size)
	{
		type  = get_type_from_maps(x - moins, y, info);
		if (type == 1 || type == 2)
		{
			if (type == 1)
			{
				point.x = x - moins;
				point.y = y;

				return(point);
			}

			if (type == 2)
			{	
					
					sprite_center_x = ((int)x - moins) / (int)info->size;
					sprite_center_x *= (int)info->size;
					sprite_center_x += ((int)info->size / 2);

					sprite_center_y = (int)y / info->size;
					sprite_center_y *= (int)info->size;
					sprite_center_y += ((int)info->size / 2);

					if (info->sprite == 0)
				{
					info->sprite_struct_all->x_center = sprite_center_x;
					info->sprite_struct_all->y_center =  sprite_center_y;
					info->sprite_struct_all->visible = 'x';
					info->sprite_struct_all->x = x;
					info->sprite_struct_all->y = y;
					info->sprite_struct_all->dest = destance_2_points(info->xp, info->yp, x - moins, y);
					info->sprite_struct_all->next = NULL;
				}
				else
				{
					sprite_data = (t_sprite*)malloc(sizeof(t_sprite));
					sprite_data->x_center = sprite_center_x;
					sprite_data->y_center =  sprite_center_y;	
					sprite_data->visible = 'x';
					sprite_data->x = x;
					sprite_data->y = y;
					sprite_data->dest = destance_2_points(info->xp, info->yp, x - moins, y);
					sprite_data->next = NULL;		
					add_to_last(info->sprite_struct_all, sprite_data);
				}
				
				info->sprite = 1;

			}

		}
		x+= xa;
		y+= ya;

	}
	point.x = -1;
	point.y = -1;	

	return (point);
}

t_point	ray_casting_y(t_all_info *info)
{
	double		x;
	double		y;
	double		xa;
	double 		ya;
	t_point		point;
	int			divs;
	int			moins;
	int			index_x;
	int			index_y;
	int 		index;
	int		sprite_center_x;
	int		sprite_center_y;
	t_sprite 	*sprite_data;
	int		type;
	moins = 0;
	divs = (int)info->yp / (int)info->size;
	divs *= (int)info->size; 
	y = divs;

	if (sin(info->angle * R_P) > 0)
		y += info->size;
	else
		moins = 1;
	x = info->xp + ((y - info->yp) / tan(info->angle * R_P));

	if (sin(info->angle * R_P) > 0)
		ya = info->size;
	else
		ya = -1 * info->size;
		if (sin(info->angle * R_P) == 1 || sin(info->angle * R_P) == -1)
			xa = 0;
		else 
			xa = ya / tan(info->angle * R_P);

	while (x >= 0.0 && y >= 0.0 && x < info->width_number * info->size && y < info->height_number * info->size)
	 { 

		type  = get_type_from_maps(x, y - moins, info);

		if (type == 1 || type == 2)
		{
			if (type == 1)
			{
				point.x = x;
				point.y = y - moins;

				return (point);
			}
			if (type == 2)
			{
					sprite_center_x = ((int)x) / (int)info->size;
					sprite_center_x *= (int)info->size;
					sprite_center_x += ((int)info->size / 2);
					sprite_center_y = (int)(y - moins) / info->size;
					sprite_center_y *= (int)info->size;
					sprite_center_y += ((int)info->size / 2);

				if (info->sprite== 0)
				{
	
					info->sprite_struct_all->x_center = sprite_center_x;
					info->sprite_struct_all->y_center = sprite_center_y;
					info->sprite_struct_all->visible = 'y';
					info->sprite_struct_all->x = x;
					info->sprite_struct_all->y = y;
					info->sprite_struct_all->next = NULL;
					info->sprite_struct_all->dest = destance_2_points(info->xp, info->yp, x, y - moins);
					
				
				}
				else
				{
					sprite_data = (t_sprite*)malloc(sizeof(t_sprite));
					sprite_data->x_center = sprite_center_x;
					sprite_data->y_center = sprite_center_y;
					sprite_data->visible = 'y';
					sprite_data->x = x;
					sprite_data->y = y;
					sprite_data->dest = destance_2_points(info->xp, info->yp, x, y - moins);
					sprite_data->next = NULL;	
					add_to_last(info->sprite_struct_all, sprite_data);	
				
				}

					info->sprite = 1;			
			}
		}
		x += xa;
		y += ya;
		
	}

	point.x = -1;
	point.y = -1;
	return (point);
}

double			destance(t_all_info *info, int x, int y)
{	
	double	destance;
	double	xx;
	double	yy;
	
	xx = (info->xp - x) * (info->xp - x);
	yy = (info->yp - y) * (info->yp - y);
	destance = sqrt(xx + yy);
	return (destance);
}