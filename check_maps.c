/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:30:48 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 16:35:06 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_is_valid(t_all_info *info, int i, int j, char *maps)
{
	if (maps[i] == '-' || maps[i] == '*')
	{
		if (i > 0 && (maps[i - 1] == '0' || maps[i - 1] == '2'
		|| is_player(maps[i - 1])))
			return (-1);
		if (maps[i + 1] && (maps[i + 1] == '0' || maps[i + 1] == '2'
		|| is_player(maps[i + 1])))
			return (-1);
		if (j > 0 && (maps[i - (int)info->width_number - 1] == '0'
		|| is_player(maps[i - (int)info->width_number - 1])))
			return (-30);
		if (j > 0 && maps[i - (int)info->width_number - 1] == '2')
			return (-30);
		if (j < info->height_number - 1 && info->maps[i +
		(int)info->width_number + 1] == '0')
			return (-1);
		if (j < info->height_number - 1 && info->maps[i +
		(int)info->width_number + 1] == '2')
			return (-1);
	}
	return (1);
}

int	check_arrownd(char *maps, t_all_info *info)
{
	int	i;
	int	j;
	int	k;
	int ply;

	ply = 0;
	i = -1;
	j = 0;
	while (maps[++i])
	{
		if (suport(maps[i]) == -1 || (is_player(maps[i]) == 1 && ++ply > 1))
			return (-100);
		if (maps[i] == '\n')
			j++;
		if (check_is_valid(info, i, j, maps) == -1)
			return (-1);
		k = 0;
		while (maps[i + k] && maps[i] == '-' && maps[i + k] == '-')
			k++;
		if (k == info->width_number)
			return (-50);
		if (i > 0 && maps[i] == '\n' && maps[i - 1] == '\n')
			return (-500);
	}
	return (ply) != 0 ? (1) : (-1);
}

int	check_the_out(char *maps, t_all_info *info)
{
	int	res;

	res = check_border(info->maps, info);
	if (res != 1)
		return (res);
	res = check_arrownd(maps, info);
	if (res != 1)
		return (res);
	return (1);
}

int	reset_the_maps(t_all_info *info)
{
	int i;

	i = 0;
	while (info->maps[i])
	{
		if (info->maps[i] == '-' || info->maps[i] == '*')
		{
			info->maps[i] = '1';
		}
		i++;
	}
	return (1);
}

int	check_the_maps(t_all_info *info)
{
	int		i;
	char	*maps;
	int		res;

	i = get_the_begin_of_the_map(info->file);
	if (i == -1)
		return (-1);
	maps = ft_strdup(info->file + i);
	info->maps = repiare_the_maps(maps);
	info->height_number = get_max_h(info->maps);
	info->width_number = get_max_w(info->maps);
	res = check_the_out(info->maps, info);
	if (res != 1)
		return (-1);
	return (0);
}
