/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:48:29 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/18 20:38:19 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

int		size(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		ls1;
	int		ls2;
	int		i;

	if ((s1 == 0) || (s2 == 0))
		return (0);
	ls1 = size((char*)s1);
	ls2 = size((char*)s2);
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
	return (ret);
}
