/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:35:25 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 16:36:22 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*repiare_the_maps(char *maps)
{
	int		i;
	char	*tst;
	int		last;

	i = -1;
	tst = malloc(sizeof(char) * (get_max_w(maps) + 1) * get_max_h(maps));
	last = 0;
	while (maps[++i])
	{
		if (maps[i] != '\n')
			tst[last++] = maps[i] == ' ' ? '*' : maps[i];
		if (maps[i] == '\n')
		{
			while ((last + 1) % (get_max_w(maps) + 1))
				tst[last++] = '-';
			tst[last++] = '\n';
		}
	}
	while ((last + 1) % (get_max_w(maps) + 1))
		tst[last++] = '-';
	tst[last] = '\0';
	free(maps);
	return (tst);
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
			return (i);
			result = i;
			while (file[i] != '\n')
				i++;
			if (file[i - 1] == '1')
				return (result);
		}
	}
	return (-1);
}

int		is_player(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int		check_border(char *maps, t_all_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (maps[i])
	{
		if (maps[i] == '\n')
			j++;
		if (maps[i] == '0' && j == 0)
			return (-10);
		if (maps[i] == '\n' && maps[i + 1] && (maps[i + 1] == '0' ||
		is_player(maps[i + 1]) || maps[i + 1] == '2'))
			return (-200);
		if (maps[i] == '\n' && maps[i - 1] && (maps[i - 1] == '0' ||
		is_player(maps[i - 1]) || maps[i - 1] == '2'))
			return (-3);
		if (j + 1 == info->height_number && (maps[i] == '0' ||
		is_player(maps[i]) || maps[i] == '2'))
			return (-4);
		i++;
	}
	return (1);
}

int		suport(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S' || c == '\n')
		return (1);
	if (c == '1' || c == '0' || c == '2' || c == '-' || c == '*')
		return (1);
	return (-1);
}
