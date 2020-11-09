/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:56:57 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/09 13:18:55 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_number(char *str)
{
	int num;
	int	i;
	int	j;

	num = 0;
	i = 0;
	while (str[i] == '0')
		i++;
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (i - j > 9)
		return (40000);
	return (ft_atoi(str + j));
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
			return (i);
		}
		i++;
	}
	return (0);
}

int	get_height(char *file)
{
	int i;
	int result;

	i = 0;
	result = 0;
	i = jump_width(file);
	result = get_number(file + i);
	if (result > 1440)
		result = 1440;
	while (file[i] != '\n')
	{
		if (!ft_isdigit(file[i]))
			return (0);
		i++;
	}
	return (result);
}

int	get_width(char *file)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == 'R' && file + i + 1 && file[i + 1] == ' '
		&& (i == 0 || file[i - 1] == '\n'))
		{
			i++;
			while (file[i] == ' ')
				i++;
			result = get_number(file + i);
			if (result > 2560)
				result = 2560;
		}
		i++;
	}
	return (result);
}
