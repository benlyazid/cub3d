/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:39:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/24 18:25:35 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define R_P ( M_PI / 180)

int	get_sprite_value(t_all_info *info, double z_sprite,  int index, int  type, double x)
{
	int 	i;
	double	x_offsite;
	int		get_x;
	int		get_y;
	int		get;
	double	get_x_f, get_y_f;

	double xp, yp, xs, ys, xv, yv, xx, yy;
	double tst_x;

	xp = info->xp;
	yp = info->yp;
	xs = info->sprite_struct_all->x_center;
	ys = info->sprite_struct_all->y_center;
	xx = info->sprite_struct_all->x;
	yy = info->sprite_struct_all->y;
	t_point begin, end, test_begin;

	t_eq_line player_sprite = find_equation_of_line(xp, yp, xx, yy);


	t_eq_line player_sprite_center = find_equation_of_line(xp, yp, xs, ys);

	t_eq_line sprite_center;
	if (player_sprite_center.m != 0)
	{
		sprite_center.is_perpendicular = 0;
		sprite_center.m = -1 / player_sprite_center.m;
		sprite_center.b = ys - (xs * sprite_center.m);

	}
	else
	{
		sprite_center.is_perpendicular = 1;
		sprite_center.m = 0;
		sprite_center.b = ys;
	}

	if (player_sprite.m == 0)
	{
		player_sprite.is_perpendicular = 1;
		player_sprite.m = 0;
		player_sprite.b = ys;
	}
	xv = entersection_two_line(sprite_center, player_sprite, info).x;
	yv = entersection_two_line(sprite_center, player_sprite, info).y;
	if (player_sprite.m == 0)
	{		
		xv = info->old_point.x;
		yv = info->old_point.y;
	}	
begin = enter_line_circle(info, xs, ys, info->size / 2, sprite_center);
	t_eq_line player_view;
	x_offsite = destance_2_points(begin.x, begin.y, xv, yv);
	if ((int)info->old_debug  == -1)
		info->old_debug = x_offsite;	
	get_x_f =  (x_offsite / info->size)  *  info->sprite_w;
	get_y_f = (z_sprite  / info->projection_sprite) * info->sprite_h;
	get = (int)get_y_f * info->sprite_w + (int)get_x_f;
	if ((int)info->old_debug != (int)x_offsite)
	{
		//printf("XOFFSITE %f, view %f %f  PLAYER %f, %f  Sprite %f %f : Xis %f \n", x_offsite, xv, yv, xp, yp, xs, ys, info->sprite_struct_all->x);

		info->old_debug = x_offsite;
	}
	if (destance_2_points(xs, ys, xv, yv) < info->size / 2 && x_offsite < info->size && get >= 0 && get < (int)info->sprite_h * (int)info->sprite_w)
	{	
		info->test =  1;
		info->old_point.x = xv;
		info->old_point.y = yv;
		// if ((int)info->old_debug != (int)x_offsite)
		// 	{
		// 		printf("XOFFSITE %f, view %f %f  PLAYER %f, %f  Sprite %f %f :player_is %d spr_is%d \n", x_offsite, xv, yv, xp, yp, xs, ys, player_sprite.is_perpendicular, sprite_center.is_perpendicular);

		// 		info->old_debug = x_offsite;
		// 	}
		if (x_offsite > 0.0 && x_offsite < info->size)
		{
			if (info->data_sprite[get] > 0x000000 )
			{
				info->data_3d[index] =info->data_sprite[get];	
			}
			return(x_offsite);
		}		
	}


		return (x_offsite);
}

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