/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:18:26 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 17:27:25 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*add_to_last(t_sprite *sprite_list, t_sprite *sprite)
{
	while (sprite_list->next)
		sprite_list = (sprite_list->next);
	sprite_list->next = sprite;
	return (0);
}

int			swap_struct(t_all_info *info)
{
	t_sprite	*sprite_change;

	sprite_change = (t_sprite*)malloc(sizeof(t_sprite));
	sprite_change->dest = info->all_sprt->next->dest;
	info->all_sprt->next->dest = info->all_sprt->dest;
	info->all_sprt->dest = sprite_change->dest;
	sprite_change->x = info->all_sprt->next->x;
	info->all_sprt->next->x = info->all_sprt->x;
	info->all_sprt->x = sprite_change->x;
	sprite_change->y = info->all_sprt->next->y;
	info->all_sprt->next->y = info->all_sprt->y;
	info->all_sprt->y = sprite_change->y;
	sprite_change->xc = info->all_sprt->next->xc;
	info->all_sprt->next->xc = info->all_sprt->xc;
	info->all_sprt->xc = sprite_change->xc;
	sprite_change->yc = info->all_sprt->next->yc;
	info->all_sprt->next->yc = info->all_sprt->yc;
	info->all_sprt->yc = sprite_change->yc;
	free(sprite_change);
	return (0);
}

int			sort_by_destance(t_all_info *info)
{
	t_sprite	*sprite_save;
	t_sprite	*sprite_change;

	sprite_save = info->sprite_struct_start;
	info->all_sprt = info->sprite_struct_start;
	while (sprite_save->next)
	{
		info->all_sprt = info->sprite_struct_start;
		while (info->all_sprt->next)
		{
			if (info->all_sprt->dest < info->all_sprt->next->dest)
			{
				swap_struct(info);
			}
			info->all_sprt = info->all_sprt->next;
		}
		sprite_save = sprite_save->next;
	}
	return (0);
}
