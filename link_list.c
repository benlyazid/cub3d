/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:18:26 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/03 12:35:03 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*add_to_last(t_sprite *sprite_list, t_sprite *sprite)
{
	while (sprite_list->next)
	{
		if (sprite_list->x_center == sprite->x_center &&
		sprite_list->y_center == sprite->y_center)
			return (0);
		sprite_list = (sprite_list->next);
	}
	if (sprite_list->x_center == sprite->x_center &&
	sprite_list->y_center == sprite->y_center)
		return (0);
	sprite_list->next = sprite;
	return (0);
}

void		swap_sprite(t_all_info *info)
{
	t_sprite	*sprite_change;

	sprite_change = (t_sprite*)malloc(sizeof(t_sprite));
	sprite_change->dest = info->sprite_struct_all->next->dest;
	info->sprite_struct_all->next->dest = info->sprite_struct_all->dest;
	info->sprite_struct_all->dest = sprite_change->dest;
	sprite_change->x_center = info->sprite_struct_all->next->x_center;
	info->sprite_struct_all->next->x_center = info->sprite_struct_all->x_center;
	info->sprite_struct_all->x_center = sprite_change->x_center;
	sprite_change->y_center = info->sprite_struct_all->next->y_center;
	info->sprite_struct_all->next->y_center = info->sprite_struct_all->y_center;
	info->sprite_struct_all->y_center = sprite_change->y_center;
	free(sprite_change);
}

int			sort_by_destance(t_all_info *info)
{
	t_sprite	*sprite_save;

	sprite_save = info->sprite_struct_start;
	info->sprite_struct_all = info->sprite_struct_start;
	while (sprite_save->next)
	{
		info->sprite_struct_all = info->sprite_struct_start;
		while (info->sprite_struct_all->next)
		{
			if (info->sprite_struct_all->dest <
			info->sprite_struct_all->next->dest)
				swap_sprite(info);
			info->sprite_struct_all = info->sprite_struct_all->next;
		}
		sprite_save = sprite_save->next;
	}
	return (0);
}
