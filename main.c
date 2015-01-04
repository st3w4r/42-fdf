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

int		expose_hook(t_param *param)
{
	draw_map(*(param->map), *(param->e));
	return (0);
}

int		main(int argc, char **argv)
{
	// void *mlx;
	// void *win;
	t_param *param;
	t_env e;
	t_map *map;

	// t_point *p1;
	// t_point *p2;


	// map =
	if (argc == 2)
	{
		map = ft_parse_map(argv);

		// ft_cal_rotation(map, 0.5);
		// ft_cal_translation_x(map);
		// ft_cal_translation_y(map);

		// draw_map(*map, e, 0xFF0000);
		// mlx_key_hook(e.win, key_hook, &e);
		if (!(param = (t_param *)malloc(sizeof(t_param))))
			ft_exit();
		get_center(param, map);
		param->map = map;
		param->e = &e;
		draw_windows("42", 1000, 1000, param->e);
		mlx_expose_hook(e.win, expose_hook, param);
		mlx_hook(e.win, 2, 3, key_hook, param);
		mlx_loop(e.mlx);
		free(param);
		// mlx_do_key_autorepeaton(e.mlx);
		// int	mlx_hook(void *win_ptr, int x_event, int x_mask,
		//  int (*funct)(), void *param);
		// ft_cal_translation_z(map);

		// ft_putnbr(map->len);
		// draw_windows("42", 1000, 1000, &e);
		// draw_map(*map, e, 0xFF0000);
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

	}

	return (0);
}
