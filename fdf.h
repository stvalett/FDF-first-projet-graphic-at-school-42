/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:03:44 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/20 09:31:16 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define LENGTH     2048
# define HEIGTH  	1152
# define HEIGTH_Z 	5
# define ANGLE      0.6
# define ROT_X      0
# define ROT_XX     2
# define ROT_Y      13
# define ROT_YY     1
# define T_EXIT		53
# define T_RIGHT	123
# define T_LEFT		124
# define T_UP	    126
# define T_DOWN		125
# define T_M		78
# define T_P		69
# define T_H1		67
# define T_H2		75
# define SCALE_W 	32
# define SCALE_H 	32

typedef struct			s_coord
{
	int					x;
	int					y;
	int					z;
}						t_coord;

typedef struct			s_rot
{
	float				x_i;
	float				x_f;
	float				y_i;
	float				y_f;
	float				z_i;
	float				z_f;
}						t_rot;

typedef struct			s_bress
{
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	int					error;
}						t_bress;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img_ptr;
	char				*data;
	int					bpp;
	int					sizeline;
	int					endian;
	float				heigth_z;
	int					x_length;
	int					y_heigth;
	int					colors;
	int					**map;
	int					scale_h;
	int					scale_w;
	int					m_x;
	int					m_y;
	float				angle;
	int					rot;
	t_coord				coord;
}						t_env;

typedef struct			s_list_line
{
	struct s_list_line	*next;
	size_t				*content_size;
	void				*data;
}						t_list_line;

int						ft_lstcount(t_list_line *list);
int						ft_rgb(int r, int g, int b);
int						ft_check_file(char *av);
int						ft_check_number(char *line);
int						ft_mlx(int **tab, int length, int width);
int						**ft_get_tab(int fd, int *length, int *width);
void					ft_get_map(t_env *env);
void					ft_draw(t_env *env, t_coord *p1, t_coord *p2);
void					ft_put_pixel(t_env *env, int x, int y);
void					ft_move(int keycode, t_env *e);
void					ft_zoom(int keycode, t_env *e);
void					ft_key_rot_x(int key, t_env *e);
void					ft_key_rot_y(int key, t_env *e);
void					ft_rot_x(t_rot *rot);
void					ft_rot_y(t_rot *rot);
int						ft_error(int ac);
int						ft_error2(char **av);

#endif
