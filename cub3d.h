/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:04 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/21 20:45:19 by kbenlyaz         ###   ########.fr       */
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

typedef struct	s_desst_to_wall
{
	float	destance;
	int		type;
	float	x_wall;
	float	y_wall;
	int		sprite;

}				t_d_wall;

typedef	struct	s_color
{
	int r;
	int g;
	int b;
	int status;
	int value;
}				t_color;

typedef	struct	s_sprite
{
	float			x;
	float			y;
	float			x_center;
	float			y_center;
	float			dest;
	int				visible;
	struct s_sprite	*next;

}				t_sprite;

typedef	struct	s_all_info
{
	t_color		color_coll;
	t_color		color_flor;
	char		*maps;
	char		*file;
	int			*mp;
	int			sprite_alloc;
	float		width;
	float		height;
	float		width_size;
	float		height_size;
	float		width_size_mini;
	float		height_size_mini;
	float		width_number;
	float		height_number;
	void		*mlx_ptr;
	void		*win_ptr;
	float		xp;
	float		yp;
	int			vision;
	float		angle;
	void		*img;
	void		*img_3d;
	int			*data;
	int			*data_3d;
	int			x_wall;
	int			y_wall;
	int			*data_texteur_no;
	void		*texteur_image_no;
	int			img_hno;
	int			img_wno;
	int			*data_texteur_so;
	void		*texteur_image_so;
	int			img_hso;
	int			img_wso;
	int			*data_texteur_we;
	void		*texteur_image_we;
	int			img_hwe;
	int			img_wwe;
	int			*data_texteur_ea;
	void		*texteur_image_ea;
	int			img_hea;
	int			img_wea;
	int			*data_sprite;
	void		*sprite_img;
	float		sprite_h;
	float		sprite_w;
	int			sprite;
	float		projection_sprite;
	float		save_angle;
	float		projection_wall;
	t_sprite	*sprite_struct_all;
	t_sprite	*sprite_struct_start;
	float		size;
	int			tst;
	int			z;
}				t_all_info;

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_equation_of_line
{
	float	m;
	float	b;
	int		is_perpendicular;
}				t_eq_line;

typedef struct	s_intersection_point
{
	float	x;
	float	y;
}				t_entersection_point;

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
int				move_player(t_all_info *info);
int				effect_move(int key, t_all_info *info);
int				check_abilitie_to_move(t_all_info *info, int key);
int				draw_image_surface(t_all_info *info);
int				*get_mp(t_all_info *info);
int				draw_image_player(t_all_info *info);
int				draw_image_view(t_all_info *info);
int				effect_key_for_move(t_all_info *info, int key);
int				draw_image_view_angle(t_all_info *info);
t_d_wall		calc_destance_to_wall(t_all_info *info);
int				draw_3d_image(t_all_info *info, float x, float alpha);
int				draw_all_image_3d(t_all_info *info);
float			ray_casting(t_all_info *info);
t_point			ray_casting_x(t_all_info *info);
t_point			ray_casting_y(t_all_info *info);
void			draw_line(t_all_info *inf, int a, int b, int c, int d, int cr);
float			destance(t_all_info *info, int x, int y);
int				draw_image_surface_mini(t_all_info *info);
int				draw_image_player_mini(t_all_info *info);
t_point			ray_casting_y_mini(t_all_info *info);
t_point			ray_casting_x_mini(t_all_info *info);
int				ray_casting_mini(t_all_info *info);
int				draw_image_view_angle_mini(t_all_info *info);
void			draw_line_mini(t_all_info *info, int x1, int y1, int color);
int				get_texteur_value(t_all_info *info, int	z, int type);
int				get_sprite_value(t_all_info *d, float z, int i, int t, float x);
int				rm_all(t_all_info *info);
float			value_angle_2_point (int a, int b, t_all_info *i, int c, int d);
float			destance_2_points(float x1, float y1, float x2, float y2);
t_eq_line		find_equation_of_line(float x1, float y1, float x2, float y2);
t_point			entersection_two_line(t_eq_line a, t_eq_line b, t_all_info *i);
float			normalisie_angle(float angle);
t_point			enter_line_circle(t_all_info *i, float x, float y,
float r, t_eq_line l);
int				get_data_from_maps(int	x, int	y, t_all_info *info);
int				draw_sprite(t_all_info *info);
t_sprite		*add_to_last (t_sprite *sprite, t_sprite *sprite_data);
int				sort_by_destance(t_all_info *info);
int				draw_sprite(t_all_info *info);
int				get_type_from_maps(float x, float y, t_all_info *info);
int				get_player_info(t_all_info *info);
int				get_sprite_from_file(t_all_info *info);
int				get_no_texteur_from_file(t_all_info *info);
int				get_so_texteur_from_file(t_all_info *info);
int				get_we_texteur_from_file(t_all_info *info);
int				get_ea_texteur_from_file(t_all_info *info);
void			set_error(int type_of_error);
int				get_color_flor(t_all_info *info);
int				get_color_coll(t_all_info *info);
int				check_the_maps(t_all_info *info);
int				get_max_h(char *maps);
int				get_max_w(char *maps);
int				check_file(char *file);
int				save(t_all_info *info);
char			*get_no_texteur_path(t_all_info *info);
char			*get_so_texteur_path(t_all_info *info);
char			*get_we_texteur_path(t_all_info *info);
char			*get_ea_texteur_path(t_all_info *info);
int				get_x_value(t_all_info *info, float img_size_w, float
img_size_h, int *data);
int				get_y_value(t_all_info *info, float img_size_w, float
img_size_h, int *data);
#endif
