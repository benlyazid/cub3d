/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:31:19 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/01/14 11:08:18 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int				*get_mp(t_all_info *info)
{
	int	*mp;
	int	i;
	int	j;

	mp = malloc(sizeof(int) *  (ft_strlen(info->maps) / 2 + 1));
	i = 0;
	j = 0;
	while (info->maps[i])
	{
		if (info->maps[i] != ' ' && info->maps[i] != '\n')
		{
			mp[j] = (info->maps[i] == '1') ? 1 : 0;
			j++;
		}		 
		i++ ;
	}
	return (mp);
}

char			*get_maps(char *file)
{
	int 	i;
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

	
	return(0);
}

char			*read_file(int fd)
{
	char	*file;
	char	*get;

	get = malloc(sizeof(char) + 1);
	file = NULL;
	while (read(fd, get, 1))
	{
		get[1] = '\0';
		if (!file)
			file = ft_strdup(get);
		else
			file = ft_strjoin(file, get);
	}
	return (file);
}

int				get_width(char *file)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == 'R')
			return (ft_atoi(file + i + 1));
		i++;
	}
	return (result);

}

int				get_height(char *file)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == 'R')
			i += 2;
		while (ft_isdigit(file[i]))
			i++;
		return (ft_atoi(file + i + 1));
		i++;
	}
	return (result);
}

void	get_all_info(char* arg, t_all_info *info)
{
	//t_all_info	*info;
	int			fd;

	//info = malloc(sizeof(t_all_info));
	fd = open(arg, O_RDONLY);
	info->file = read_file(fd);
	info->maps = get_maps(info->file);
	info->width = get_width(info->file);
	info->height = get_height(info->file);
	info->width_number = number_of_width(info->maps); 
	info->height_number = number_of_height(info->maps);
	info->height_size = size_of_height(info->height_number, info->height);
	info->width_size = size_of_widht(info->width_number, info->width);
	info->mp = get_mp(info);
}