/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:32:36 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/10 21:45:20 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t n, size_t t)
{
	char	*tab;
	int		i;

	if (NULL == (tab = malloc(n * t)))
		return ((void*)tab);
	i = 0;
	while (i < (int)(n * t))
	{
		tab[i] = 0;
		i++;
	}
	return ((void*)tab);
}
