/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:45:30 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/23 06:41:45 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	if (NULL == (t = (t_list*)malloc(sizeof(t_list))))
		return (0);
	t->content = content;
	t->next = NULL;
	return (t);
}
