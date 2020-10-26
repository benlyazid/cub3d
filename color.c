/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:36:46 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 17:20:55 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_color_flor_value(t_all_info *info, int i)
{
	while (info->file[i] == ' ')
		i++;
	if (ft_isdigit(info->file[i]))
		info->color_flor.r = ft_atoi(&info->file[i]);
	else
		info->color_flor.status = 0;
	while (ft_isdigit(info->file[i]))
		i++;
	if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
		info->color_flor.g = ft_atoi(&info->file[++i]);
	else
		info->color_flor.status = 0;
	while (ft_isdigit(info->file[i]))
		i++;
	if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
		info->color_flor.b = ft_atoi(&info->file[++i]);
	else
		info->color_flor.status = 0;
	return (i);
}

int	get_color_flor(t_all_info *info)
{
	int i;

	i = -1;
	info->color_flor.status = 0;
	while (info->file[++i])
	{
		if ((info->file[i] == 'F' && info->file[i + 1] == ' ')
		&& (i == 0 || info->file[i - 1] == '\n'))
		{
			info->color_flor.status = 1;
			i++;
			i = set_color_flor_value(info, i);
			if (info->color_flor.r + info->color_flor.g +
			info->color_flor.b > 766)
				info->color_flor.status = 0;
			while (ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] != '\n')
				info->color_flor.status = 0;
		}
	}
	return (0);
}

int	set_color_coll_value(t_all_info *info, int i)
{
	if (ft_isdigit(info->file[i]))
		info->color_coll.r = ft_atoi(&info->file[i]);
	else
		info->color_coll.status = 0;
	while (ft_isdigit(info->file[i]))
		i++;
	if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
		info->color_coll.g = ft_atoi(&info->file[++i]);
	else
		info->color_coll.status = 0;
	while (ft_isdigit(info->file[i]))
		i++;
	if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
		info->color_coll.b = ft_atoi(&info->file[++i]);
	else
		info->color_coll.status = 0;
	if (info->color_coll.r + info->color_coll.g + info->color_coll.b > 766)
		info->color_coll.status = 0;
	while (ft_isdigit(info->file[i]))
		i++;
	if (info->file[i] != '\n')
		info->color_coll.status = 0;
	return (i);
}

int	get_color_coll(t_all_info *info)
{
	int i;

	i = -1;
	info->color_coll.status = 0;
	while (info->file[++i])
	{
		if ((info->file[i] == 'C' && info->file[i + 1] == ' ') &&
		(i == 0 || info->file[i - 1] == '\n'))
		{
			i++;
			info->color_coll.status = 1;
			while (info->file[i] == ' ')
				i++;
			i++;
			info->color_coll.status = 1;
			i = set_color_coll_value(info, i);
		}
	}
	return (0);
}
