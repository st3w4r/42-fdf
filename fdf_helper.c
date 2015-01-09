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

void	get_center(t_env *e)
{
	t_point	p;
	int		yl;
	int		xl;

	p = e->center;
	yl = e->map->len;
	xl = e->map->lines[0]->len;
	p.x = (e->map->lines[yl - 1]->points[xl - 1]->x +
			e->map->lines[0]->points[0]->x) / 2;
	p.y = (e->map->lines[yl - 1]->points[xl - 1]->y +
			e->map->lines[0]->points[0]->y) / 2;
	e->center = p;
}

/*
static void	put_pixel_to_image(t_env *e, int x, int y, int color)
{
	int i;

	i = x + (y * e->s_line);
	e->pixel_img[i] = color;
	e->pixel_img[++i] = color >> 8;
	e->pixel_img[++i] = color >> 16;
}
*/
void	draw_reload(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->img = mlx_new_image(e->mlx, WINDOW_SIZE_H, WINDOW_SIZE_W);
	e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}
