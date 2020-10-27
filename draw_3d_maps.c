/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:55:05 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/27 09:49:53 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

int			initial_value_for_3d(t_all_info *info, double alpha)
{
	info->all_sprt = malloc(sizeof(t_sprite));
	info->sprite_struct_start = info->all_sprt;
	info->wll_dst = calc_destance_to_wall(info);
	info->x_wall = info->wll_dst.x_wall;
	info->y_wall = info->wll_dst.y_wall;
	info->dst_to_wall = info->wll_dst.destance * cos(alpha * R_P);
	info->dst_ply_prj = (info->width / 2) / tan(M_PI / 6);
	if (info->wll_dst.type != 'z')
		info->projection_wall = info->dst_ply_prj * info->size /
		info->dst_to_wall;
	else
	{
		info->projection_wall = 0;
		info->wll_dst.type = 'y';
	}
	info->start = (int)((info->height - info->projection_wall) / 2);
	info->end = (int)((info->height + info->projection_wall) / 2);
	return (1);
}

int			draw_wall_flor_sol(t_all_info *info, double x, int z, int c)
{
	int	i;

	while (z++ < info->start)
	{
		i = ((z * (int)info->width) + (int)x);
		info->data_3d[i] = (int)info->color_coll.value;
	}
	z = info->start;
	while (z < (int)info->end)
	{
		i = (z * info->width) + (int)x;
		if (i >= 0 && i < (int)info->height * (int)info->width)
			info->data_3d[i] = get_texteur_value(info, c, info->wll_dst.type);
		c++;
		z++;
	}
	z = info->end;
	while (z < (int)info->height)
	{
		i = ((z * (int)info->width) + (int)x);
		if (i >= 0 && i < info->width * info->height)
			info->data_3d[i] = (int)info->color_flor.value;
		z++;
	}
	return (1);
}

int			draw_sprite(t_all_info *info, int x)
{
	t_sprite	*save;
	int			i;

	while (info->sprite == 1 && info->all_sprt)
	{
		info->dst = destance_2_points(info->xp, info->yp,
		info->all_sprt->xc, info->all_sprt->yc);
		info->prjct_sprt = info->dst_ply_prj * info->size / info->dst;
		info->sprit_start = ((int)info->height - (int)info->prjct_sprt) / 2;
		info->sprit_end = (((int)info->height + (int)info->prjct_sprt) / 2);
		info->z_sprt = info->sprit_start;
		while (info->z_sprt < info->sprit_end)
		{
			i = ((int)info->z_sprt * (int)info->width) + (int)x;
			if (i >= 0 && i < (int)info->height * (int)info->width)
				if (info->wll_dst.destance > info->all_sprt->dest)
					get_sprite_value(info, info->z_sprt - info->sprit_start, i);
			info->z_sprt += 1;
		}
		save = info->all_sprt->next;
		free(info->all_sprt);
		info->all_sprt = save;
	}
	return (0);
}

int			draw_3d_image(t_all_info *info, double x, double alpha)
{
	initial_value_for_3d(info, alpha);
	draw_wall_flor_sol(info, x, -1, 0);
	if (info->sprite == 1)
	{
		sort_by_destance(info);
		info->all_sprt = info->sprite_struct_start;
	}
	draw_sprite(info, x);
	if (info->sprite == 0)
		free(info->sprite_struct_start);
	info->sprite = 0;
	return (0);
}

int			draw_all_image_3d(t_all_info *info)
{
	double	save_angle;
	double	alpha;
	double	x;

	save_angle = info->angle;
	alpha = -30;
	x = 0;
	info->test = 0;
	while (x < info->width)
	{
		info->tst = x;
		info->angle += alpha;
		draw_3d_image(info, x, alpha);
		info->angle = save_angle;
		alpha += (60 / info->width);
		x += 1;
	}
	info->old_debug = -1;
	info->angle = save_angle;
	return (0);
}
