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
	int		nb;
}				t_line;

typedef struct	s_map {
	t_line **lines;

}				t_map;

t_map			*ft_parse_map(char **av);
t_point			**ft_points(char *line, int nb_line);
void			ft_parse_points (char *nb_str);
int				ft_getnbr(char *str);
int				ft_map_line(char *map);
#endif
