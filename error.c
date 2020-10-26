/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:34:17 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 13:05:49 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_error(int er, t_all_info *info)
{
	//check free
	//norm
	// check 00000 in the bigen of the resolution
	//makefile
	// remove inusid function and files
	// correct steps
	char *error = ft_strdup("error\n");
	ft_putstr_fd(error, 1);
	free(error);
	if (er == 70)
		error = ft_strdup("Error in Resolution");
	else if (er == 60)
		error = ft_strdup("Error in texteur path");
	else if (er == 50)
		error = ft_strdup("Error in sprite path");
	else if (er == 40)
		error = ft_strdup("Error in color format");
	else if (er == 80)
		error = ft_strdup("Error in the maps");
	else if (er == 100)
		error = ft_strdup("Error in the file");
	else if (er == 90)
		error = ft_strdup("Error in the file data");
	else if (er == 30)
		error = ft_strdup("arg not supported");
	if (er <= 80)
		free(info->maps);
	if (er <= 70)
		free(info->mp);
	if (er <= 90)
		free(info->file);
	free(info);
	ft_putstr_fd(error, 1);
	free(error);
}
