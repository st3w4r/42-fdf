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

// # include "get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "libft/includes/libft.h"
// # define POS_N 0
# define DEC_T 0
# define DEC_L 0
# define SIZE_W 20
# define SIZE_H 20

# define MOVE_UP -10
# define MOVE_DOWN 10
# define MOVE_LEFT -10
# define MOVE_RIGHT 10

# define MOVE_ZOOM_IN 1.1
# define MOVE_ZOOM_OUT 0.9

# define MOVE_ROT_X_U -0.1
# define MOVE_ROT_X_D 0.1
# define MOVE_ROT_Y_U -0.1
# define MOVE_ROT_Y_D 0.1
# define MOVE_ROT_Z_U -0.1
# define MOVE_ROT_Z_D 0.1


/**
*	Key code
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

typedef struct	s_env {
	void *mlx;
	void *win;
}				t_env;

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
	t_line **lines;
	int		len;
}				t_map;

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

typedef struct	s_param {
	t_map *map;
	t_env *e;
	t_point center;
}				t_param;

/**
*	Parse Map
*	\file parse_arg.c
*/
t_map			*ft_parse_map(char **av);
int				ft_points(char *line, int nb_line, t_point ***array_points);
void			ft_parse_points (char *nb_str);
int				ft_getnbr(char *str);
int				ft_map_line(char *map);

/**
*	Draw Map
*	\file fdf_draw.c
*/
void			draw(void *mlx, void *win);
void			draw_map(t_map map, t_env e);
void			draw_windows(char *title, int weight, int height, t_env *e);
void			draw_point(t_point point, t_env e, int color);
void			draw_line(t_point point1, t_point point2, t_env env, int color);
void			draw_reload(t_map map, t_env e);
/**
*	Gestion Error
*	\file fdf_error.c
*/
void			ft_exit();

/**
*	Calcul of matrice
*	\file fdf_cal_matrice.c
*/
void		ft_cal_matrice(t_point *p, t_matrice *m, t_param *param);
void		ft_cal_rotation_x(t_param *param, double rot);
void		ft_cal_rotation_y(t_param *param, double rot);
void		ft_cal_rotation_z(t_param *param, double rot);
void		ft_cal_translation(t_param *param, double x, double y, double z);
void		ft_cal_scale(t_param *param, double s);
void		ft_cal_matrice_all_points(t_map *map, t_matrice *m, t_param *param);

/*
void		ft_cal_translation_x(t_map *map);
void		ft_cal_translation_y(t_map *map);
void		ft_cal_translation_z(t_map *map);
*/
// void		ft_cal_matrice(t_point *p, t_matrice *m, t_param *param);

/**
*	Mtarice init
*	\file fdf_matrice.c
*/
t_matrice	*ft_matrice_rotation_x(double beta);
t_matrice	*ft_matrice_rotation_y(double beta);
t_matrice	*ft_matrice_rotation_z(double beta);
t_matrice	*ft_matrice_translation(double tx, double ty, double tz);
t_matrice	*ft_matrice_scale(double s);
// t_matrice	*ft_matrice_translation_x(double tran);
// t_matrice	*ft_matrice_translation_y(double tran);
// t_matrice	*ft_matrice_translation_z(double tran);

/**
*	Hook
*	\file fdf_hook.c
*/
int			key_hook(int keycode, t_param *param);

/**
*	Function Helpers
*	\file fdf_helper.c
*/
int			get_color(int z);
void		get_center(t_param *param, t_map *m);

#endif
