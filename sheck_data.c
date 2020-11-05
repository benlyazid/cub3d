/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sheck_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:52:50 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/05 14:11:44 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_file_ext(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[--len] != 'b')
		return (0);
	if (str[--len] != 'u')
		return (0);
	if (str[--len] != 'c')
		return (0);
	if (str[--len] != '.')
		return (0);
	return (1);
}

int		check_xpm_ext(char *path)
{
	int	l;

	l = ft_strlen(path);
	if (l < 4)
		return (-1);
	if (path[l - 1] == 'm' && path[l - 2] == 'p'
	&& path[l - 3] == 'x' && path[l - 4] == '.')
		return (1);
	return (-1);
}
