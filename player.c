/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:53:57 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/06 10:08:15 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_funct(t_all_info *info)
{
	free(info->mp);
	free(info);
	exit(0);
}

int	move_player(t_all_info *info)
{
	mlx_hook(info->win_ptr, 17, 0, exit_funct, info);
	mlx_hook(info->win_ptr, 2, 0, effect_move, info);
	return (0);
}
