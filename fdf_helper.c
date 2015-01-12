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

int		get_color(t_point *point1, t_point *point2)
{
	int color;
	int z;

	if (point2->z_color > point1->z_color)
		z = point2->z_color;
	else
		z = point1->z_color;
	if (z < 0)
		color = 0x0D6386;
	else if (z >= 0 && z < 10)
		color = 0x32A862;
	else if (z >= 10 && z < 20)
		color = 0x8FC89A;
	else if (z >= 20 && z < 50)
		color = 0xFAECBE;
	else if (z >= 50 && z < 70)
		color = 0x996E56;
	else if (z >= 70)
		color = 0xE0D3CC;
	else
		color = 0;
	return (color);
}

void	get_center(t_env *e)
{
	t_point	p;
	int		yl;
	int		xl;

	p = e->center;
	yl = e->map->len;
	xl = e->map->lines[yl - 1]->len;
	p.x = (e->map->lines[yl - 1]->points[xl - 1]->x +
			e->map->lines[0]->points[0]->x) / 2;
	p.y = (e->map->lines[yl - 1]->points[xl - 1]->y +
			e->map->lines[0]->points[0]->y) / 2;
	e->center = p;
}

void	draw_reload(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WINDOW_SIZE_W + 100, WINDOW_SIZE_H + 100);
	e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, -50, -50);
	mlx_destroy_image(e->mlx, e->img);
}

void	adapt_map(t_env *e)
{
	int		w;
	int		h;
	double	s;

	w = (WINDOW_SIZE_W + 100) / 2;
	h = (WINDOW_SIZE_H + 100) / 2;
	s = (w - 600) / (e->center.x);
	ft_cal_translat(e, -e->center.x + w, -e->center.y + h, 0);
	ft_cal_scale(e, s);
}

int		point_out_window(t_point point1)
{
	if (!(point1.x > WINDOW_SIZE_W + 100 || point1.x <= 0 ||
		point1.y > WINDOW_SIZE_H + 100 || point1.y <= 0))
		return (1);
	else
		return (0);
}
