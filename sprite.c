/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:39:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 09:29:56 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define R_P ( M_PI / 180)

t_eq_line	get_eqution_of_sprite(t_all_info *info, t_eq_line player_sprite)
{
	t_eq_line	line;
	double		xs;
	double		ys;

	xs = info->all_sprt->xc;
	ys = info->all_sprt->yc;
	if (player_sprite.m != 0)
	{
		line.is_perpendicular = 0;
		line.m = -1 / player_sprite.m;
		line.b = ys - (xs * line.m);
	}
	else
	{
		line.is_perpendicular = 1;
		line.m = 0;
		line.b = ys;
	}
	return (line);
}

int			set_sprite_color(t_all_info *info, double x_off, int i, double z)
{
	double	xs;
	double	ys;
	double	get_x_f;
	double	get_y_f;
	int		get;

	xs = info->all_sprt->xc;
	ys = info->all_sprt->yc;
	get_x_f = (x_off / info->size) * info->sprite_w;
	get_y_f = (z / info->prjct_sprt) * info->sprite_h;
	get = (int)get_y_f * info->sprite_w + (int)get_x_f;
	if (destance_2_points(xs, ys, info->view.x, info->view.y) < info->size / 2
	&& x_off < info->size && get >= 0 && get < (int)info->sprite_h *
	(int)info->sprite_w)
	{
		info->old_point.x = info->view.x;
		info->old_point.y = info->view.y;
		if (x_off > 0.0 && x_off < info->size)
			if (info->data_sprite[get] > 0x000000)
				info->data_3d[i] = info->data_sprite[get];
	}
	return (0);
}

int			get_sprite_value(t_all_info *info, double z_sprite, int i, double x)
{
	double		x_offsite;
	t_eq_line	sprite_center;
	t_point		begin;
	t_eq_line	player_sprite_center;
	t_eq_line	player_sprite;

	player_sprite = find_equation_of_line(info->xp, info->yp,
	info->all_sprt->x, info->all_sprt->y);
	if (player_sprite.m == 0)
	{
		player_sprite.is_perpendicular = 1;
		player_sprite.m = 0;
		player_sprite.b = info->all_sprt->yc;
	}
	player_sprite_center = find_equation_of_line(info->xp, info->yp,
	info->all_sprt->xc, info->all_sprt->yc);
	sprite_center = get_eqution_of_sprite(info, player_sprite_center);
	info->view = entersection_two_line(sprite_center, player_sprite, info);
	info->view.x = !player_sprite.m ? info->old_point.x : info->view.x;
	info->view.y = !player_sprite.m ? info->old_point.y : info->view.y;
	begin = entr_ln_cr(info, info->all_sprt->xc, info->all_sprt->yc,
	sprite_center);
	x_offsite = destance_2_points(begin.x, begin.y, info->view.x, info->view.y);
	set_sprite_color(info, x_offsite, i, z_sprite);
	return (1);
}

int			get_sprite_from_file(t_all_info *info)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	path = get_sprite_path(info);
	i = 0;
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)
		return (-1);
	close(i);
	info->sprite_img = mlx_xpm_file_to_image(info->mlx_ptr, path, &j, &i);
	info->sprite_h = i;
	info->sprite_w = j;
	info->data_sprite = (int*)mlx_get_data_addr(info->sprite_img, &i, &j, &k);
	free(path);
	free(info->sprite_img);
	return (1);
}
