/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_for_2d_maps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:51:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/16 08:59:11 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	number_of_width(char *maps)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while (maps[i] && maps[i] != '\n')
	{
		if (maps[i] == '1')
			result++;
		i++;
	}
	return (result);
}
int	number_of_height(char *maps)
{
	int	i;
	int result;

	i = 0;
	result = 1;
	while (maps[i])
	{	
		if (maps[i] == '\n')
			result++;
		i++;
	}	
	return (result);
}

int	size_of_widht(int number, int width)
{
	return ((width / number));
}

int	size_of_height(int number, int height)
{
	return ((height / number));
}

