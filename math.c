/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:53:57 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/24 11:25:56 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

double       destance_2_points(double x1, double y1, double x2, double y2)
{
    double   destance;
    destance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return (destance);

}

t_eq_line  find_equation_of_line(double a, double b, double c, double d)
{
    t_eq_line equation;
	double x1, y1, x2, y2;
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
    if (x1 != x2)
        equation.m = (y1 - y2) / (x1 - x2);
    else
        equation.m = 0;
    equation.b = y1 - (equation.m * x1);
    equation.is_perpendicular = 0;
    return (equation);
}

t_point             entersection_two_line(t_eq_line equation1, t_eq_line equation2, t_all_info *info)
{

   t_point     point;
    
    point.x = (equation2.b - equation1.b) / (equation1.m - equation2.m);
    point.y = (point.x * equation1.m) + equation1.b;

	if (equation2.is_perpendicular)
	{
		point.x = info->sprite_struct_all->x;
		point.y = info->sprite_struct_all->y_center;
		return point;
	}
	
    if (equation1.is_perpendicular)
	{
		if (info->sprite_struct_all->x_center != info->xp)
		{
			point.x = info->sprite_struct_all->x_center;
			point.y = (point.x * equation2.m) + equation2.b;	
		}
		else
		{
			point.y = info->sprite_struct_all->y_center;
			point.x = (point.y - equation2.b) / equation2.m;	
		}
		   
	}
    return (point);
}

t_point enter_line_circle(t_all_info *info,double x_c, double y_c, double r, t_eq_line line)
{
    double x1, y1, x2, y2, x_center, y_center, raduis, lm, lb;
    double a, b,c ;
    t_point point;
	x_center = x_c;
	y_center = y_c;
	raduis =r;
	lm = line.m;
	lb = line.b;
    a = pow(lm, 2) + 1;
    b = (2 * lm * (lb - y_center)) - (2 * x_center);
    c = pow(lb - y_center, 2) - pow(raduis, 2) + pow(x_center, 2);
    x1 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    x2 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    y1 = ((lm * x1) + lb);
    y2 = ((lm * x2) + lb);
    if (line.is_perpendicular == 1)
    {
        if (x_center != info->xp)
        {
            x1 = x_center;
            x2 = x1;
            y1 = y_center + (info->size / 2);
            y2 = y_center - (info->size / 2);
        }
        else
        {
            x1 = x_center + (info->size / 2);
            x2 = x_center - (info->size / 2);
            y1 = y_center;
            y2 = y_center;
        }
    }
    if ((info->yp >= y_center && info->xp <= x_center))
    {
        if (x1 > x2 || (x1 == x2 && y1 > y2)) 
        {
            point.x = x2;
            point.y = y2;
        }
        else
        {
            point.x = x1;
            point.y = y1;
        }
    }
	else if (info->yp >= y_center && info->xp >= x_center)
    {
        if (x1 > x2 || (x1 == x2 && y1 < y2))
        {
            point.x = x2;
			
            point.y = y2;
        }
        else
        {
            point.x = x1;
            point.y = y1;
        }
    }
    else 
    {

        if (x1 < x2 )
        {
            point.x = x2;
            point.y = y2;
        }
        else
        {
            point.x = x1;
            point.y = y1;
        }
    }
    return(point);

}