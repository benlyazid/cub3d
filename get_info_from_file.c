/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:31:19 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/03 13:44:40 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*join(char  *s1, char  *s2)
{
	char	*ret;
	int		ls1;
	int		ls2;
	int		i;

	if ((s1 == 0) || (s2 == 0))
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	i = 0;
	if (NULL == (ret = malloc(sizeof(char) * (ls1 + ls2 + 1))))
		return (0);
	while (i < ls1)
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (i < ls2)
	{
		*(ret + i + ls1) = *(s2 + i);
		i++;
	}
	*(ret + i + ls1) = '\0';
	free(s1);
	return (ret);
}

char		*read_file(int fd)
{
	char	*file;
	char	*get;
	file = NULL;
	get = malloc(sizeof(char) + 1);

	while (read(fd, get, 1))
	{
		get[1] = '\0';
		if (file == NULL)
		{
			file = ft_strdup(get);
		}
		else
		{
			file = join(file, get);
		}
		
	}
	free(get);
	close(fd);
	return (file);
	
}

void	get_all_info(char* arg, t_all_info *info)
{
	info->width = get_width(info->file);
	info->height = get_height(info->file);
	info->size = 64;
	get_mp(info);
	get_color_flor(info);
	get_color_coll(info);
	info->color_flor.value = 65536 * info->color_flor.r + 256 * info->color_flor.g + info->color_flor.b;
	info->color_coll.value = 65536 * info->color_coll.r + 256 * info->color_coll.g + info->color_coll.b;
}

int get_color_flor(t_all_info *info)
{
	int i;

	i = -1;
	info->color_flor.status = 0;
	while(info->file[++i])
	{
		if((info->file[i] == 'F' && info->file[i + 1] == ' ') && (i == 0 || info->file[i - 1] == '\n'))
		{
			info->color_flor.status = 1;
			i++;
			while (info->file[i] == ' ')
				i++;
			if (ft_isdigit(info->file[i]))
				info->color_flor.r = ft_atoi(&info->file[i]);
			else
				info->color_flor.status = 0;
			while(ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
					info->color_flor.g = ft_atoi(&info->file[++i]);
			else
				info->color_flor.status = 0;
			while(ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
				info->color_flor.b = ft_atoi(&info->file[++i]);
			else
				info->color_flor.status = 0;
			if(info->color_flor.r + info->color_flor.g + info->color_flor.b > 766)
				info->color_flor.status = 0;
			while(ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] != '\n')
				info->color_flor.status = 0;
		}
	}
	return 0;
}


int get_color_coll(t_all_info *info)
{
	int i;

	i = -1;
	info->color_coll.status = 0;

	while(info->file[++i])
	{
		
		if((info->file[i] == 'C' && info->file[i + 1] == ' ') && (i == 0 || info->file[i - 1] == '\n'))
		{
			info->color_coll.status = 1;
			i++;
			while (info->file[i] == ' ')
				i++;
			if (ft_isdigit(info->file[i]))
				info->color_coll.r = ft_atoi(&info->file[i]);
			else
				info->color_coll.status = 0;
			while(ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
					info->color_coll.g = ft_atoi(&info->file[++i]);
			else
				info->color_coll.status = 0;
			while(ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] == ',' && ft_isdigit(info->file[i + 1]))
				info->color_coll.b = ft_atoi(&info->file[++i]);
			else
				info->color_coll.status = 0;
			if(info->color_coll.r + info->color_coll.g + info->color_coll.b > 766)
				info->color_coll.status = 0;
			while(ft_isdigit(info->file[i]))
				i++;
			if (info->file[i] != '\n')
				info->color_coll.status = 0;
		}
	}
	return 0;
}


int		get_line_end(char *maps, int line)
{
	int res;
	int y;

	res = 0;
	y = 0;
	while (maps[res] && y <= line)
	{
		if (maps[res] == '\n')
			y++;
		res++;
		
	}
	return res;
}

char *repiare_the_maps(char *maps)
{
	int i;
	int w;
	int h;
	char	*tst;

	i = 0;
	w = get_max_w(maps) + 1; //this 1 is for \n
	h = get_max_h(maps);
	tst = malloc(sizeof(char) * (w) * h );
	int last = 0;
	while (maps[i])
	{

		if (maps[i] != '\n')
		{
			if (maps[i] == ' ')
				{
					tst[last] = '*';
				}
			else
			{	
				tst[last] = maps[i];
			}
			last++;
		}
		if (maps[i] == '\n')
		{
			while ((last + 1)% (w))
			{
				tst[last] = '-';
				last++;
			}
			tst[last] = '\n';
			last++;	
		}
		i++;

	}
	while ((last + 1)% (w))
	{
		tst[last] = '-';
		last++;
	}
	tst[last] = '\0';
	free(maps);
	return tst;
}


int is_player(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return 1;
	return 0;
	
}


int check_border(char *maps, t_all_info *info)
{
	//Check for * and - in the bigen
	int i = 0;
	int j  = 0;
	while (maps[i])
	{
		if (maps[i] == '\n')
			j++;
		if (maps[i] == '0' && j == 0)
			return -10;
		//if (maps[i] == '\n' && maps[i + 1] && maps[i + 1] != '1')
		if (maps[i] == '\n' && maps[i + 1] && (maps[i + 1] == '0' || is_player(maps[i + 1])|| maps[i + 1] == '2'))
			return -200;
		if (maps[i] == '\n' && maps[i - 1] && (maps[i - 1] == '0' || is_player(maps[i - 1]) || maps[i - 1] == '2'))
			return -3;
		if (j + 1 == info->height_number  && (maps[i] == '0' || is_player(maps[i]) || maps[i] == '2'))
			return -4;
		i++;
	}
	
	return 1;
}


int not_supported(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S' || c == '\n')
		return 1;
	if (c == '1' || c == '0' || c == '2' || c == '-' || c == '*')
		return 1;
	return -1;
	
}



int reset_the_maps(t_all_info *info)
{
	int i = 0;
	while (info->maps[i])
	{
		if (info->maps[i] == '-' || info->maps[i] == '*')
		{
			info->maps[i] = '1';
		}
		i++;
	}
	return 1;
}






