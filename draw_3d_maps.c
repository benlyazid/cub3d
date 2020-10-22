/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:55:05 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/22 18:21:06 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

int		draw_3d_image(t_all_info *info, double x, double alpha)
{
	double	destance_to_the_wall;
	double	destance_player_projection;
	double	projection_wall;
	int		start;
	int		z;
	int		index;
	int		c;
	int	 end;
	double	destance_to_sprite;
	int 	sprite_start, sprite_end, z_sprite;
	int		get;
	double	angle_sprite_player;
	int		index_sprite;
	double	index_f;
	t_d_wall wall_dest;
	int x_offsite;
	t_sprite *save;
	index = 0;


	info->sprite_struct_all = malloc(sizeof(t_sprite));
	info->sprite_struct_start = info->sprite_struct_all;

	wall_dest = calc_destance_to_wall(info);
	info->x_wall = wall_dest.x_wall;
	info->y_wall = wall_dest.y_wall;

	destance_to_the_wall = wall_dest.destance * cos (alpha * R_P);
	destance_player_projection = (info->width / 2) / tan (M_PI / 6 ); // /2

	if(wall_dest.type != 'z')
		projection_wall = destance_player_projection * info->size / destance_to_the_wall;


	///////////
	else
	{
		projection_wall = 0;
		wall_dest.type = 'y';	
	}
	

	/////////////////
	start = (int)((info->height - projection_wall) / 2);
	end = (int)((info->height + projection_wall) / 2);


	z_sprite = sprite_start;

	z = 0;
	c = 0;
	while (z < start)
	{
		index = ((z * (int)info->width) + (int)x);
		//if ( index >= 0 && index < info->width * info->height)
			//info->data_3d[index] = 0x02aaaa; //sky
			info->data_3d[index] = (int)info->color_coll.value;
		z++;
	}

	z = start;
	while (z < (int)end)
	{

		index = (z * (int)info->width) + (int)x; 
		if (index >= 0 && index < (int)info->height * (int)info->width)
		{
			info->projection_wall = projection_wall;
			info->data_3d[index] = get_texteur_value(info, c, wall_dest.type);

		}

		c++;
		z++;
		
	 }
		
	z = end;
	while(z < (int)info->height)
	{
		index = ((z * (int)info->width) + (int)x);
		if ( index >= 0 && index < info->width * info->height)
			//info->data_3d[index] = 53; //floor 
			info->data_3d[index] = (int)info->color_flor.value;
		z++;
	}

	if (info->sprite == 1 )
	{	
		sort_by_destance(info);
		info->sprite_struct_all = info->sprite_struct_start;
	}

	while (info->sprite == 1 && info->sprite_struct_all)
	{
		destance_to_sprite = destance_2_points(info->xp, info->yp, info->sprite_struct_all->x_center, info->sprite_struct_all->y_center);
		
		info->projection_sprite = destance_player_projection * info->size / destance_to_sprite;
		sprite_start = ((int)info->height - (int)info->projection_sprite) / 2;
		sprite_end = (((int)info->height + (int)info->projection_sprite) / 2);
		z_sprite = sprite_start;
		while (z_sprite < sprite_end)
		{ 
			index = ((int)z_sprite * (int)info->width) + (int)x; 
			if (index >= 0 && index < (int)info->height * (int)info->width)
				if (wall_dest.destance > info->sprite_struct_all->dest)
					x_offsite = get_sprite_value(info, (z_sprite - sprite_start), index, wall_dest.type, x);
			z_sprite+=1;
		}
		
		save = info->sprite_struct_all->next;
		free(info->sprite_struct_all);
		info->sprite_struct_all = save;
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
	double	xd;
	double	yd;
	t_d_wall dest_to_wall;

	xpoint = ray_casting_x(info);

	
	/*while(info->tst > 0)
	{
		//printf("leaks test0\n");
	}*/
	
	ypoint = ray_casting_y(info);


	
	if(xpoint.x >= 0 && xpoint.y >= 0)
		xd = destance(info, xpoint.x, xpoint.y);
	else
		xd = INT32_MAX;
	if (ypoint.x >= 0 && ypoint.y >= 0)
		yd = destance(info, ypoint.x, ypoint.y);
	else 
		yd = INT32_MAX;



	if (xpoint.x >= 0 && xpoint.y >= 0 && yd >= xd)
	{
		dest_to_wall.destance = xd;
		dest_to_wall.type = 'y'; //? x
		dest_to_wall.x_wall =  xpoint.x;
		dest_to_wall.y_wall = xpoint.y;
		return(dest_to_wall);
	}
	else if (ypoint.x >= 0 && ypoint.y >= 0 && xd > yd)
	{	
		dest_to_wall.destance = yd;
		dest_to_wall.type = 'x';//? y
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
	double save_angle;
	double alpha;
	double	x;
	save_angle = info->angle;
	alpha = -30;
	x = 0;

	
	while (x < info->width)
	{
		info->tst = x;
		info->angle += alpha;
		draw_3d_image(info, x, alpha);
		info->angle = save_angle;
		alpha+= (60 / info->width);
		x+= 1;
	}
	printf("finish\n\n\n\n");
	 info->angle = save_angle;
	return (0);
}
