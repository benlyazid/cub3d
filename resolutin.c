/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolutin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:37:55 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 16:38:14 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_width_result(char *file, int i, int j)
{
	int result;

	result = 0;
	if (ft_isdigit(file[i]) && j <= 9)
		result = ft_atoi(file + i);
	else if (ft_isdigit(file[i]) && j > 9)
		result = 2560;
	else
		return (0);
	if (result > 2560)
		result = 2560;
	return (result);
}

int	get_width(char *file)
{
	int result;
	int i;
	int	j;

	result = 0;
	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i] == 'R' && (i == 0 || file[i - 1] == '\n'))
		{
			i++;
			while (file[i] == ' ')
				i++;
			while (file[i] == '0')
				i++;
			while (ft_isdigit(file[i + j]))
				j++;
			return (get_width_result(file, i, j));
		}
		i++;
	}
	return (result);
}

int	get_height_result(char *file, int i, int j)
{
	int result;

	result = 0;
	if (ft_isdigit(file[i]) && j <= 9)
		result = ft_atoi(file + i);
	else if (ft_isdigit(file[i]) && j > 9)
		result = 2560;
	else
		return (0);
	if (result > 1440)
		result = 1440;
	return (result);
}

int	jump_width(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == 'R')
		{
			i += 1;
			while (file[i] == ' ')
				i++;
			while (ft_isdigit(file[i]))
				i++;
			while (file[i] == ' ')
				i++;
			while (file[i] == '0')
				i++;
			return (i);
		}
		i++;
	}
	return (-1);
}

int	get_height(char *file)
{
	int i;
	int result;
	int	j;

	i = -1;
	result = 0;
	j = 0;
	i = jump_width(file);
	if (i == -1)
		return (0);
	while (ft_isdigit(file[i + j]))
		j++;
	result = get_height_result(file, i, j);
	i--;
	while (file[++i] != '\n')
		if (!ft_isdigit(file[i]))
			return (0);
	return (result);
}
