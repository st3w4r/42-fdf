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

void		draw_map(t_env *e)
{
	int			x;
	int			y;
	t_point		p1;

	y = 0;
	while (y < e->map->len)
	{
		x = 0;
		while (x < (e->map->lines[y]->len))
		{
			p1 = (*e->map->lines[y]->points[x]);
			if (e->map->lines[y]->points[x + 1])
				draw_line(p1, (*e->map->lines[y]->points[x + 1]), e);
			if (e->map->lines[y + 1])
				if (e->map->lines[y + 1]->points[x] &&
					x <= e->map->lines[y + 1]->len)
					draw_line(p1, (*e->map->lines[y + 1]->points[x]), e);
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

static void	draw_point(t_point point, t_env *e, int color)
{
	int i;

	i = ((int)point.x * 4) + ((int)point.y * e->s_line);
	e->pixel_img[i] = color;
	e->pixel_img[++i] = color >> 8;
	e->pixel_img[++i] = color >> 16;
}

void		draw_line(t_point p1, t_point p2, t_env *e)
{
	double	tab[6];
	int		state;

	if (point_in_window(p1, p2) == 0)
		return ;
	draw_line_params(&p1, &p2, tab);
	state = 1;
	while (state == 1 && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
	{
		draw_point(p1, e, get_color(&p1, &p2));
		tab[5] = tab[4];
		state = 0;
		if (tab[5] > -tab[0] && (int)p1.x != (int)p2.x)
		{
			tab[4] -= tab[2];
			p1.x += tab[1];
			state = 1;
		}
		if (tab[5] < tab[2] && (int)p1.y != (int)p2.y)
		{
			tab[4] += tab[0];
			p1.y += tab[3];
			state = 1;
		}
	}
}
