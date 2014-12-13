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

int		main(int argc, char **argv)
{
	// void *mlx;
	// void *win;
	t_env e;
	t_map *map;

	// map =
	if (argc == 2)
		map = ft_parse_map(argv);

	ft_putnbr(map->len);
	draw_windows("42", 600, 600, &e);
	draw_point((*map->lines[5]->points[8]), e, 0xFF0000);
	draw_point((*map->lines[6]->points[8]), e, 0xFF0000);
	draw_point((*map->lines[5]->points[9]), e, 0xFF0000);
	draw_point((*map->lines[6]->points[9]), e, 0xFF0000);
	// map = (*t_map)malloc(sizeof(t_map));


	/*
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	// puts("in");
	// printf("%d %s", argc, argv[0]);
	draw(e.mlx, e.win);
	*/
	sleep(5);


	return (0);
}
