/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:39:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/20 18:43:39 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define R_P ( M_PI / 180)

int	get_sprite_value(t_all_info *info, float z_sprite,  int index, int  type, float x)
{
	int 	i;
	float	angle_player_center;
	float	angle_player_ray;
	float	angle_rotation;
	float	angle_result;
	float	intersection_x;
	float	intersection_y;
	float	point_start_x;
	float	point_start_y;
	float	start_x;
	float	start_y;
	float	x_offsite;
	int		get_x;
	int		get_y;
	int		get;
	float	get_x_f, get_y_f;

float xp, yp, xs, ys, xv, yv, xx, yy;
float teta, angle;
float tst_x;

xp = info->xp;
yp = info->yp;
xs = info->sprite_struct_all->x_center;
ys = info->sprite_struct_all->y_center;
angle = info->save_angle - info->angle;
xx = info->sprite_struct_all->x;
yy = info->sprite_struct_all->y;
t_point begin, end, test_begin;

//player ray
t_equation_of_line player_sprite = find_equation_of_line(xp, yp, xx, yy);

//sprite center player 

t_equation_of_line player_sprite_center = find_equation_of_line(xp, yp, xs, ys);

// sprite center equation
t_equation_of_line sprite_center;
sprite_center.m = -1 / player_sprite_center.m;
sprite_center.b = ys - (xs * sprite_center.m);


//printf("plyer sprite  EQ %f 	%f \n", player_sprite.m, player_sprite.b);

//printf("sprite EQ %f 	%f \n", sprite_center.m, sprite_center.b);
//entersection new of ray view
//xv = xs * cosf(angle * R_P) - (ys * sinf(angle * R_P));
//yv = xs * sinf(angle * R_P) + (ys * cosf(angle * R_P));

xv = find_entersection_point_of_two_line(sprite_center, player_sprite, info).x;
yv = find_entersection_point_of_two_line(sprite_center, player_sprite, info).y;
// begin point 
//try to chose the small one 

//intersection cercl and line 
test_begin = find_entersection_point_ofline_and_circle(info, xs, ys, info->size / 2, sprite_center);

begin.x = xs + (info->size / 2) * sqrtf(1 / (1 + powf(sprite_center.m, 2)));
if (begin.x > xs - (info->size / 2) * sqrtf(1 / (1 + powf(sprite_center.m, 2))))
	begin.x =  xs - (info->size / 2) * sqrtf(1 / (1 + powf(sprite_center.m, 2)));
begin.y = begin.x * sprite_center.m + sprite_center.b;

tst_x = destance_2_points(begin.x, begin.y, xv, yv);
// player view ray
t_equation_of_line player_view;

//end point 
if (xs > begin.x)
	end.x = begin.x - (xs - begin.x);
else
	end.x = xs - (begin.x - xs);
if (ys > begin.y)
	end.y = begin.y - (ys - begin.y);
else
	end.y = ys - (begin.y - ys);

begin.x = test_begin.x;
begin.y = test_begin.y;
	//printf("center   is  %f +  %f\n", xs, ys);
	//printf("casting  is  %f +  %f  %f\n", xv, yv, angle);
	//printf("test : %f\n", tst_x);

	//x_offsite = (info->size / 2) - destance_2_points(info->sprite_struct_all->x_center, info->sprite_struct_all->y_center, cos((info->angle) * R_P) * destance_2_points(info->xp, info->yp, info->sprite_struct_all->x_center , info->sprite_struct_all->y_center) + info->xp, sin((info->angle) * R_P) *  destance_2_points(info->xp, info->yp, info->sprite_struct_all->x_center, info->sprite_struct_all->y_center) + info->yp);
	x_offsite = tst_x;
	get_x_f =  x_offsite / info->size *  info->sprite_w;
	get_y_f = (z_sprite  / info->projection_sprite) * info->sprite_h;
	get = (int)get_y_f * (int)info->sprite_w + (int)get_x_f;
	if ( destance_2_points(xs, ys, xv, yv) <= info->size / 2 && x_offsite < info->size && get >= 0 && get < (int)info->sprite_h * (int)info->sprite_w)
		{	
			//printf("all dest is %f\n", destance_2_points(begin.x, begin.y, end.x, end.y));
			//printf("begin  is  %f +  %f dest is %f\n", begin.x, begin.y, tst_x);
			printf("ray  is  %f,  %f center  %f, %f begin %f, %f check  %f, %f\n", xv, yv, xs, ys, begin.x, begin.y, test_begin.x, test_begin.y);

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