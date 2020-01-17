/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:04 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/01/15 13:58:17 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef	struct	s_all_info
{
	char	*maps;
	char	*file;
	int		*mp;
	float		width;
	float		height;
	float		width_size;
	float		height_size;	
	float		width_number;
	float		height_number;
	void	*mlx_ptr;
	void	*win_ptr;
	float		xp;
	float		yp;
	int		vision;
	float	angle;
	void	*img;
	int		*data;
}				t_all_info;	

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

char			*get_maps(char *maps);
int				get_width(char *file);
int				get_height(char *file);
char			*read_file(int fd);
void			get_all_info(char *arg, t_all_info *info);
int				number_of_width(char *maps);
int				number_of_height(char *maps);
int				size_of_height(int number, int height);
int				size_of_widht(int number, int widht);
int				draw_2d_maps(t_all_info *info);
int				draw_bloc(int x, int y, t_all_info *info);
int				set_player(t_all_info *info);
t_all_info 		*move_player(t_all_info *info);
int				effect_move(int key, t_all_info *info);
int				check_abilitie_to_move(t_all_info *info, int key);
int				set_vision(t_all_info *info);
t_all_info		*rot_view(t_all_info *info);
int				draw_vision(t_all_info *info);
int				draw_image_surface(t_all_info *info);
int				*get_mp(t_all_info *info);
int				draw_image_player(t_all_info *info);
int				remove_player_image(t_all_info *info, int xp, int yp);
int				draw_image_view(t_all_info *info);
int				destrow_image_view(t_all_info *info, int xp, int yp, float angle);
int				effect_key_for_move(t_all_info *info, int key);
int				draw_image_view_angle(t_all_info *info);
int				destrow_image_view_angle(t_all_info *info, int xp, int yp, float angle);
float			calc_destance_to_wall(t_all_info *info);
float			calc_px(t_all_info *info);
int				draw_3d_image(t_all_info *info, int x, float alpha);
int				draw_all_image_3d(t_all_info *info);
void			remove_3d_image(t_all_info *info);
int				get_the_exact_value(t_all_info *info, int x, int y, int i);
int				ray_casting(t_all_info *info);
t_point			ray_casting_x(t_all_info *info);
t_point			ray_casting_y(t_all_info *info);
void			DDA(t_all_info *info, int X1, int Y1, int color);
float			destance(t_all_info *info, int x, int y);
int				rm_all(t_all_info *info);
#endif 
