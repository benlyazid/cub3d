/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:45:43 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/15 20:05:33 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*rst;

	i = 0;
	while (*(src + i))
		i++;
	if (NULL == (rst = malloc(sizeof(char) * (i + 1))))
		return (0);
	j = 0;
	while (j < i)
	{
		*(rst + j) = *(src + j);
		j++;
	}
	*(rst + j) = *(src + j);
	return (rst);
}
