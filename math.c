/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:53:57 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/21 13:25:57 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)
float   value_angle_2_point (int x1, int y1, t_all_info *info, int x2, int y2)
{
    float   angle;
    float   sprite;
    float   player;
    float   sprite_amgnitude;
    float   player_magnitude;

  
    angle = atan2f(y1 - y2, x1 - x2);
    return (angle);
}

float       destance_2_points(float x1, float y1, float x2, float y2)
{
    float   destance;
    destance = sqrtf(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    return (destance);

}

t_equation_of_line  find_equation_of_line(float x1, float y1, float x2, float y2)
{
    t_equation_of_line equation;
    if (x1 != x2)
        equation.m = (y1 - y2) / (x1 - x2);
    else
        equation.m = 0;
    equation.b = y1 - (equation.m * x1);
    equation.is_perpendicular = 0;
    return (equation);
}

t_entersection_point             find_entersection_point_of_two_line(t_equation_of_line equation1, t_equation_of_line equation2, t_all_info *info)
{

   t_entersection_point     point;
    
    point.x = (equation2.b - equation1.b) / (equation1.m - equation2.m);
    point.y = (point.x * equation1.m) + equation1.b;

    if (equation1.is_perpendicular || equation2.is_perpendicular)
    {    
        if (info->xp != info->sprite_struct_all->x_center)
        {
            point.x = info->sprite_struct_all->x_center;
            if (!equation1.is_perpendicular)
                point.y = (point.x * equation1.m) + equation1.b;
                
            if (!equation2.is_perpendicular)
                point.y = (point.x * equation2.m) + equation2.b;
        }
        else
        {
            point.y = info->sprite_struct_all->y_center;
            if (!equation1.is_perpendicular)
                point.x = (point.y - equation1.b) / equation1.m;
                
            if (!equation2.is_perpendicular)
                point.x = (point.y - equation2.b) / equation2.m;
        }

    }
    return (point);
}

float   normalisie_angle(float angle)
{
    if (angle > 2 * M_PI)
        angle -= (2 * M_PI);
    if (angle < 0)
        angle += (2 * M_PI);
    return(angle);
}

t_point find_entersection_point_ofline_and_circle(t_all_info *info,float x_center, float y_center, float raduis, t_equation_of_line line)
{
    float x1, y1, x2, y2;
    float a, b,c ;
    t_point point;
    a = powf(line.m, 2) + 1;

    b = (2 * line.m * (line.b - y_center)) - (2 * x_center);

    c = powf(line.b - y_center, 2) - powf(raduis, 2) + powf(x_center, 2);

    x1 = (-b - sqrtf(powf(b, 2) - (4 * a * c))) / (2 * a);
    x2 = (-b + sqrtf(powf(b, 2) - (4 * a * c))) / (2 * a);
    y1 = ((line.m * x1) + line.b);
    y2 = ((line.m * x2) + line.b);

    if (line.is_perpendicular == 1)
    {
        if (x_center != info->sprite_struct_all->x_center)
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
    
    // if (destance_2_points(x1, y1, 0, 0) > destance_2_points(x2, y2, 0, 0))
    if ((info->yp >= y_center && info->xp >= x_center) || (info->yp >= y_center && info->xp <= x_center))
    {
       // printf("data is : x1 : %f, y1 : %f, X2 : %f, y2 : %f\n", x1, y1, x2, y2);
        if (x1 > x2 || (x1 == x2 && y1 > y2))
        {
           // printf("enter 0\n");

            point.x = x2;
            point.y = y2;
        }
        else
        {
           // printf("enter 1\n");
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
    

    
   /* if(point.x == x1)
        printf("else pint is %f, %f\n", x2, (line.m * x2) + line.b);
    else
        printf("else pint is %f, %f\n", x1, (line.m * x1) + line.b);*/
        
    return(point);

}