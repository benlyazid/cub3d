/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:43:47 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/06 11:13:41 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				check_save(t_all_info *info, char *argv[], int argc)
{
	int		i;
	char	*arg;

	arg = argv[2];
	if (argc == 2)
		return (0);
	if (argc > 3)
	{
		set_error(80, info);
		return (-1);
	}
	if (argc == 3)
	{
		if (arg[0] == '-' && arg[1] == '-' && arg[2] == 's'
		&& arg[3] == 'a' && arg[4] == 'v' && arg[5] == 'e')
			save_bmp(info);
		else
		{
			set_error(80, info);
			return (-1);
		}
	}
	return (1);
}
