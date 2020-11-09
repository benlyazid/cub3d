/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:24:02 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/09 12:29:59 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_line(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (1);
	if (line[0] == 'S' && line[1] == 'O')
		return (1);
	if (line[0] == 'W' && line[1] == 'E')
		return (1);
	if (line[0] == 'E' && line[1] == 'A')
		return (1);
	if (line[0] == 'S')
		return (1);
	if (line[0] == 'F')
		return (1);
	if (line[0] == 'C')
		return (1);
	if (line[0] == 'R')
		return (1);
	return (10);
}

int		check_file(char *file)
{
	int	i;
	int	info_number;

	info_number = 0;
	i = 0;
	if (!check_for_unsuported_element(file))
	{
		return (-1);
	}
	while (file[i])
	{
		if (file[i] != '\n' && file[i] != ' ' && file[i] != '1'
		&& file[i] != '0' && file[i] != '2')
			info_number += check_line(file + i);
		while (file[i] && file[i] != '\n')
			i++;
		if (info_number > 8)
			return (-1);
		if (!file[i])
			return (1);
		i++;
	}
	return (1);
}

int		check_for_unsuported_element(char *file)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (file[i])
	{
		if ((i == 0 && file[i] == ' ') || (file[i] == '\n'
		&& file[i + 1] == ' '))
		{
			if (file[i] == '\n')
				i++;
			while (file[i] == ' ' || file[i] == '1'
			|| file[i] == '2' || file[i] == '0' || is_player(file[i]))
				i++;
			if (file[i] && file[i] != '\n')
				return (0);
		}
		i++;
	}
	return (1);
}
