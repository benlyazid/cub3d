/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:31:19 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/05 08:50:24 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*read_file(int fd)
{
	char	*file;
	char	*get;

	file = NULL;
	get = malloc(sizeof(char) + 1);
	while (read(fd, get, 1))
	{
		get[1] = '\0';
		if (file == NULL)
		{
			file = ft_strdup(get);
		}
		else
		{
			file = join(file, get);
		}
	}
	free(get);
	close(fd);
	return (file);
}

void		get_all_info(char *arg, t_all_info *info)
{
	info->width = get_width(info->file);
	info->height = get_height(info->file);
	info->size = 64;
	get_mp(info);
	get_clr_f(info);
	get_clr_c(info);
}

char		*repiare_the_maps(char *maps)
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

int			check_border(char *maps, t_all_info *info)
{
	int i;
	int j;

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

int			reset_the_maps(t_all_info *info)
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
