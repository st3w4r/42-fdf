/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:49:08 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/03 19:49:36 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int z)
{
	int array_color[5];

	array_color[0] = 0x0000FF;
	array_color[1] = 0xFFFF00;
	array_color[2] = 0x00FF00;
	array_color[3] = 0x7F5B13;
	array_color[4] = 0xFFFFFF;
	if (z < 0)
		return (array_color[0]);
	else if (z >= 0 && z < 10)
		return (array_color[1]);
	else if (z >= 10 && z < 20)
		return (array_color[2]);
	else if (z >= 20 && z < 30)
		return (array_color[3]);
	else if (z >= 30)
		return (array_color[4]);
	else
		return (0);
}

void	get_center(t_param *param, t_map *m)
{
	t_point	p;
	int		yl;
	int		xl;

	p = param->center;
	yl = m->len;
	xl = m->lines[0]->len;
	p.x = (m->lines[yl - 1]->points[xl - 1]->x + m->lines[0]->points[0]->x) / 2;
	p.y = (m->lines[yl - 1]->points[xl - 1]->y + m->lines[0]->points[0]->y) / 2;
	param->center = p;
}

void	draw_reload(t_map map, t_env e)
{
	mlx_clear_window(e.mlx, e.win);
	draw_map(map, e);
}
