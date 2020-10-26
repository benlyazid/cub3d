/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:53:57 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 09:29:56 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

double		destance_2_points(double x1, double y1, double x2, double y2)
{
	double	destance;

	destance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return (destance);
}

t_eq_line	find_equation_of_line(double x1, double y1, double x2, double y2)
{
	t_eq_line equation;

	if (x1 != x2)
		equation.m = (y1 - y2) / (x1 - x2);
	else
	{
		equation.m = 0;
		equation.is_perpendicular = 1;
	}
	equation.b = y1 - (equation.m * x1);
	equation.is_perpendicular = 0;
	return (equation);
}

t_point		entersection_two_line(t_eq_line eq1, t_eq_line eq2, t_all_info *ifo)
{
	t_point	point;

	point.x = (eq2.b - eq1.b) / (eq1.m - eq2.m);
	point.y = (point.x * eq1.m) + eq1.b;
	if (eq1.is_perpendicular)
	{
		if (ifo->all_sprt->xc != ifo->xp)
		{
			point.x = ifo->all_sprt->xc;
			point.y = (point.x * eq2.m) + eq2.b;
		}
		else
		{
			point.y = ifo->all_sprt->yc;
			point.x = (point.y - eq2.b) / eq2.m;
		}
	}
	return (point);
}

int			set_var(t_all_info *info, double x_c, double y_c, t_eq_line line)
{
	info->aa = pow(line.m, 2) + 1;
	info->bb = (2 * line.m * (line.b - y_c)) - (2 * x_c);
	info->cc = pow(line.b - y_c, 2) - pow((info->size / 2), 2) + pow(x_c, 2);
	info->x1 = (-info->bb - sqrt(pow(info->bb, 2) - (4 * info->aa * info->cc)))
	/ (2 * info->aa);
	info->x2 = (-info->bb + sqrt(pow(info->bb, 2) - (4 * info->aa * info->cc)))
	/ (2 * info->aa);
	info->y1 = ((line.m * info->x1) + line.b);
	info->y2 = ((line.m * info->x2) + line.b);
	if (line.is_perpendicular == 1)
	{
		info->x1 = (x_c != info->xp) ? x_c : x_c + (info->size / 2);
		info->x2 = (x_c != info->xp) ? x_c : info->x1 - (info->size / 2);
		info->y1 = (x_c != info->xp) ? y_c + (info->size / 2) : y_c;
		info->y2 = (x_c != info->xp) ? y_c - (info->size / 2) : y_c;
	}
	return (0);
}

t_point		entr_ln_cr(t_all_info *info, double x_c, double y_c, t_eq_line line)
{
	t_point point;

	set_var(info, x_c, y_c, line);
	if ((info->yp >= y_c && info->xp <= x_c))
	{
		point.x = (info->x1 > info->x2 || (info->x1 == info->x2 &&
		info->y1 > info->y2)) ? info->x2 : info->x1;
		point.y = (info->x1 > info->x2 || (info->x1 == info->x2 &&
		info->y1 > info->y2)) ? info->y2 : info->y1;
	}
	else if (info->yp >= y_c && info->xp >= x_c)
	{
		point.x = (info->x1 > info->x2 || (info->x1 == info->x2 &&
		info->y1 < info->y2)) ? info->x2 : info->x1;
		point.y = (info->x1 > info->x2 || (info->x1 == info->x2 &&
		info->y1 < info->y2)) ? info->y2 : info->y1;
	}
	else
	{
		point.x = info->x1 < info->x2 ? info->x2 : info->x1;
		point.y = info->x1 < info->x2 ? info->y2 : info->y1;
	}
	return (point);
}
