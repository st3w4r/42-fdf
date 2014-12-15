/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:00:21 by ybarbier          #+#    #+#             */
/*   Updated: 2014/12/09 15:00:24 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define POS_N 20
# define DEC_T 1
# define DEC_L 1

typedef struct	s_env {
	void *mlx;
	void *win;
}				t_env;

typedef struct	s_point {
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct	s_line {
	t_point	**points;
	int		len;
}				t_line;

typedef struct	s_map {
	t_line **lines;
	int		len;
}				t_map;

t_map			*ft_parse_map(char **av);
int				ft_points(char *line, int nb_line, t_point ***array_points);
void			ft_parse_points (char *nb_str);
int				ft_getnbr(char *str);
int				ft_map_line(char *map);

void			draw(void *mlx, void *win);
void			draw_map(t_map map, t_env e, int color);
void			draw_windows(char *title, int weight, int height, t_env *e);
void			draw_point(t_point point, t_env e, int color);
void			draw_line(t_point point1, t_point point2, t_env e, int color);
#endif
