/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:15:11 by ybarbier          #+#    #+#             */
/*   Updated: 2014/12/13 15:15:13 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_windows(char *title, int weight, int height, t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, weight, height, title);
}

void		draw_map(t_map map, t_env e)
{
	int			x;
	int			y;
	t_point		p1;
	int			p_color;

	y = 0;
	while (y < map.len)
	{
		x = 0;
		while (x < (map.lines[y]->len))
		{
			p1 = (*map.lines[y]->points[x]);
			p_color = map.lines[y]->points[x]->color;
			if (map.lines[y]->points[x + 1])
				draw_line(p1, (*map.lines[y]->points[x + 1]), e, p_color);
			if (map.lines[y + 1])
				draw_line(p1, (*map.lines[y + 1]->points[x]), e, p_color);
			x++;
		}
		y++;
	}
}

static void	draw_line_params(t_point *point1, t_point *point2, double *tab)
{
	tab[0] = fabs(point1->x - point2->x);
	tab[1] = point1->x < point2->x ? 1 : -1;
	tab[2] = fabs(point1->y - point2->y);
	tab[3] = point1->y < point2->y ? 1 : -1;
	tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]) * 0.5;
}

static void	draw_point(t_point point, t_env e, int color)
{
	mlx_pixel_put(e.mlx, e.win, point.x, point.y, color);
}

void		draw_line(t_point point1, t_point point2, t_env env, int color)
{
	double	tab[6];
	int		state;

	draw_line_params(&point1, &point2, tab);
	state = 1;
	while (state == 1 &&
		!((int)point1.x == (int)point2.x && (int)point1.y == (int)point2.y))
	{
		draw_point(point1, env, color);
		tab[5] = tab[4];
		state = 0;
		if (tab[5] > -tab[0] && (int)point1.x != (int)point2.x)
		{
			tab[4] -= tab[2];
			point1.x += tab[1];
			state = 1;
		}
		if (tab[5] < tab[2] && (int)point1.y != (int)point2.y)
		{
			tab[4] += tab[0];
			point1.y += tab[3];
			state = 1;
		}
	}
}
