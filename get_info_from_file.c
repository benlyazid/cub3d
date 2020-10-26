/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:31:19 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/26 17:03:25 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*join(char *s1, char *s2)
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
	i = -1;
	while (++i < ls2)
	{
		*(ret + i + ls1) = *(s2 + i);
	}
	*(ret + i + ls1) = '\0';
	free(s1);
	return (ret);
}

int		check_file_if_is_dot_cub(char *name)
{
	int i;
	int l;

	l = ft_strlen(name);
	i = l - 1;
	if (l < 3)
		return (-1);
	if (name[i] != 'b')
		return (-1);
	if (name[i - 1] != 'u')
		return (-1);
	if (name[i - 2] != 'c')
		return (-1);
	if (name[i - 3] != '.')
		return (-1);
	return (1);
}

char	*read_file(int fd)
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

void	get_all_info(char *arg, t_all_info *info)
{
	info->width = get_width(info->file);
	info->height = get_height(info->file);
	info->size = 40;
	get_mp(info);
	get_color_flor(info);
	get_color_coll(info);
	info->color_flor.value = 65536 * info->color_flor.r + 256 *
	info->color_flor.g + info->color_flor.b;
	info->color_coll.value = 65536 * info->color_coll.r + 256 *
	info->color_coll.g + info->color_coll.b;
}

int		file_suport(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S' || c == '\n')
		return (1);
	if (c == '1' || c == '0' || c == '2' || c == ' ')
		return (1);
	return (-1);
}
