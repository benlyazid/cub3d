/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:28:19 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/05 13:34:00 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_no_texteur_from_file(t_all_info *info)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	path = get_no_texteur_path(info);
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)
		return (-1);
	close(i);
	info->texteur_image_no = mlx_xpm_file_to_image(info->mlx_ptr, path,
	(int*)&info->img_wno, (int*)&info->img_hno);
	if (check_xpm_ext(path) == -1)
		return (-1);
	free(path);
	if (info->texteur_image_no == NULL)
		return (-1);
	info->data_texteur_no = (int*)mlx_get_data_addr(info->texteur_image_no,
	&i, &j, &k);
	free(info->texteur_image_no);
	return (1);
}

int		get_so_texteur_from_file(t_all_info *info)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	path = get_so_texteur_path(info);
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)
		return (-1);
	close(i);
	info->texteur_image_so = mlx_xpm_file_to_image(info->mlx_ptr, path,
	(int*)&info->img_wso, (int*)&info->img_hso);
	free(path);
	if (check_xpm_ext(path) == -1)
		return (-1);
	if (info->texteur_image_so == NULL)
		return (-1);
	info->data_texteur_so = (int*)mlx_get_data_addr(
		info->texteur_image_so, &i, &j, &k);
	return (1);
}

int		get_we_texteur_from_file(t_all_info *info)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	i = 0;
	path = get_we_texteur_path(info);
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)
		return (-1);
	close(i);
	info->texteur_image_we = (mlx_xpm_file_to_image(info->mlx_ptr, path,
	(int*)&info->img_wwe, (int*)&info->img_hwe));
	if (check_xpm_ext(path) == -1)
		return (-1);
	free(path);
	if (!info->texteur_image_we)
		return (-1);
	info->data_texteur_we = (int*)mlx_get_data_addr(
		info->texteur_image_we, &i, &j, &k);
	free(info->texteur_image_we);
	return (1);
}

int		get_ea_texteur_from_file(t_all_info *info)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	path = get_ea_texteur_path(info);
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)
		return (-1);
	close(i);
	info->texteur_image_ea = mlx_xpm_file_to_image(info->mlx_ptr, path,
	(int*)&info->img_wea, (int*)&info->img_hea);
	if (check_xpm_ext(path) == -1)
		return (-1);
	free(path);
	if (info->texteur_image_ea == NULL)
		return (-1);
	info->data_texteur_ea = (int*)mlx_get_data_addr(
		info->texteur_image_ea, &i, &j, &k);
	free(info->texteur_image_ea);
	return (1);
}
