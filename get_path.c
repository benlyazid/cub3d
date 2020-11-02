/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:10:52 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/22 08:30:10 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_no_texteur_path(t_all_info *info)
{
	int		i;
	int		j;
	char	*path;

	path = NULL;
	i = 0;
	while (info->file[i])
	{
		if (info->file[i] == 'N' && info->file[i + 1] == 'O' &&
		(i == 0 || info->file[i - 1] == '\n'))
		{
			i += 2;
			if (info->file[i] != ' ')
				return (path);
			while (info->file[i] == ' ')
				i++;
			j = i;
			while (info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			return (path);
		}
		i++;
	}
	return (path);
}

char	*get_so_texteur_path(t_all_info *info)
{
	int		i;
	int		j;
	char	*path;

	path = NULL;
	i = 0;
	while (info->file[i])
	{
		if (info->file[i] == 'S' && info->file[i + 1] == 'O' &&
		(i == 0 || info->file[i - 1] == '\n'))
		{
			i += 2;
			if (info->file[i] != ' ')
				return (path);
			while (info->file[i] == ' ')
				i++;
			j = i;
			while (info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			return (path);
		}
		i++;
	}
	return (path);
}

char	*get_we_texteur_path(t_all_info *info)
{
	int		i;
	char	*path;
	int		j;

	i = 0;
	path = NULL;
	while (info->file[i])
	{
		if (info->file[i] == 'W' && info->file[i + 1] == 'E' &&
		(i == 0 || info->file[i - 1] == '\n'))
		{
			i += 2;
			if (info->file[i] != ' ')
				return (NULL);
			while (info->file[i] == ' ')
				i++;
			j = i;
			while (info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*get_ea_texteur_path(t_all_info *info)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	path = NULL;
	while (info->file[i])
	{
		if (info->file[i] == 'E' && info->file[i + 1] == 'A' &&
		(i == 0 || info->file[i - 1] == '\n'))
		{
			i += 2;
			if (info->file[i] != ' ')
				return (path);
			while (info->file[i] == ' ')
				i++;
			j = i;
			while (info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			return (path);
		}
		i++;
	}
	return (path);
}
