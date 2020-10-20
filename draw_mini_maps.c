/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_maps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:02:47 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/02/04 17:57:29 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

int	draw_image_surface_mini(t_all_info *info)
{
	float 	x;
	float	y;
	int 	index;
	float	index_x;
	float	index_y;
	int 	index_data;
	y = 0;	
	while (info->height > (int)y * 5)
	{
		x = 0;
		while (info->width > (int)x * 5)
		{
			index_data =(int) ((y * info->width) + x);
			index_x = (int) (x / info->size * 5);
			index_y = (int) (y / info->size  * 5);
			index = (int)((index_y * info->width_number) + index_x); 
			if (info->mp[index] == 1)
				{
					info->data_3d[index_data] = 0xFFFFFF;	
				}
				if (info->mp[index] == 2)
				{
				info->data_3d[index_data] = 0xFF1255;	
				}
			x++;
		}
		y++;
	}
	return (0);
}

int			draw_image_player_mini(t_all_info *info)
{
	float	angle;
	float 	r;
	int	x;
	int	y;
	int		andex;

	angle = 0;
	while (angle <= 2 * M_PI)
	{
		r = 10;
		while (r >= 0)
		{	
			x = (int)(((info->xp) +(r * cosf(angle))) / 5);
			y = (int)(((info->yp) + (r * sinf(angle))) / 5);
			andex = round((y * info->width) + x);
			info->data_3d[andex] = 0xaa02ff;			
			r -= 1;
		}	
		angle += (0.1 * M_PI / 180);
	}
	
	return (0);
}

int				draw_image_view_angle_mini(t_all_info *info)
{
	float save_angle;
	float alpha;

	save_angle = info->angle;
	 alpha = -30;
	 while (alpha <= 30)
	 {
		 info->angle += alpha;
		 ray_casting_mini(info);
		 info->angle = save_angle;
		 alpha+=0.05;
	 }
	 info->angle = save_angle;
	return (0);
}

int ray_casting_mini(t_all_info *info)
{
	t_point	xpoint;
	t_point	ypoint;
	float	xd;
	float	yd;

	xpoint = ray_casting_x_mini(info);
	ypoint = ray_casting_y_mini(info);
	if(xpoint.x >= 0 && xpoint.y >= 0)
		xd = destance(info, xpoint.x, xpoint.y);
	else
		xd = INT32_MAX;
	if (ypoint.x >= 0 && ypoint.y >= 0)
		yd = destance(info, ypoint.x, ypoint.y);
	else 
		yd = INT32_MAX;
	if (xpoint.x > 0 && xpoint.y > 0 && yd >= xd)
	{	
			DDA_mini(info, xpoint.x, xpoint.y, 0x5869aa);
	}
	else if (ypoint.x > 0 && ypoint.y > 0 && xd > yd)
	{	
			DDA_mini(info, ypoint.x, ypoint.y, 0x5869aa);
	}
	return (0);
}

t_point	ray_casting_x_mini(t_all_info *info)
{
	float	x;
	float	y;
	float	xa;
	float 	ya;
	int		index_x;
	int		index_y;
	int		index;
	t_point	point;
	int		divs;
	int		moins;

	moins = 0;
	divs = (int)(info->xp / info->size);
	divs *= info->size;
	x = divs;
	if (cosf(info->angle * R_P) > 0)
		x += info->size; 
	else
		{
			moins = 1;
			//x-=1;
		}
	y = info->yp + (x - info->xp) * tanf(info->angle * R_P);
	if (cosf(info->angle * R_P) > 0)
		xa = info->size;
	else
		xa = -1 * info->size;
	ya = xa * tanf(info->angle * R_P);
	while (x >= 0 && y >= 0 && x < info->width && y < info->height)
	{
		index_x = ((int)x - moins) * (int)info->width_number / (int)info->width;
		index_y = (int)y * (int)info->height_number / (int)info->height;	
		index = (index_y * (int)info->width_number  + index_x);
		if (info->mp[index] == 1 || info->mp[index] == 2 )
		{
			point.x =(int)x;
			point.y =(int)y;
			return (point);
		}
		x+= xa;
		y+= ya;
	}
	point.x = -1;
	point.y = -1;
	return (point);
}

t_point	ray_casting_y_mini(t_all_info *info)
{
	float		x;
	float		y;
	float		xa;
	float 		ya;
	t_point		point;
	int			divs;
	int			moins;
	int index_x;
	int index_y;
	int index;
	
	moins =0;
	divs = (info->yp / info->size) ;
	divs *= info->size; 
	y = divs;
	if (sinf(info->angle * R_P) > 0)
		y += info->size;
	else
		{
			moins = 1;
		}
	x = info->xp + ((y -info->yp) / tanf(info->angle * R_P));
	if (sinf(info->angle * R_P) > 0)
		ya = info->size;
	else
		ya = -1 * info->size;
		if (sinf(info->angle *R_P) == 1 || sinf(info->angle *R_P) == -1) //tanf (90) == error 
			xa = 0;
		else 
			xa = ya / tanf(info->angle * R_P);
	
	while (x >= 0 && y  >= 0 && x <= info->width && y <= info->height)
	{
		index_x = (int)x * (int)info->width_number / (int)info->width;
		index_y = ((int)y - moins) * (int)info->height_number / (int)info->height;	
		index = (index_y * (int)info->width_number  + index_x);
		if (info->mp[index] == 1 || info->mp[index] == 2 )
		{
			point.x = (int)x;
			point.y = (int)y;
			return (point);
		}
		x += xa;
		y += ya;
	}
	point.x = -1;
	point.y = -1;
	return (point);
}

void DDA_mini(t_all_info *info, int X1, int Y1, int color) 
{ 
    // calculate dx & dy 
    int dx =(int) (X1 - (int)info->xp) / 5; 
    int dy =(int) (Y1 - (int)info->yp) / 5; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
    // Put pixel for each step 
    float X = info->xp / 5; 
    float Y = info->yp / 5; 
	int		index_y;
	int		index_x;
	int 	index;
    for (int i = 0; i <= steps; i++) 
    {
		index_x = (int)X ;
		index_y = (int)Y ;
		index = (index_y * info->width) + index_x;
		info->data_3d[index] = color;
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
                             // generation step by step 
    } 
} 