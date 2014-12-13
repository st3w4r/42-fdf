/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:51:09 by ybarbier          #+#    #+#             */
/*   Updated: 2014/12/09 15:00:59 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw (void *mlx, void *win)
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

int		main(int argc, char **argv)
{
	// void *mlx;
	// void *win;
	//t_env e;
	// t_map *map;

	// map =
	if (argc == 2)
		ft_parse_map(argv);
	// map = (*t_map)malloc(sizeof(t_map));


	/*
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	// puts("in");
	// printf("%d %s", argc, argv[0]);
	draw(e.mlx, e.win);
	sleep(5);
	*/


	return (0);
}
