/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:34:17 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/27 09:43:44 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_error(t_all_info *info, char *error, int er)
{
	if (er <= 80)
		free(info->maps);
	if (er <= 70)
		free(info->mp);
	if (er <= 90)
		free(info->file);
	free(info);
	ft_putstr_fd(error, 1);
	free(error);
	return (1);
}

int	set_error(int er)
{
	char	*error;

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
	return (-1);
}

int	check_file_error(t_all_info *info, char *file)
{
	info->fd = open(file, O_RDONLY);
	if (info->fd == -1)
	{
		set_error(100);
		return (-1);
	}
	info->file = read_file(info->fd);
	if (info->file == NULL)
	{
		set_error(100);
		return (-1);
	}
	if (check_file(info->file) == -1 || check_file_if_is_dot_cub(file) == -1)
	{
		set_error(90);
		return (-1);
	}
	if (check_the_maps(info) == -1)
	{
		set_error(80);
		return (-1);
	}
	return (1);
}

int	check_image_error(t_all_info *info)
{
	int ret;

	ret = 0;
	info->mlx_ptr = mlx_init();
	if (info->height == 0 || info->width == 0)
		return (set_error(70));
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->width,
	info->height, "CUB_3D");
	info->img_3d = mlx_new_image(info->mlx_ptr, info->width,
	info->height);
	info->data_3d = (int*)mlx_get_data_addr(info->img_3d, &info->bits,
	&info->line, &info->c);
	ret += get_no_texteur_from_file(info);
	ret += get_ea_texteur_from_file(info);
	ret += get_we_texteur_from_file(info);
	ret += get_so_texteur_from_file(info);
	if (ret != 4)
		return (set_error(60));
	ret += get_sprite_from_file(info);
	if (ret != 5)
		return (set_error(50));
	if (info->color_flor.status == 0 || info->color_coll.status == 0)
		return (set_error(40));
	return (1);
}

int	check_save_error(t_all_info *info, char *arg, int argc)
{
	if (argc > 2)
	{
		if (check_argv(arg) == -1)
		{
			set_error(30);
			return (-1);
		}
		else
		{
			save_bmp(info);
			free(info->mp);
			free(info->maps);
			free(info->file);
			free(info);
			return (0);
		}
	}
	return (1);
}
