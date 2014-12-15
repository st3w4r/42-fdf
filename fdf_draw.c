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


void draw_windows(char *title, int weight, int height, t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, weight, height, title);
}

/*
void draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2, int color)
{
    int dx;
    int dy;
    int i;
    int e;

    int incx;
    int incy;
    int inc1;
    int inc2;
    int x;
    int y;

    dx = x2 - x1;
    dy = y2 - y1;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (x2 < x1)
        incx = -1;
    incy = 1;
    if (y2 < y1)
        incy = -1;
    x = x1;
    y = y1;

    if (dx > dy)
    {
        mlx_pixel_put(mlx, win, x, y, color);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        i = 0;
        while (i < dx)
        {
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            mlx_pixel_put(mlx, win, x, y, color);
            i++;
        }
    }
    else
    {
        mlx_pixel_put(mlx, win, x, y, color);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        i = 0;
        while (i < dy)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            mlx_pixel_put(mlx, win, x, y, color);
            i++;
        }
    }
}*/

void draw_map(t_map map, t_env e, int color)
{
	int x;
	int y;

	x = 0;
	while (x < map.len)
	{
		y = 0;
		while (y < map.lines[x]->len)
		{
			draw_point((*map.lines[x]->points[y]), e, color);
			// draw_line(e.mlx, e.win, map.lines[x]->points[y]->x, map.lines[x]->points[y]->y, map.lines[x +1]->points[y]->x, map.lines[x +1]->points[y]->y, color);
			y++;
		}
		x++;
	}
}

void draw_line(t_point point1, t_point point2, t_env env, int color)
{
	int dx;
	int dy;
	int e;
	// t_point new_point;
	// new_point = (t_point)malloc(sizeof(t_point))
							// new_point.x = point1.x;
							// new_point.y = point1.y;

	dx = point2.x - point1.y;
	if (dx != 0)
	{
		if (dx > 0)
		{
			dy = point2.y - point1.y
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (point1.x < point2.x)
						{
							draw_point(point1, env, color);
							e -= dy;
							if (e < 0)
							{
								point1.y++;
								e += dx;
							}
							point1.x++;
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx *= 2;
						while (point1.y < point2.y)
						{
							draw_point(point1, env, color);
							e -= dx;
							if (e < 0)
							{
								point1.x++;
								e += dy;
							}
							point1.y++;
						}
					}
				}
			}
		}
	}
}

void draw_point(t_point point, t_env e, int color)
{
	mlx_pixel_put(e.mlx, e.win, (point.x + DEC_L ) * POS_N, (point.y + DEC_T )* POS_N, color);
}

void draw(void *mlx, void *win)
{
	int x;
	int y;

	x = 50;
	while (x < 200)
	{
		y = 50;
		while (y < 200)
		{
			mlx_pixel_put(mlx, win, y, x, 0xFF0000);
			// usleep(500);
			y++;
		}
		x++;
	}
}
