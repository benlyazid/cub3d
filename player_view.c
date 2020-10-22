/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:18:26 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/22 18:21:06 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

#define R_P ( M_PI / 180)

int			draw_image_view(t_all_info *info)
{

	double	x_res, y_res, beta, x_start, y_start, percentage;
	t_eq_line equation;
	t_eq_line equation_center;
	t_eq_line equation_of_ray;
	t_entersection_point	point;
	t_point start_point;
	double xrs, yrs;
	t_entersection_point intersection_point_result;
	t_d_wall	destance_to_wall;
	destance_to_wall = calc_destance_to_wall(info);
	double	angle_player_center;
	double	angle_player_ray;
	double	angle_rotation;
	double	angle_result;
	double	intersection_x;
	double	intersection_y;
	double	point_start_x;
	double	point_start_y;
	double	start_x;
	double	start_y;
	int		get_x;
	int		get_y;
	int		get;
	double	get_x_f, get_y_f;
	double	x_offsite;


	if (info->sprite == 0)
		draw_line(info, info->xp, info->yp, destance_to_wall.x_wall, destance_to_wall.y_wall, 0x253691);
	else
	{
		sort_by_destance(info);	
		 info->sprite_struct_all = info->sprite_struct_start;
		 draw_line(info, info->xp, info->yp, info->sprite_struct_all->x, info->sprite_struct_all->y, 0x253691);

	}
	info->sprite = 0;
	return (0);
}

int				draw_image_view_angle(t_all_info *info)
{
	double save_angle;
	double alpha;

	save_angle = info->angle;
	 alpha = -30;
	 while (alpha <= 30)
	 {
		 info->angle += alpha;
		 draw_image_view(info);
		 info->angle = save_angle;
		 alpha+= 60 / info->width;
	 }
	 info->angle = save_angle;
	return (0);
}

int free_linked_list(t_sprite *list)
{
	t_sprite *save;
	save = list;

	while (list != NULL)
	{
		list = list->next;
		//free(save);
		//save = NULL;
	}
	list = save;
	list = NULL;
	return 0;
}
		
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
	//info->sprite_struct_all = (t_sprite*)malloc(sizeof(t_sprite));
	//info->sprite_struct_start = info->sprite_struct_all;

	//if (info->sprite_struct_start == NULL)



	
	//you are here

	

	/*if (info->sprite_alloc == 0)
	{	
		printf("yes %lu\n", sizeof(t_sprite));
		info->sprite_struct_all = (t_sprite*)malloc(sizeof(t_sprite));
		info->sprite_struct_start = info->sprite_struct_all;
		info->sprite_alloc = 1;
	}
	else
	{
		//free(info->sprite_struct_start);
		info->sprite_struct_all = (t_sprite*)malloc(sizeof(t_sprite));
		info->sprite_struct_start = info->sprite_struct_all;
	}
	while (info->tst == 1)
	{
		printf("tst\n");
	}*/
	
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
				point.x = x - moins; //rm moin;;
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
					info->sprite_struct_all->x = x - moins;
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
					sprite_data->x = x - moins;
					sprite_data->y = y;
					sprite_data->dest = destance_2_points(info->xp, info->yp, x - moins, y);
					sprite_data->next = NULL;		
					add_to_last(info->sprite_struct_all, sprite_data);
					//////
					//free(sprite_data);
					///	//

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
					info->sprite_struct_all->y = y - moins;
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
					sprite_data->y = y - moins;
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

void draw_line(t_all_info *info, int X1, int Y1, int X2, int Y2, int color)
{ 
    // calculate dx & dy 
    int dx =(int) X1 - X2; 
    int dy =(int) Y1 - Y2; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    double Xinc = dx / (double) steps; 
    double Yinc = dy / (double) steps; 
    // Put pixel for each step 
    double X = X2; 
    double Y = Y2; 
	int		index_y;
	int		index_x;
	int 	index;
    for (int i = 0; i <= steps; i++) 
    {
		index_x = (int)X;
		index_y = (int)Y;
		index = (index_y * info->width) + index_x;
		if (index_y >= 0 && index_y < info->height && index_x >= 0 && index_x < info->width)
			info->data[index] = color;

        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
                             // generation step by step 
    } 
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