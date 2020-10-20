/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:34:45 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/21 06:07:14 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sizehh(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	if (sizehh((char*)to_find) == 0)
		return ((char*)str);
	while ((i < sizehh((char*)str) - sizehh((char*)((to_find)) + 1)
	&& i < (int)n))
	{
		j = 0;
		while (j < sizehh((char*)to_find))
		{
			if (str[i + j] != to_find[j])
				break ;
			j++;
		}
		if (j == sizehh((char*)to_find) && (i + j <= (int)n))
		{
			p = ((char*)(str + i));
			return (p);
		}
		i++;
	}
	return (0);
}
