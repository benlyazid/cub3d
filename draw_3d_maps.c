/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:55:05 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/03 10:54:34 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)


int	draw_flor_sol(t_all_info *info)
{
	int	i;
	int	j;
	int	index;
	float	float_dest;

	j = 0;
	
	while (j < info->height)
	{
		i = 0;
		while (i < info->width)
		{
			index = (j * info->width) + (int)i; 
			i++;
			if (j < info->height / 2)
				info->data_3d[index] = (int)info->color_coll.value;
			else
				info->data_3d[index] = (int)info->color_flor.value;
		}
		j++;
	}
	return (0);
}

int		draw_3d_image(t_all_info *info, float x, float alpha)
{
	float	destance_to_the_wall;
	float	projection_wall;
	int		start;
	int		z;
	int		index;
	int	 	end;
	float	destance_to_sprite;
	int		get;
	float	get_x, get_y;
	t_d_wall wall_dest;
	int 	x_offsite;
	t_sprite *save;
	int		y0;
	int		color_index;

	info->sprite_struct_all = malloc(sizeof(t_sprite));
	info->sprite_struct_start = info->sprite_struct_all;
	wall_dest = calc_destance_to_wall(info);
	info->x_wall = wall_dest.x_wall;
	info->y_wall = wall_dest.y_wall;

	destance_to_the_wall = wall_dest.destance * cos (alpha * R_P);
	projection_wall = info->dst_player_projection * info->size / destance_to_the_wall;
	start = (int)((info->height - projection_wall) / 2);
	end = (int)((info->height + projection_wall) / 2);
	info->projection_wall = projection_wall;
	if (end > info->height)
		end = info->height;

	z = end - 1;
	x_offsite = get_texteur_value(info, wall_dest.type);
	while (z > -1 && z > start)
	{
		index = (z * info->width) + x; 
		if (index >= 0 && index < (int)info->height * (int)info->width)
		{
			y0 = (z - start) * info->txt_img_size_h / info->projection_wall;
			color_index = ((int)y0 * info->txt_img_size_w) + (int)x_offsite;
			if (x_offsite >= 0 && x_offsite < info->txt_img_size_w && y0 >= 0 && y0 < info->txt_img_size_h)
				info->data_3d[index] = info->txt_img_data[color_index];
		}
		z--;
	}
	if (info->sprite == 1 )
	{
		sort_by_destance(info);
		info->sprite_struct_all = info->sprite_struct_start;
		
		while (info->sprite == 1 && info->sprite_struct_all)
		{
			destance_to_sprite = DEST_2P(info->xp, info->yp, info->sprite_struct_all->x_center, info->sprite_struct_all->y_center);
			info->rayon = destance_to_sprite;
			info->projection_sprite = info->dst_player_projection * info->size / destance_to_sprite;
			start = ((int)info->height - (int)info->projection_sprite) / 2;
			end = (((int)info->height + (int)info->projection_sprite) / 2);
			z = start;
			x_offsite = get_sprite_value(info);
			if (end > info->height)
				end = info->height - 1;
			z = end;
			while (z > -1 && z > start)
			{
				index = ((int)z * (int)info->width) + (int)x; 
				if (index >= 0 && index < (int)info->height * (int)info->width)
					if (wall_dest.destance > info->sprite_struct_all->dest && x_offsite < info->size && x_offsite > -1)
					{
						get_x =  (x_offsite / info->size)  *  info->sprite_w;
						get_y = ((z - start)  / info->projection_sprite) * info->sprite_h;
						get = (int)get_y * info->sprite_w + (int)get_x;
						if (get >-1 && get < (int)info->sprite_h * (int)info->sprite_w && info->data_sprite[get] > 0x000000)
						{
							info->data_3d[index] = info->data_sprite[get];
						}
					}
				z -= 1;
			}
			save = info->sprite_struct_all->next;
			free(info->sprite_struct_all);
			info->sprite_struct_all = save;
		}
		info->sprite_struct_all = info->sprite_struct_start;
	}

	if (info->sprite == 0)
	{
		free(info->sprite_struct_start);
	}
	info->sprite = 0;

	return (0);
}

t_d_wall	calc_destance_to_wall(t_all_info *info)
{
	t_point	xpoint;
	t_point	ypoint;
	float	xd;
	float	yd;
	t_d_wall dest_to_wall;

	xpoint = ray_casting_x(info);
	
	ypoint = ray_casting_y(info);


	
	if(xpoint.x >= 0 && xpoint.y >= 0)
	{
		xd = destance(info, xpoint.x, xpoint.y);
	}
	else
		xd = INT32_MAX;
	if (ypoint.x >= 0 && ypoint.y >= 0)
	{
		yd = destance(info, ypoint.x, ypoint.y);
	}
	else 
		yd = INT32_MAX;

	if (xpoint.x >= 0 && xpoint.y >= 0 && yd >= xd)
	{
		dest_to_wall.destance = xd;
		dest_to_wall.type = 'y';
		dest_to_wall.x_wall =  xpoint.x;
		dest_to_wall.y_wall = xpoint.y;
		return(dest_to_wall);
	}
	else if (ypoint.x >= 0 && ypoint.y >= 0 && xd > yd)
	{	
		dest_to_wall.destance = yd;
		dest_to_wall.type = 'x';
		dest_to_wall.x_wall =  ypoint.x;
		dest_to_wall.y_wall = ypoint.y;
		
		return(dest_to_wall);	
	}
	dest_to_wall.x_wall = 0;
	dest_to_wall.y_wall = 0;
	dest_to_wall.type = 'z';
	dest_to_wall.destance = 0;
	return (dest_to_wall);
}

int				draw_all_image_3d(t_all_info *info)
{
	float save_angle;
	float alpha;
	float	x;
	save_angle = info->angle;
	alpha = -30;
	x = 0;
	info->dst_player_projection = (info->width / 2) / tan (M_PI / 6 );
	draw_flor_sol(info);
	//TIME(
	while (x < info->width)
	{
		info->angle += alpha;
		draw_3d_image(info, x, alpha);
		info->angle = save_angle;
		alpha+= (60 / info->width);
		x+= 1;
	}
	//)
	 info->angle = save_angle;
	return (0);
}
