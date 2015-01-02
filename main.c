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

	// t_point *p1;
	// t_point *p2;


	// map =
	if (argc == 2)
	{
		map = ft_parse_map(argv);

		ft_cal_rotation(map);
		ft_cal_translation_x(map);
		ft_cal_translation_y(map);
		// ft_cal_translation_z(map);

		ft_putnbr(map->len);
		draw_windows("42", 1000, 1000, &e);
		draw_map(*map, e, 0xFF0000);
	// map = (*t_map)malloc(sizeof(t_map));


	/*
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	// puts("in");
	// printf("%d %s", argc, argv[0]);
	draw(e.mlx, e.win);
	*/
	/*
	p1 = (t_point*)malloc(sizeof(t_point));
	p2 = (t_point*)malloc(sizeof(t_point));

	p1->x = 10 * SIZE_W;
	p1->y = 10 * SIZE_H;

	p2->x = 20 * SIZE_W;
	p2->y = 30 * SIZE_H;
	draw_line(*p1, *p2, e, 0xFF0000);
*/

		sleep(50);
	}

	return (0);
}
