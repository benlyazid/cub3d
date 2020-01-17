/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:18:26 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/01/16 12:23:41 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

#define R_P ( M_PI / 180)

// int			sheck_for_wall(float x, float y, t_all_info *info)
// {
// 	int dev;
// 	int index_x;
// 	int	index_y;
// 	int	index;
// 		index_x = x * info->width_number / info->width;
// 		index_y = y * info->height_number / info->height;	
// 		index = (int)((index_y * info->width_number  + index_x) * 2);
// 		if (info->maps[index] == '1' || info->maps[index + 1] == '1')
	
// 	return (0);	
// }

int			sheck_block(float x, float y, t_all_info *info)
{
	int x0;
	int	y0;
	int	ix;
	int	index;
	int	iy;

	x0 = (int)(x / info->width_size);
	x0 *= (int)(info->width_size);	
	y0 = (int)(y / info->height_size);
	y0 *= (int)(info->height_size);
	ix = 1;
	ft_putstr_fd("x_size is : ",1);
	ft_putnbr_fd(info->width_size, 1);
	ft_putstr_fd("\n",1);
	ft_putstr_fd("y_size is : ",1);
	ft_putnbr_fd(info->height_size, 1);
	ft_putstr_fd("\n",1);
	ft_putstr_fd("x0 is : ",1);
	ft_putnbr_fd(x0, 1);
	ft_putstr_fd("\n",1);
	ft_putstr_fd("y0 is : ",1);
	ft_putnbr_fd(y0, 1);
	ft_putstr_fd("\n-----------\n",1);	
	while (ix < info->width_size - 1)
	{
		iy = 1; //x+1?
		while (iy < info->height_size - 1)
		{
			index = (y0 + iy) * info->width + (x0 + ix); 
			if (info->data[index] == 0xffffff)
				{
					ft_putstr_fd("x_end is : ",1);
					ft_putnbr_fd(x0 + ix, 1);
					ft_putstr_fd("\n",1);
					ft_putstr_fd("y_end is : ",1);
					ft_putnbr_fd(y0 + iy, 1);
					ft_putstr_fd("\n------------------------------------end \n",1);	
					return (1);
				}
			iy++;
		}
		ix++;	
	}
	return (0);
}

int			draw_image_view(t_all_info *info)
{
	int i;
	int index;
	int	index_x;
	int	index_y;
	int x;
	int y;

	i = 0;
		while (1)
		{
				index_x = (int)((info->xp + (i * cos((info->angle) * R_P))) * info->width_number / info->width);
				index_y = (int)((info->yp + (i * sin((info->angle) * R_P))) * info->height_number / info->height);		
				index = (index_y * info->width_number  + index_x) * 2;
				x = (int)(info->xp + (cos((info->angle + 0)* R_P) * i));
				y = (int)(info->yp + (sin((info->angle + 0)* R_P) * i));
				if (info->maps[index] == '1')
					return(0) ; 
					index = (y * info->width) + x;
				info->data[index] = 0x6416FAA;
				i++;
		}
		
	return (0);
	//floor bas
	//round meduim
	//ceil height 
	
}

int			destrow_image_view(t_all_info *info, int xp, int yp, float angle)
{
	int i;
	int index;
	int	index_x;
	int	index_y;
	int x;
	int y;

	i = 0;
		while (1)
		{
				index_x = (int)((xp + (i * cos((angle + 0)* R_P))) * info->width_number / info->width);
				index_y = (int)((yp + (i * sin((angle + 0)* R_P))) * info->height_number / info->height);		
				index = (index_y * info->width_number  + index_x) * 2;
		x = (int)(xp + (cos((angle + 0)* R_P) * i));
				y = (int)(yp + (sin((angle + 0)* R_P) * i));
			if (info->maps[index] == '1')
				return (0);
			index = (y * info->width) + x;
			info->data[index] = 0x0;
			i++;
		}	
	return (0);
	
}

int				draw_image_view_angle(t_all_info *info)
{
	float save_angle;
	float alpha;

	save_angle = info->angle;
	 alpha = -30;
	 ray_casting(info);
	 while (alpha <= 30)
	 {
		 info->angle += alpha;
		 draw_image_view(info);
		 info->angle = save_angle;
		 alpha+= 0.05;
		 
	 }
	 info->angle = save_angle;
	return (0);
}
int				destrow_image_view_angle(t_all_info *info, int xp, int yp, float angle)
{
	float save_angle;
	float alpha;

	save_angle = angle;
	 alpha = -30;
	 while (alpha <= 30)
	 {
		 angle += alpha;
		destrow_image_view(info, xp, yp,  angle);
		 angle = save_angle;
		 alpha+= 0.05;
		 
	 }
	 angle = save_angle;
	return (0);
}

int ray_casting(t_all_info *info)
{
	t_point	xpoint;
	t_point	ypoint;
	float	xd;
	float	yd;

	xpoint = ray_casting_x(info);
	ypoint = ray_casting_y(info);
	if(xpoint.x >= 0 && xpoint.y >= 0)
		xd = destance(info, xpoint.x, xpoint.y);
	else
		xd = INT32_MAX;
	if (ypoint.x >= 0 && ypoint.y >= 0)
		yd = destance(info, ypoint.x, ypoint.y);
	else 
		yd = INT32_MAX;
	/*ft_putnbr_fd(ypoint.x, 1);
	ft_putstr_fd("	", 1);
	ft_putnbr_fd(ypoint.y, 1);
	ft_putstr_fd("\n", 1);*/
	
	
	///////////////////////////////////////////////////
	if (xpoint.x > 0 && xpoint.y > 0 && yd >= xd)
	{	
			DDA(info, xpoint.x, xpoint.y, 0x5869aa);
	}
	else if (ypoint.x > 0 && ypoint.y > 0 && xd > yd)
	{	
			DDA(info, ypoint.x, ypoint.y, 0x5869aa);
	}
	/////////////////////////////////////////////
	//if (xpoint.x >= 0 && xpoint.y >= 0 && xpoint.x <= info->width && xpoint.y <= info->height)
	//	DDA(info, xpoint.x, xpoint.y, 0x5869aa);
	// if  (ypoint.x >= 0 && ypoint.y >= 0 && ypoint.x <= info->width && ypoint.y <= info->height)
		//	DDA(info, ypoint.x, ypoint.y, 0x5869aa);

		
	return (0);
}
		
t_point	ray_casting_x(t_all_info *info)
{
	float	x;
	float	y;
	float	xa;
	float 	ya;
	int		index_x;
	int		index_y;
	int		index;
	t_point	point;
	int		dvs;

	dvs = (int)(info->xp / info->width_size);
	dvs *= info->width_size;
	x = dvs;
	if (cos(info->angle * R_P) > 0)
		x += info->width_size; 
	else
		x-=1;
	y = info->yp + (x - info->xp) * tan(info->angle * R_P);
	if (cos(info->angle * R_P) > 0)
		xa = info->width_size;
	else
		xa = -1 * info->width_size;
	ya = xa * tan(info->angle * R_P); //info->height_size place by xa;
	while (x >= 0 && y >= 0 && x < info->width && y < info->height)
	{
		index_x = (int)x * info->width_number / info->width;
		index_y = (int)y * info->height_number / info->height;	
		index = (index_y * info->width_number  + index_x) * 2;
		if (sheck_block(x, y, info))
		{
			point.x = x;
			point.y = y;
			return (point);
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
	float		x;
	float		y;
	float		xa;
	float 		ya;
	//float		index_x;
	//float		index_y;
	//int			index;
	t_point		point;
	int			divs;
	
	divs = (info->yp / info->height_size) ;
	divs *= info->height_size; 
	y = divs;
	if (sin(info->angle * R_P) > 0)
		y += info->height_size;
	else
		y -= 1;
	x = info->xp + ((y -info->yp) / tan(info->angle * R_P));
	if (sin(info->angle * R_P) > 0)
		ya = info->height_size;
	else
		ya = -1 * info->height_size;
		if (sin(info->angle *R_P) == 1 || sin(info->angle *R_P) == -1) //tan (90) == error 
			xa = 0;
		else 
			xa = ya / tan(info->angle * R_P);
	
	while (x >= 0 && y >= 0 && x <= info->width && y <= info->height)
	{
		
		/*ft_putstr_fd("		", 1);
		ft_putnbr_fd(index, 1);
		ft_putstr_fd("		", 1);
		ft_putchar_fd(info->maps[index], 1);*/
		//info->data[(int)y * (int)info->width + (int)x] = 0xffff00;
		if ( sheck_block(x, y, info)/*info->data[index] != 0|| info->maps[index + 5] == '1' || info->maps[index - 5] == '1'*/)
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

void DDA(t_all_info *info, int X1, int Y1, int color) 
{ 
    // calculate dx & dy 
    int dx =(int) X1 - (int)info->xp; 
    int dy =(int) Y1 - (int)info->yp; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
    // Put pixel for each step 
    float X = info->xp; 
    float Y = info->yp; 
	int		index_y;
	int		index_x;
	int 	index;
    for (int i = 0; i <= steps; i++) 
    {
		index_x = (int)X;
		index_y = (int)Y;
		index = (index_y * info->width) + index_x;
		info->data[index] = color;
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
                             // generation step by step 
    } 
} 

int rm_all(t_all_info *info)
{
	int x;
	int y;
	int index;

	x = 0;
	while (x < info->width)
	{
		y = 0;
		while (y < info->height)
		{
			index =  y * info->width + x;
			info->data[(index)] = 0x0;
			y++;
		}
		x++;
	}
	return (0);
}

float			destance(t_all_info *info, int x, int y)
{	
	float	destance;
	float	xx;
	float	yy;
	
	xx = (info->xp - x) * (info->xp - x);
	yy = (info->yp - y) * (info->yp - y);
	destance = sqrt(xx + yy);
	return (destance);
}
