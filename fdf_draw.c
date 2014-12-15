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

	y = 0;
	while (y < map.len)
	{
		x = 0;
		while (x < (map.lines[y]->len))
		{
			if (map.lines[y]->points[x]->z > 1)
				color = 0x00FF00;
			else
				color = 0xFF0000;
			// draw_point((*map.lines[y]->points[x]), e, color);
			if (map.lines[y]->points[x + 1])
				draw_line((*map.lines[y]->points[x]), (*map.lines[y]->points[x + 1]), e, color);
			if (map.lines[y + 1])
				draw_line((*map.lines[y]->points[x]), (*map.lines[y + 1]->points[x]), e, color);
			x++;
		}
		y++;
	}
}
/*
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
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (point1.x < point2.x)
						{
							draw
						}
					}
				}
			}
		}
	}
}*/

void draw_line(t_point point1, t_point point2, t_env env, int color)
{
	// ft_putnbr(point1.x);
	// puts(" x");
	// ft_putnbr(point1.y);
	// puts(" y");
	while (point1.x < point2.x)
	{
		draw_point(point1, env, color);
		point1.x++;
	}

	while (point1.y < point2.y)
	{
		draw_point(point1, env, color);
		point1.y++;
	}
}

void draw_point(t_point point, t_env e, int color)
{
	mlx_pixel_put(e.mlx, e.win, (point.x + DEC_L), (point.y + DEC_T), color);
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
