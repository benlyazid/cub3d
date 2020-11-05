/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_maps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:41:25 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/05 14:15:53 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check(int i, t_all_info *info, int j)
{
	if (info->maps[i] == '-' || info->maps[i] == '*')
	{
		if (i > 0 && (info->maps[i - 1] == '0' || info->maps[i - 1] == '2' ||
		is_player(info->maps[i - 1])))
			return (0);
		if (info->maps[i + 1] && (info->maps[i + 1] == '0' ||
		info->maps[i + 1] == '2' || is_player(info->maps[i + 1])))
			return (0);
		if (j > 0 && (info->maps[i - (int)info->width_number - 1] == '0'
		|| is_player(info->maps[i - (int)info->width_number - 1])))
			return (0);
		if (j > 0 && info->maps[i - (int)info->width_number - 1] == '2')
			return (0);
		if (j < info->height_number - 1 && info->maps[i +
		(int)info->width_number + 1] == '0')
			return (0);
		if (j < info->height_number - 1 && info->maps[i +
		(int)info->width_number + 1] == '2')
			return (0);
	}
	return (1);
}

int		check_arrownd(char *maps, t_all_info *info)
{
	int i;
	int j;
	int k;
	int player;

	i = -1;
	j = 0;
	player = 0;
	while (maps[++i])
	{
		if (not_supported(maps[i]) == -1 || (is_player(maps[i]) == 1
		&& ++player > 1))
			return (-100);
		if (maps[i] == '\n')
			j++;
		if (!check(i, info, j))
			return (0);
		k = 0;
		while (maps[i + k] && maps[i] == '-' && maps[i + k] == '-')
			k++;
		if (k == info->width_number || (i > 0 && maps[i] == '\n'
		&& maps[i - 1] == '\n'))
			return (-50);
	}
	return (player) != 0 ? 1 : -1;
}

int		check_the_out(char *maps, t_all_info *info)
{
	int res;

	res = check_border(info->maps, info);
	if (res != 1)
		return (res);
	res = check_arrownd(maps, info);
	if (res != 1)
		return (res);
	return (1);
}

int		get_the_begin_of_the_map(char *file)
{
	int i;
	int result;

	i = -1;
	while (file[++i])
	{
		if ((file[i] == '1' || file[i] == ' ') && file[i - 1] == '\n')
		{
			result = i;
			while (file[i] != '\n')
				i++;
			if (file[i - 1] == '1')
				return (result);
		}
	}
	return (-1);
}

int		check_the_maps(t_all_info *info)
{
	int		i;
	char	*maps;
	int		res;

	i = get_the_begin_of_the_map(info->file);
	if (i == -1)
		return (-1);
	maps = ft_strdup(info->file + i);
	if (!check_line_spaces(maps))
		return (-1);
	info->maps = repiare_the_maps(maps);
	info->height_number = get_max_h(info->maps);
	info->width_number = get_max_w(info->maps);
	res = check_the_out(info->maps, info);
	if (res != 1)
		return (-1);
	return (0);
}
