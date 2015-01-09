/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:00:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/04 00:06:29 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "libft/includes/libft.h"

# define DEC_T 100
# define DEC_L 100
# define SIZE_W 20
# define SIZE_H 20

# define WINDOW_SIZE_H 1000
# define WINDOW_SIZE_W 1000

/*
**	Move pixel
*/
# define MOVE_UP -100
# define MOVE_DOWN 100
# define MOVE_LEFT -100
# define MOVE_RIGHT 100

# define MOVE_ZOOM_IN 1.1
# define MOVE_ZOOM_OUT 0.9

# define MOVE_ROT_X_U -0.1
# define MOVE_ROT_X_D 0.1
# define MOVE_ROT_Y_U -0.1
# define MOVE_ROT_Y_D 0.1
# define MOVE_ROT_Z_U -0.1
# define MOVE_ROT_Z_D 0.1

/*
**	Key code
*/
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ZOOM_IN 65451
# define KEY_ZOOM_OUT 65453

# define KEY_ROT_X_U 65460
# define KEY_ROT_X_D 65457
# define KEY_ROT_Y_U 65461
# define KEY_ROT_Y_D 65458
# define KEY_ROT_Z_U 65462
# define KEY_ROT_Z_D 65459

typedef struct	s_point {
	double	x;
	double	y;
	double	z;
	double	s;
	int		color;
}				t_point;

typedef struct	s_line {
	t_point	**points;
	int		len;
}				t_line;

typedef struct	s_map {
	t_line	**lines;
	int		len;
}				t_map;

typedef struct	s_env {
	void	*mlx;
	void	*win;
	t_map	*map;
	t_point	center;
	void	*img;
	char	*pixel_img;
	int		bpp;
	int		s_line;
	int		ed;
}				t_env;

typedef struct	s_matrice {
	double a1;
	double a2;
	double a3;
	double a4;
	double b1;
	double b2;
	double b3;
	double b4;
	double c1;
	double c2;
	double c3;
	double c4;
	double d1;
	double d2;
	double d3;
	double d4;
}				t_matrice;

/*
**	Parse Map
**	\file parse_arg.c
*/
t_map			*ft_parse_map(char **av, int fd);
int				ft_points(char *line, int nb_line, t_point ***array_points);
void			ft_parse_points (char *nb_str);
int				ft_getnbr(char *str);
int				ft_map_line(char *map);

/*
**	Draw Map
**	\file fdf_draw.c
*/
void			draw_windows(char *title, int weight, int height, t_env *e);
void			draw_map(t_env *e);
void			draw_line(t_point p1, t_point p2, t_env *e, int color);

/*
**	Gestion Error
**	\file fdf_error.c
*/
void			ft_exit(void);

/*
**	Calcul of matrice
**	\file fdf_cal_matrice.c
*/

void			ft_cal_rotation(t_env *e, double rot, char axe);
void			ft_cal_translat(t_env *e, double x, double y, double z);
void			ft_cal_scale(t_env *e, double s);

/*
**	Mtarice init
**	\file fdf_matrice.c
*/
t_matrice		*ft_matrice_rotation_x(double beta);
t_matrice		*ft_matrice_rotation_y(double beta);
t_matrice		*ft_matrice_rotation_z(double beta);
t_matrice		*ft_matrice_translation(double tx, double ty, double tz);
t_matrice		*ft_matrice_scale(double s);

/*
**	Hook
**	\file fdf_hook.c
*/
int				key_hook(int keycode, t_env *e);

/*
**	Function Helpers
**	\file fdf_helper.c
*/
int				get_color(int z);
void			get_center(t_env *e);
void			draw_reload(t_env *e);
int				point_in_window(t_point point1, t_point point2);
void			adapt_map(t_env *e);

#endif
