/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 08:16:41 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/05 11:45:50 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	initailize_variable(t_all_info *info)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = info->width;
	height = info->height;
	info->bitcount = 24;
	info->w_bt = ((width * info->bitcount + 31) / 32) * 4;
	info->imagesize = info->w_bt * height;
	info->bisize = 40;
	info->bfoffbits = 54;
	info->filesize = 54 + info->imagesize;
	info->biplanes = 1;
	info->header = malloc(54 + 1);
	info->buf = malloc(info->imagesize + 1);
	while (i < 55)
	{
		info->header[i] = 0;
		i++;
	}
	return (1);
}

int	mem_copy_header(t_all_info *info)
{
	int	width;
	int	height;

	width = info->width;
	height = info->height;
	ft_memcpy(info->header, "BM", 2);
	ft_memcpy(info->header + 2, &info->filesize, 4);
	ft_memcpy(info->header + 10, &info->bfoffbits, 4);
	ft_memcpy(info->header + 14, &info->bisize, 4);
	ft_memcpy(info->header + 18, &width, 4);
	ft_memcpy(info->header + 22, &height, 4);
	ft_memcpy(info->header + 26, &info->biplanes, 2);
	ft_memcpy(info->header + 28, &info->bitcount, 2);
	ft_memcpy(info->header + 34, &info->imagesize, 4);
	info->header[54] = '\0';
	return (1);
}

int	save_in_file(t_all_info *info)
{
	int	fd;

	fd = open("save.bmp", O_WRONLY | O_CREAT, 0644);
	write(fd, info->header, 54);
	write(fd, info->buf, info->imagesize);
	close(fd);
	free(info->buf);
	free(info->header);
	free(info->mp);
	free(info->maps);
	free(info->file);
	free(info);
	return (1);
}

int	save_bmp(t_all_info *info)
{
	int	width;
	int	height;
	int	row;
	int	col;

	row = -1;
	initailize_variable(info);
	mem_copy_header(info);
	width = info->width;
	height = info->height;
	while (++row < height)
	{
		col = 0;
		while (col < width)
		{
			info->uc = info->data_3d[(height - row) * width + col];
			info->buf[row * info->w_bt + col * 3 + 0] = info->uc % 256;
			info->buf[row * info->w_bt + col * 3 + 1] = (info->uc / 256) % 256;
			info->buf[row * info->w_bt + col * 3 + 2] = (info->uc / 65536) %
			256;
			col++;
		}
	}
	save_in_file(info);
	return (1);
}
