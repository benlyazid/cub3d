/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:37:30 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/06 12:37:13 by kbenlyaz         ###   ########.fr       */
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
	i = -1;
	if (NULL == (ret = malloc(sizeof(char) * (ls1 + ls2 + 1))))
		return (0);
	while (++i < ls1)
		*(ret + i) = *(s1 + i);
	i = -1;
	while (++i < ls2)
		*(ret + i + ls1) = *(s2 + i);
	*(ret + i + ls1) = '\0';
	free(s1);
	return (ret);
}

int		check_line_spaces(char *maps)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (maps[i])
	{
		if (i == 0 || maps[i] == '\n')
		{
			i++;
			while (maps[i] && maps[i] == ' ')
				i++;
			if (i != 0 && maps[i] && maps[i] == '\n' && maps[i - 1] == ' ')
				return (0);
		}
		i++;
	}
	return (1);
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
	return (res);
}

int		is_player(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int		not_supported(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S' || c == '\n')
		return (1);
	if (c == '1' || c == '0' || c == '2' || c == '-' || c == '*')
		return (1);
	return (-1);
}
