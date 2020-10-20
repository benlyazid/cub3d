/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:39:01 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/18 20:27:36 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texteur_value(t_all_info *info, int	z, int type, float projection_wall)
{
	float	x0;
	float	y0;
	int		index_0;

	x0 = 0  * projection_wall * type * z;
	y0  = 0;
	index_0 = 0;

	if (type == 'x')
	{
		//no and su
		if ((int)info->angle % 360 < 360 && (int)info->angle % 360> 180)
		{
			x0 = info->x_wall % (int)info->size;
			x0  = x0 * info->img_wno / info->size;
			y0 = z * info->img_hno / projection_wall;
			index_0 = ((int)y0 * (int)info->img_wno) + (int)x0;
			if(x0 >= 0 && x0 < info->img_wno && y0 >= 0 && y0 < info->img_hno)
				return (info->data_texteur_no[index_0]);
		}
		else
		{
			x0 = info->x_wall % (int)info->size;
			x0  = x0 * info->img_wso / info->size;
			y0 = z * info->img_hso / projection_wall;
			index_0 = ((int)y0 * (int)info->img_wso) + (int)x0;
			if(x0 >= 0 && x0 < info->img_wso && y0 >= 0 && y0 < info->img_hso)
				return (info->data_texteur_so[index_0]);

		}
	}

	else if (type == 'y')
	{
		//we and ea 
		if (abs((int)info->angle % 360) > 90 && abs((int)info->angle % 360) < 270)
		{
			x0 = info->y_wall % (int)info->size;
			x0  = x0 * info->img_wwe / info->size;
			y0 = z * info->img_hwe / projection_wall;
			index_0 = ((int)y0 * (int)info->img_wwe) + (int)x0;
			if(x0 >= 0 && x0 < info->img_wwe && y0 >= 0 && y0 < info->img_hwe)
				return (info->data_texteur_we[index_0]);
		}
		else
		{
			x0 = info->y_wall % (int)info->size;
			x0  = x0 * info->img_wea / info->size;
			y0 = z * info->img_hea / projection_wall;
			index_0 = ((int)y0 * (int)info->img_wea) + (int)x0;
			if(x0 >= 0 && x0 < info->img_wea && y0 >= 0 && y0 < info->img_hea)
				return (info->data_texteur_ea[index_0]);
		}
	}
	return (0);  
}

int get_no_texteur_from_file(t_all_info *info)
{
	int i;
	int j;
	int k;
	char *path;

	path = NULL;
	i = 0;
	while (info->file[i])
	{
		if(info->file[i] == 'N' && info->file[i + 1] == 'O' && ( i == 0 || info->file[i - 1] == '\n'))
		{
			i+= 2;
			if (info->file[i] != ' ')
				return -1;
			while(info->file[i] == ' ')
				i++;
			j = i;
			while(info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			break;
		}
		i++;
	}
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)	
		return -1;
	close(i);

	info->texteur_image_no = mlx_xpm_file_to_image(info->mlx_ptr, path, (int*)&info->img_wno, (int*)&info->img_hno);
	info->data_texteur_no = (int*)mlx_get_data_addr(info->texteur_image_no, &i, &j, &k); 
	free(path);
	free(info->texteur_image_no);
	return 1;
}

int get_so_texteur_from_file(t_all_info *info)
{
	int i;
	int j;
	int k;
	char *path;

	path = NULL;
	i = 0;
	while(info->file[i])
	{
		if(info->file[i] == 'S' && info->file[i + 1] == 'O' && ( i == 0 || info->file[i - 1] == '\n'))
		{
			i+= 2;
			if (info->file[i] != ' ')
				return -1;
			while(info->file[i] == ' ')
				i++;
			j = i;
			while(info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			break;
		}
		i++;
	}

	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)	
		return -1;
	close(i);
	info->texteur_image_so = mlx_xpm_file_to_image(info->mlx_ptr, path, (int*)&info->img_wso, (int*)&info->img_hso);
	info->data_texteur_so = (int*)mlx_get_data_addr(info->texteur_image_so, &i, &j, &k); 
	free(info->texteur_image_so);
	free(path);
	

	return 1;
}

int get_we_texteur_from_file(t_all_info *info)
{
	int i;
	int j;
	int k;
	char *path;

	i = 0;
	path =  NULL;
	while(info->file[i])
	{
		if(info->file[i] == 'W' && info->file[i + 1] == 'E' && ( i == 0 || info->file[i - 1] == '\n'))
		{
			i+= 2;
			if (info->file[i] != ' ')
				return -1;
			while(info->file[i] == ' ')
				i++;
			j = i;
			while(info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			break;
		}
		i++;
	}
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)	
		return -1;
	close(i);

	info->texteur_image_we = mlx_xpm_file_to_image(info->mlx_ptr, path, (int*)&info->img_wwe, (int*)&info->img_hwe);
	info->data_texteur_we = (int*)mlx_get_data_addr(info->texteur_image_we, &i, &j, &k); 
	
	free(info->texteur_image_we);
	free(path);
	return 1;

}

int get_ea_texteur_from_file(t_all_info *info)
{
	int i;
	int j;
	int k;
	char *path;

	i = 0;
	path = NULL;
	while(info->file[i])
	{
		if (info->file[i] == 'E' && info->file[i + 1] == 'A' && ( i == 0 || info->file[i - 1] == '\n'))
		{
			i+= 2;
			if (info->file[i] != ' ')
				return -1;
			while(info->file[i] == ' ')
				i++;
			j = i;
			while(info->file[j] != '\n')
				j++;
			path = ft_substr(info->file, i, j - i);
			break;
		}
		i++;
	}
	i = open(path, O_WRONLY);
	if (path == NULL || i == -1)	
		return -1;
	close(i);
	info->texteur_image_ea = mlx_xpm_file_to_image(info->mlx_ptr, path, (int*)&info->img_wea, (int*)&info->img_hea);
	info->data_texteur_ea = (int*)mlx_get_data_addr(info->texteur_image_ea, &i, &j, &k); 
	free(info->texteur_image_ea);
	free(path);
	return 1;
}


//W : 200




