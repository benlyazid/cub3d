/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:42:04 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/11/05 14:07:09 by kbenlyaz         ###   ########.fr       */
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
# define DEST_2P(X1, Y1, X2, Y2) sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
# define R_P ( M_PI / 180)

typedef struct	s_desst_to_wall
{
	float	destance;
	int		type;
	float	x_wall;
	float	y_wall;

}				t_d_wall;

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

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
	float			x_center;
	float			y_center;
	float			dest;
	struct s_sprite	*next;

}				t_sprite;

typedef	struct	s_all_info
{
	int			moins;
	float		x;
	float		y;
	float		xa;
	float		ya;
	int			end;
	int			start;
	t_d_wall	wall_dest;
	int			uc;
	int			bitcount;
	int			w_bt;
	int			bisize;
	int			imagesize;
	int			bfoffbits;
	int			biplanes;
	int			filesize;
	char		*header;
	char		*buf;
	float		txt_w;
	float		txt_h;
	int			*txt_img_data;
	t_color		clr_c;
	t_color		clr_f;
	char		*maps;
	char		*file;
	int			*mp;
	float		width;
	float		height;
	float		width_size;
	float		height_size;
	float		width_number;
	float		height_number;
	void		*mlx_ptr;
	void		*win_ptr;
	float		xp;
	float		yp;
	float		angle;
	void		*img_3d;
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
	float		sprt_h;
	float		sprt_w;
	int			sprite;
	float		prjct_sprit;
	float		save_angle;
	float		projection_wall;
	t_sprite	*sprt_strct_all;
	t_sprite	*sprite_struct_start;
	float		size;
	float		rayon;
	float		dst_player_projection;
}				t_all_info;

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
char			*read_file(int fd);
void			get_all_info(char *arg, t_all_info *info);
int				draw_2d_maps(t_all_info *info);
int				move_player(t_all_info *info);
int				effect_move(int key, t_all_info *info);
int				check_abilitie_to_move(t_all_info *info, int key);
int				*get_mp(t_all_info *info);
int				effect_key_for_move(t_all_info *info, int key, int multiple);
t_d_wall		calc_destance_to_wall(t_all_info *info);
int				draw_3d_image(t_all_info *info, float x, float alpha);
int				draw_all_image_3d(t_all_info *info);
float			ray_casting(t_all_info *info);
t_point			ray_casting_x(t_all_info *info);
t_point			ray_casting_y(t_all_info *info);
float			destance(t_all_info *info, int x, int y);
int				get_texteur_value(t_all_info *info, int type);
float			get_sprite_value(t_all_info *info);
t_sprite		*add_to_last (t_sprite *sprite, t_sprite *sprite_data);
int				sort_by_destance(t_all_info *info);
int				get_type_from_maps(float x, float y, t_all_info *info);
int				get_player_info(t_all_info *info);
int				get_sprite_from_file(t_all_info *info);
int				get_no_texteur_from_file(t_all_info *info);
int				get_so_texteur_from_file(t_all_info *info);
int				get_we_texteur_from_file(t_all_info *info);
int				get_ea_texteur_from_file(t_all_info *info);
void			set_error(int type_of_error, t_all_info *info);
int				get_clr_f(t_all_info *info);
int				get_clr_c(t_all_info *info);
int				check_the_maps(t_all_info *info);
int				get_max_h(char *maps);
int				get_max_w(char *maps);
int				check_file(char *file);
int				save(t_all_info *info);
char			*get_no_texteur_path(t_all_info *info);
char			*get_so_texteur_path(t_all_info *info);
char			*get_we_texteur_path(t_all_info *info);
char			*get_ea_texteur_path(t_all_info *info);
int				get_number(char *str);
int				get_height(char	*str);
int				get_width(char *file);
int				is_player(char c);
int				check_border(char *maps, t_all_info *info);
int				not_supported(char c);
char			*repiare_the_maps(char *maps);
int				draw_flor_sol(t_all_info *info);
void			insert_sprite_to_x(t_all_info *info, int m, float x, float y);
void			initial_x_ray(t_all_info *info);
void			add_sprit_to_x(t_all_info *info, int moins, float x, float y);
int				check_file_ext(char *str);
char			*join(char *s1, char *s2);
int				check_line_spaces(char *maps);
int				check_for_unsuported_element(char *file);
int				check_error(t_all_info *info, char *argv[]);
int				check_error2(t_all_info *info, char *argv[]);
int				check_save(t_all_info *info, char *argv[], int argc);
int				save_in_file(t_all_info *info);
int				save_bmp(t_all_info *info);
int				check_xpm_ext(char *path);
#endif
