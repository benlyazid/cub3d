/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:24:02 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 12:59:12 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *line)
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

int	check_line_to_end(char *file, int i)
{
	int	j;
	int	wall_number;

	j = 0;
	wall_number = 0;
	if (file[i + j] == ' ')
		while (file[i + j] && file[i + j] != '\n')
		{
			if (file_suport(file[i + j]) == -1)
				return (0);
			if (file[i + j] == '1')
				wall_number++;
			j++;
		}
	if (j && !wall_number)
		return (0);
	return (1);
}

int	check_file(char *file)
{
	int i;
	int info_number;

	info_number = 0;
	i = 0;
	while (file[i])
	{
		if (!check_line_to_end(file, i))
			return (-1);
		if (file[i] != '\n' && file[i] != ' ' && file[i] != '1' &&
		file[i] != '0' && file[i] != '2')
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
