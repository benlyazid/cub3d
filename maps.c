/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:39:06 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/04 10:36:33 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		*get_mp(t_all_info *info)
{
	int	*mp;
	int	i;
	int	j;
	int	number_of_new_line;

	number_of_new_line = get_max_h(info->maps);
	info->mp = (int*)malloc(sizeof(int) * (ft_strlen(info->maps)
	- number_of_new_line + 1));
	i = 0;
	j = 0;
	while (info->maps[i])
	{
		if (info->maps[i] == '1')
			info->mp[j] = 1;
		if (info->maps[i] == '2')
			info->mp[j] = 2;
		if (info->maps[i] == '0' || info->maps[i] == 'S' || info->maps[i] == 'N'
		|| info->maps[i] == 'E' || info->maps[i] == 'W')
			info->mp[j] = 0;
		if (info->maps[i] != ' ' && info->maps[i] != '\n')
			j++;
		i++;
	}
	return (0);
}

char	*get_maps(char *file)
{
	int		i;
	char	*maps;

	i = 0;
	maps = NULL;
	while (file[i])
	{
		if (file[i] == '\n')
			if (file[i + 1] == '1')
				return (ft_strdup(file + i + 1));
		i++;
	}
	return (0);
}

int		get_max_w(char *maps)
{
	int res;
	int i;
	int j;
	int number;

	i = -1;
	res = 0;
	number = 0;
	while (maps[++i])
	{
		j = 0;
		while (maps[i + j] && maps[i + j] != '\n')
		{
			j++;
		}
		if (res < j)
			res = j;
	}
	return (res);
}

int		get_max_h(char *maps)
{
	int res;
	int i;

	i = -1;
	res = 1;
	while (maps[++i])
	{
		if (maps[i] == '\n')
			res++;
	}
	return (res);
}

int		get_data_from_maps(int x, int y, t_all_info *info)
{
	int index_x;
	int	index_y;
	int index;

	index_x = ((int)x) * (int)info->width_number / (int)info->width;
	index_y = (int)y * (int)info->height_number / (int)info->height;
	index = (index_y * (int)info->width_number + index_x);
	return (info->mp[index]);
}
