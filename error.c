/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:07:18 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/05 13:25:02 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_message(char *error, int type_of_error, t_all_info *info)
{
	ft_putstr_fd(error, 1);
	if (type_of_error > 10)
		free(info->file);
	if (type_of_error > 20)
		free(info->maps);
	if (type_of_error > 30)
		free(info->mp);
	free(error);
	free(info);
}

void	set_error(int type_of_error, t_all_info *info)
{
	char	*error;

	error = ft_strdup("ERROR\n");
	ft_putstr_fd(error, 1);
	free(error);
	if (type_of_error == 40)
		error = ft_strdup("Error in Resolution");
	else if (type_of_error == 50)
		error = ft_strdup("Error in texteur path");
	else if (type_of_error == 60)
		error = ft_strdup("Error in sprite path");
	else if (type_of_error == 70)
		error = ft_strdup("Error in color format");
	else if (type_of_error == 30)
		error = ft_strdup("Error in the maps");
	else if (type_of_error == 10)
		error = ft_strdup("Error in the file");
	else if (type_of_error == 20)
		error = ft_strdup("Error in the file data");
	else if (type_of_error == 80)
		error = ft_strdup("Error in the arg");
	put_message(error, type_of_error, info);
}

int		check_error(t_all_info *info, char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		set_error(10, info);
		return (-1);
	}
	info->file = read_file(fd);
	if (info->file == NULL || !check_file_ext(argv[1]))
	{
		set_error(20, info);
		return (-1);
	}
	if (check_file(info->file) == -1)
	{
		set_error(20, info);
		return (-1);
	}
	if (check_the_maps(info) == -1)
	{
		set_error(30, info);
		return (-1);
	}
	return (1);
}

int		send_error(int ret, t_all_info *info)
{
	if (ret != 4)
	{
		set_error(50, info);
		return (-1);
	}
	ret += get_sprite_from_file(info);
	if (ret != 5)
	{
		set_error(60, info);
		return (-1);
	}
	if (info->clr_f.status == 0 || info->clr_c.status == 0)
	{
		set_error(70, info);
		return (-1);
	}
	return (1);
}

int		check_error2(t_all_info *info, char *argv[])
{
	int ret;
	int	a;

	ret = 0;
	get_all_info(argv[1], info);
	info->mlx_ptr = mlx_init();
	if (info->height == 0 || info->width == 0)
	{
		set_error(40, info);
		return (-1);
	}
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->width,
	info->height, "mlx");
	info->img_3d = mlx_new_image(info->mlx_ptr, info->width, info->height);
	info->data_3d = (int*)mlx_get_data_addr(info->img_3d, &a, &a, &a);
	ret += get_no_texteur_from_file(info);
	ret += get_ea_texteur_from_file(info);
	ret += get_we_texteur_from_file(info);
	ret += get_so_texteur_from_file(info);
	if (send_error(ret, info) == -1)
		return (-1);
	return (1);
}
