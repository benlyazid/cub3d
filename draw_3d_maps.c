/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:55:05 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/01/05 08:52:21 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R_P ( M_PI / 180)

void		initial_value(t_all_info *info, float alpha)
{
	if (!(info->sprt_strct_all = malloc(sizeof(t_sprite))))
		return ;
	info->sprite_struct_start = info->sprt_strct_all;
	info->wall_dest = calc_destance_to_wall(info);
	info->x_wall = info->wall_dest.x_wall;
	info->y_wall = info->wall_dest.y_wall;
	info->projection_wall = info->dst_player_projection * info->size
	/ (info->wall_dest.destance * cos(alpha * R_P));
	info->start = (int)((info->height - info->projection_wall) / 2);
	info->end = (int)((info->height + info->projection_wall) / 2);
	if (info->end > info->height)
		info->end = info->height;
}

void		draw_texteur(t_all_info *info, int x_of, int x)
{
	int	z;
	int	index;
	int	color_index;
	int	y0;

	z = info->end - 1;
	while (z > -1 && z > info->start)
	{
		index = (z * info->width) + x;
		if (index >= 0 && index < (int)info->height * (int)info->width)
		{
			y0 = (z - info->start) * info->txt_h / info->projection_wall;
			color_index = ((int)y0 * info->txt_w) + (int)x_of;
			if (x_of >= 0 && x_of < info->txt_w && y0 >= 0 && y0 < info->txt_h)
				info->data_3d[index] = info->txt_img_data[color_index];
		}
		z--;
	}
}

void		draw_sprite(t_all_info *info, int x, int x_offsite)
{
	int		z;
	int		index;
	float	get_x;
	float	get_y;
	int		get;

	z = info->end;
	while (z > -1 && z > info->start)
	{
		index = ((int)z * (int)info->width) + (int)x;
		if (index >= 0 && index < (int)info->height * (int)info->width)
			if (info->wall_dest.destance > info->sprt_strct_all->dest
			&& x_offsite < info->size && x_offsite > -1)
			{
				get_x = (x_offsite / info->size) * info->sprt_w;
				get_y = ((z - info->start) / info->prjct_sprit) * info->sprt_h;
				get = (int)get_y * info->sprt_w + (int)get_x;
				if (get > -1 && get < (int)info->sprt_h * (int)info->sprt_w
				&& info->data_sprite[get] > 0x000000)
					info->data_3d[index] = info->data_sprite[get];
			}
		z -= 1;
	}
}

int			initial_sprite(t_all_info *info)
{
	int	x_offsite;

	info->rayon = DEST_2P(info->xp, info->yp, info->sprt_strct_all->x_center,
	info->sprt_strct_all->y_center);
	info->prjct_sprit = info->dst_player_projection * info->size / info->rayon;
	info->start = ((int)info->height - (int)info->prjct_sprit) / 2;
	info->end = (((int)info->height + (int)info->prjct_sprit) / 2);
	if (info->end > info->height)
		info->end = info->height - 1;
	x_offsite = get_sprite_value(info);
	return (x_offsite);
}

int			draw_3d_image(t_all_info *info, float x, float alpha)
{
	int			x_offsite;
	t_sprite	*save;

	initial_value(info, alpha);
	x_offsite = get_texteur_value(info, info->wall_dest.type);
	draw_texteur(info, x_offsite, x);
	if (info->sprite == 1)
	{
		sort_by_destance(info);
		info->sprt_strct_all = info->sprite_struct_start;
		while (info->sprite == 1 && info->sprt_strct_all)
		{
			x_offsite = initial_sprite(info);
			draw_sprite(info, x, x_offsite);
			save = info->sprt_strct_all->next;
			free(info->sprt_strct_all);
			info->sprt_strct_all = save;
		}
		info->sprt_strct_all = info->sprite_struct_start;
	}
	if (info->sprite == 0)
		free(info->sprite_struct_start);
	info->sprite = 0;
	return (0);
}
