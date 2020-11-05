/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:08:55 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/04 18:35:43 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	i--;
	while (ft_isdigit(str[++i]))
		j++;
	if (j > 4)
		return (0);
	return (1);
}

int	set_color_f(t_all_info *info, int i, char type)
{
	int color;

	while (type == 'r' && info->file[i] == ' ')
		i++;
	while (info->file[i] == '0')
		i++;
	if (type != 'r')
	{
		while (ft_isdigit(info->file[i]))
			i++;
		if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
			i++;
	}
	if (ft_isdigit(info->file[i]) && check_color(info->file + i))
	{
		if (type == 'r')
			info->clr_f.r = ft_atoi(&info->file[i]);
		if (type == 'g')
			info->clr_f.g = ft_atoi(&info->file[i]);
		if (type == 'b')
			info->clr_f.b = ft_atoi(&info->file[i]);
	}
	else
		info->clr_f.status = 0;
	return (i);
}

int	get_clr_f(t_all_info *info)
{
	int i;

	i = -1;
	info->clr_f.status = 0;
	while (info->file[++i])
	{
		if ((info->file[i] == 'F' && info->file[i + 1] == ' ')
		&& (i == 0 || info->file[i - 1] == '\n'))
		{
			info->clr_f.status = 1;
			i++;
			i = set_color_f(info, i, 'r');
			i = set_color_f(info, i, 'g');
			i = set_color_f(info, i, 'b');
			if (info->clr_f.r + info->clr_f.g + info->clr_f.b > 766)
				info->clr_f.status = 0;
			while (ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] != '\n')
				info->clr_f.status = 0;
		}
	}
	info->clr_f.value = 65536 * info->clr_f.r + 256 *
	info->clr_f.g + info->clr_f.b;
	return (0);
}

int	set_color_c(t_all_info *info, int i, char type)
{
	int color;

	while (type == 'r' && info->file[i] == ' ')
		i++;
	while (info->file[i] == '0')
		i++;
	if (type != 'r')
	{
		while (ft_isdigit(info->file[i]))
			i++;
		if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
			i++;
	}
	if (ft_isdigit(info->file[i]) && check_color(info->file + i))
	{
		if (type == 'r')
			info->clr_c.r = ft_atoi(&info->file[i]);
		if (type == 'g')
			info->clr_c.g = ft_atoi(&info->file[i]);
		if (type == 'b')
			info->clr_c.b = ft_atoi(&info->file[i]);
	}
	else
		info->clr_c.status = 0;
	return (i);
}

int	get_clr_c(t_all_info *info)
{
	int i;

	i = -1;
	info->clr_c.status = 0;
	while (info->file[++i])
	{
		if ((info->file[i] == 'C' && info->file[i + 1] == ' ') &&
		(i == 0 || info->file[i - 1] == '\n'))
		{
			i++;
			info->clr_c.status = 1;
			i = set_color_c(info, i, 'r');
			i = set_color_c(info, i, 'g');
			i = set_color_c(info, i, 'b');
			if (info->clr_c.r + info->clr_c.g + info->clr_c.b > 766)
				info->clr_c.status = 0;
			while (ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] != '\n')
				info->clr_c.status = 0;
		}
	}
	info->clr_c.value = 65536 * info->clr_c.r + 256 *
	info->clr_c.g + info->clr_c.b;
	return (0);
}
